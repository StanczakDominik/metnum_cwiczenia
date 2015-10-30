#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double a = 0.;
//double b=1.;
//double analytical=(b-a)*(b-a)/2.;
double b = 2.*M_PI;
double analytical = -b;

double f(double x)
{
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

int main()
{   cout << setiosflags(ios::fixed) << setprecision(12) << endl;
    for (int i=0; i<8; i++)
    {
        int n = pow(10,i);
        double h = (b-a)/double(n);
	    cout << h << "\t" << integrate_rectangular(a,b,h) << "\t" << integrate_trapezoidal(a,b,h) << "\t" << integrate_simpson(a,b,h) << "\t" << integrate_boole(a,b,h) << "\t" << integrate_rectangular_correction(a,b,h) << endl;
	}
}
