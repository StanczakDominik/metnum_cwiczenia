#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
using namespace std;

double a = 0.;
//double b=1.;
//double analytical = double(1)/double(3);
//double analytical=(b-a)*(b-a)/2.;
double b = 2.*M_PI;
double analytical = -b;

double f(double x)
{
	//return x*x;
	return x*sin(x);

}

double integrate_trapezoidal(double a, double b, double h)  //TRAPEZY SA BE
{
    double sum = (f(a)+f(b))/2.;
    for(double x=a+h/2.; x<b; x+=h)
    {
        sum += f(x);
    }
    return sum*h;
}

double integrate_rectangular(double a, double b, double h)
{
    double sum = 0.0;
    for(double x=a; x<b; x+=h)
    {
        sum += f(x+h/2.);
    }
    return sum*h;
}
double integrate_rectangular_correction(double a, double b, double h)
{
    double result = 0.0;
    double x = a;
    double xs = 0.0;
    while(x<b)
    {
        double dh = h;
        if (x+h <b)
            xs = (x+x+h) / 2.0;
        else
            xs = (x+b) / 2.0;
            dh = b-x;
        result += f(xs)*dh;
        x += dh;
    }
    return result;
}
double integrate_simpson(double a, double b, double h)
{
    double sum = 0.0;
    for(double x=a; x<b; x+=h)
    {
        sum += f(x)+4*f(x+h/2.)+f(x+h);
    }
    return sum*h/6.;
}

double integrate_boole(double a, double b, double h)
{
    double sum = 0.0;
    for(double x=a; x<b; x+=h)
    {
        sum += 7*f(x)+32*f(x+h/4)+12*f(x+h/2)+32*f(x+3/4.*h)+7*f(x+h);
    }
    return sum*h/90.;
}

double random_interval(double a, double b)
{
	return a + (b-a)*(double)rand()/static_cast<double>(RAND_MAX);
}
double integrate_monte_carlo(double a, double b, double N, double min_func, double max_func)
{
	//cout << b-a << " " << max_func-min_func << endl;
	double result = (b-a)*(max_func-min_func);
	int counter = 0;

	for(int i=0; i<N; ++i)
	{
		double x = random_interval(a,b);
		double y = random_interval(min_func,max_func);

		double fx = f(x);
		if ((fx > 0) && (fx > y) && (y>0))
		{
			counter++;
		}
		else if ((fx < 0) && (y<0) && (fx < y))
		{
			counter--;
		}
	}
	result *= double(counter)/double(N);
	return result;
}

// wersja oficjalna
double integrate_monte_carlo2(double x0, double x1, double n, double y0, double y1)
{
    int hits=0;
    for(int i=0; i<n; ++i)
    {
        double x = random_interval(x0, x1);
        double y = random_interval(y0, y1);
        double z = f(x);
        if (z>0 && y > 0 && y < z) hits++;
        else if (z<0 && y < 0 && y > z) hits--;
    }
    return (double)hits / (double)n * (x1-x0) * (y1-y0);
}

int main()
{   
	srand(time(NULL));
	cout << setiosflags(ios::fixed) << setprecision(12) << endl;
	cout << "n\th\t\trect\t\ttrap\t\tsimp\t\tbool\t\tmc"<<endl;
    for (int i=1; i<8; i++)
    {
        int n = pow(10,i);
        double h = (b-a)/double(n);
		double monte_carlo_integration = integrate_monte_carlo(a,b,n,-5,2);
	    cout << n << "\t" << h << "\t" << integrate_rectangular(a,b,h) <<  "\t" << integrate_trapezoidal(a,b,h) << "\t" << integrate_simpson(a,b,h) << "\t" << integrate_boole(a,b,h) << "\t" << monte_carlo_integration <<  endl;
	    cout << n << "\t" << h << "\t" << integrate_rectangular(a,b,h)-analytical << "\t" << integrate_trapezoidal(a,b,h)-analytical << "\t" << integrate_simpson(a,b,h)-analytical << "\t" << integrate_boole(a,b,h)-analytical << "\t" << monte_carlo_integration - analytical << endl;
	    cout << n << "\t" << h << "\t" << (integrate_rectangular(a,b,h)-analytical)/analytical << "\t" << (integrate_trapezoidal(a,b,h)-analytical)/analytical << "\t" << (integrate_simpson(a,b,h)-analytical)/analytical << "\t" << (integrate_boole(a,b,h)-analytical)/analytical << "\t" << (monte_carlo_integration - analytical)/analytical << endl;
		cout << endl;
	}
}
