#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
using namespace std;

double a = 0.;
double b=1.;
double analytical = double(1)/double(3);
//double analytical=(b-a)*(b-a)/2.;
//double b = 2.*M_PI;
//double analytical = -b;

double f(double x)
{
	return exp(-0.5*x*x)/sqrt(2.*M_PI);

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
	int really_large_int = 1000000000;
	return a + (rand() % really_large_int)/double(really_large_int) *(b-a);
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
		if (fx > y && fx > 0)
		{
			counter++;
		}
		else if (fx < y && fx < 0)
		{
			counter--;
		}
	}
	result *= double(counter/N);
	return result;
}

double gaussian_distribuant(double a, double x, double h)
{
	return integrate_boole(a,x,h);
}

int main(int argc, char** argv)
{   
	cout << setiosflags(ios::fixed) << setprecision(12) << endl;
	double a=-100;
	if(argc < 2)
	{
		cout << "Podaj z" << endl;
		exit(1);
	}
	double z = atof(argv[1]);
	if(z<a)
	{
		cout << "Zbyt maly z. Wyjdzie 0" << endl;
		exit(1);
	}
	cout << gaussian_distribuant(a,z,0.01) << endl;
}
