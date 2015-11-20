#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double epsilon = pow(10,-12);

double mimosrod_ziemia = 0.0167;
double mimosrod_merkury = 0.2056;



double f(double x)
{
	return x*x*x*x-5.;
}
double fprime(double x)
{
    return 2.0*x;
}
double bisection(double a, double b)
{
    unsigned i = 0;
    double fa = f(a);
    double fb = f(b);
    bool a_sign = signbit(f(a));
    bool b_sign = signbit(f(b));
    if(a_sign==b_sign)
	{
	    cout << fa << "\t" << fb << endl;
	    cout << "Zle warunki poczatkowe" << endl;
	    return 0;
	}
	while(true)
	{
	    i++;
	    double x = (a+b)/2.0;
	    double fx = f(x);
	    cout << i << "\t" << x << "\t" << fabs(fx) << endl;
	    bool x_sign=signbit(fx);
	    if (fabs(fx)<epsilon)
	    {
	        cout << "Iteracje: " << i << endl;
	        return x;
	    }

	    if(a_sign != x_sign)
	    {
	       // a = a;
	        b = x;
	    }
	    else if (a_sign == x_sign)
	    {
	        a = x;
	        //b = b;
	    }
	}
}

double falsi(double a, double b)
{
    unsigned i = 0;
    double fa = f(a);
    double fb = f(b);
    bool a_sign = signbit(f(a));
    bool b_sign = signbit(f(b));
    if(a_sign==b_sign)
	{
	    cout << fa << "\t" << fb << endl;
	    cout << "Zle warunki poczatkowe" << endl;
	    return 0;
	}
	while(true)
	{
        double fa = f(a);
        double fb = f(b);
        bool a_sign = signbit(f(a));
	    i++;
	    double x = b-fb*(b-a)/(fb-fa);
	    double fx = f(x);
	    cout << i << "\t" << x << "\t" << fabs(fx) << endl;
	    bool x_sign=signbit(fx);
	    if(i>100000)
	    {
	        cout << "Chyba nie zbiega." << endl;
	        return 0    ;
	    }
	    if (fabs(fx)<epsilon)
	    {
	        cout << "Iteracje: " << i << endl;
	        return x;
	    }

	    if(a_sign != x_sign)
	    {
	       // a = a;
	        b = x;
	    }
	    else if (a_sign == x_sign)
	    {
	        a = x;
	        //b = b;
	    }
	}
}

double newton(double x)
{
    unsigned i = 0;
	while(true)
	{
	    i++;
	    double fx = f(x);
	    double fp = fprime(x);
	    cout << i << "\t" << x << "\t" << fabs(fx) << endl;
	    if (fabs(fx)<epsilon)
	    {
	        cout << "Iteracje: " << i << endl;
	        return x;
	    }
	    x -= fx/fp;
	    if(i>100000)
	    {
	        cout << "Chyba nie zbiega." << endl;
	        return 0    ;
	    }
	}
}

double tangents(double x, double xprev)
{
    unsigned i = 0;
	while(true)
	{
	    i++;
	    double fx = f(x);
	    double fp = f(xprev);
	    cout << i << "\t" << x << "\t" << fabs(fx) << endl;
	    if (fabs(fx)<epsilon)
	    {
	        cout << "Iteracje: " << i << endl;
	        return x;
	    }
	    x -= fx*(x-xprev)/(fx-fp);
	    if(i>100000)
	    {
	        cout << "Chyba nie zbiega." << endl;
	        return 0    ;
	    }
	}
}


double brent(double a, double b)
{
    unsigned i = 0;
    double fa = f(a);
    double fb = f(b);
    double s;
    double fs;
    double d;
    bool a_sign = signbit(f(a));
    bool b_sign = signbit(f(b));
    if(a_sign==b_sign)
	{
	    cout << fa << "\t" << fb << endl;
	    cout << "Zle warunki poczatkowe" << endl;
	    return 0;
	}
	if (abs(fa) < abs(fb))
	{
	    double swap_b = b;
	    b = a;
	    a = swap_b;
	}
    double c = a;
    
    bool mflag = true;
	do
	{
	    i++;
	    fa = f(a);
	    fb = f(b);
	    double fc = f(c);
	    if ((abs(fa-fc)>epsilon) and (abs(fb-fc) > epsilon))
	    {
	        cout << "inverse quadratic" << endl;
	        double s = a*fb*fc/((fa-fb)*(fa-fc)) + b*fa*fc/((fb-fa)*(fb-fc))+c*fa*fb/((fc-fa)*(fc-fb));
	    }
	    else
	    {
	        cout << "bisekcja" << endl;
	        double s = b - fb*(b-a)/(fb-fa);
	    }
	    cout << s << endl;
	    
	    if (
	        (not ( (s > (3.*a+b)/4.) and (s < b) ))
	        or (mflag and (abs(s-b) >= abs(b-c)/2.))
	        or ((not mflag) and abs(s-b) >= abs(c-d)/2.0)
	        or (mflag and (abs(b-c) < epsilon))
	        or ((not mflag) and (abs(c-d)<epsilon))
	        )
	    {
	        double s = (a+b)/2.0;
	        mflag = true;
	    }
	    else mflag = false;
	    
	    double fs = f(s);
	    double d = c;
	    c = b;
	    if (fa*fs < 0) b = s;
	    else a = s;
	    if (abs(fa) < abs(fb))
	    {
	        double swap_b = b;
	        b = a;
	        a = swap_b;
	    }
	    cout << i << "\t" << s << "\t" << fabs(fs) << endl;
	    cout << a << "\t" << b << "\t" << fa << "\t" << fb << endl;
	}
	while((abs(fb)>epsilon) and (abs(fs)>epsilon) and (abs(b-a)>epsilon));
	return b;
}
    
int main()
{   
    double a = 0.0;
    double b = 10.0;
    //cout << "Bisekcja" << endl;
    //cout << bisection(a,b) << endl;
    //cout << "\n\n\nFalsi" << endl;
    //cout << falsi(a,b) << endl;
    //cout << "\n\n\nNewton" << endl;
    //cout << newton((a+b)/2.0) << endl;
    //cout << "\n\n\nTangensy" << endl;
    //cout << tangents((a+b)/2.0, (a+b)/3.0) << endl;
    cout << "\n\n\nBrent" << endl;
    cout << brent(a, b) << endl;
}
