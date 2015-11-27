#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double epsilon = pow(10,-12);


double f(double x)
{
    return sin(x+cos(x))-cos(x+sin(x));
}
double fprime(double x)
{
    return (1-sin(x))*cos(x+cos(x))+sin(x+sin(x))*(cos(x)+1);
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

bool sign(double a)
{
    if (a >=0) return true;
    else return false;
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
    double fx = f(x);
	while(abs(fx) > epsilon)
	{
	    cout << i << "\t" << x << "\t" << fabs(fx) << endl;
	    i++;
	    double fp = f(xprev);
	    if(abs(fx-fp) < epsilon)
	    {
	        return x;
	    }
	    else
	    {
	        x -= fx*(x-xprev)/(fx-fp);
	        fx = f(x);
	        xprev = x;
	    }
	}
	cout << i << endl;
	return x;
}

double git_dekker(double a, double b, double eps)
{
    int licznik = 0;
    while(fabs(b-a) > epsilon)
    {
        licznik ++;
        if(fabs(f(b)) < eps)
        {
            return b;
        }
        double s = b - (b - a) / (f(b) - f(a)) * f(b);
        double m = (a+b) / 2.0;
        double b2 = m;
        
        //cout << licznik << ": " << a << " " << b << " " << s << " " << m << endl;
        
        if( (b < s && s < m) || (b > s && s > m))
        {
            b2 = s;
        }
        
        if(sign(f(b2)) == sign(f(b)))
        {
            b = b2;
        }
        else
        {
            a = b2;
        }
        if (fabs(f(a)) < fabs(f(b)))
        {
            double c = a;
            a = b;
            b = c;
        }
    }
    return b;
}    

double dekker(double a, double b)
{
    double fa = f(a);
    double fb = f(b);
    double bnew = 0;
    double s = 0;
    if (fa*fb>0)
    {
        cout << "Zle warunki poczatkowe" << endl;
        cout << "f(a): " << fa << endl;
        cout << "f(b): " << fb << endl;
        return 0;
    }    
    double bprev = a;
    
    unsigned int iteracja = 0;
    bool czy_idzie_interpolacja = true;
    bool czy_b_s_m = true;
    
    while(abs(fb)>epsilon and iteracja < 100)
    {
        iteracja++;
        double fbprev = f(bprev);
        double m = (a+b)/2.0;
        if (abs(fb - fbprev) > epsilon) // f(bk) != f(bk-1)
        {
            czy_idzie_interpolacja = true;
            s = b - (b-bprev)/(fb-fbprev)*fb;
        }
        else
        {
            czy_idzie_interpolacja = false;
            s = m;
        }
        
        
        if (b < s and s < m)
        {
            czy_b_s_m = true;
            bnew = s;
        }
        else
        {
            czy_b_s_m = false;
            bnew = m;
        }

        
        //printf("i%4d a%8.4f b %7.4f s %7.4f m %7.4f interp %d bsm %d \n", iteracja, a, b, s, m, czy_idzie_interpolacja, czy_b_s_m);
        //cout << iteracja << "\t" << a << "\t" << b << "\t" << s << "\t" << m << "\t" << czy_idzie_interpolacja << "\t" << czy_b_s_m << endl;
        
        double fbnew = f(bnew);
        
        if (fa*fbnew>0) //ten sam znak
        {
            a = b;      //bk zamiast bk+1
            fa = fb;
        }
        b = bnew;
        fb = fbnew;        
        
        //nadpisanie b na bnew?
        
        if (abs(fa)<abs(fb))
        {
            double c = a;
            a = b;
            b = c;
        }
    }
    //cout << iteracja << endl;
    return b;
}

    
int main()
{   
    double a = 0;
    double b = 2.5;
    cout << "Bisekcja" << endl;
    cout << bisection(a,b) << endl;
    cout << "\n\n\nFalsi" << endl;
    cout << falsi(a,b) << endl;
    cout << "\n\n\nNewton" << endl;
    cout << newton(1) << endl;
    cout << "\n\n\nTangensy" << endl;
    cout << tangents((a+b)/2.0, (a+b)/3.0) << endl;
    //cout << "\n\n\nBrent" << endl;
    //cout << brent(a, b) << endl;
    cout << git_dekker(a,b, epsilon) << endl;
    //cout << dekker(0,5) << endl;
}
