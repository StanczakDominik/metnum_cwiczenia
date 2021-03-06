#include <iostream>
using namespace std;
#include <stdio.h>
#include <cmath>
#include <vector>

vector<double> lambda = {1, 2, 3, 4, 3, 2};

vector<double> add(vector<double> x, double c1,vector<double> y, double c2)
{
    vector<double> xnew;
    for (int i=0; i<x.size(); i++)
    {
        xnew.push_back(c1*x[i] + c2*y[i]);
    }
    return xnew;
}
vector<double> f(double t, vector<double> x)
{
    vector<double> xnew;
    xnew.push_back(-lambda[0]*x[0]);
    for (int i=1; i<x.size(); ++i)
    {
        xnew.push_back(-lambda[i]*x[i]+lambda[i-1]*x[i-1]);
    }
    xnew.push_back(lambda[x.size()-1]*x[x.size()-1]);
    return xnew;
}

vector<double> Euler(double t, vector<double> x, double dt)
{
    return add(x, 1, f(t,x), dt);
}


vector<double> ModifiedEuler(double t, vector<double> x, double dt)
{
    return add(x, 1, f(t+dt/2., add(x, 1, f(t, x), dt/2.)), dt);
}

vector<double> RK4(double t, vector<double> x, double dt)
{
    vector<double> K1 = f(t, x);
    vector<double> K2 = f(t+dt/2., add(x, 1, K1, dt/2.));
    vector<double> K3 = f(t+dt/2., add(x, 1, K2, dt/2.));
    vector<double> K4 = f(t+dt, add(x, 1, K3, dt));
    return add(x, 1, add(K1, 1, add(K2, 2, add(K3, 2, K4, 1), 1), 1), dt/6.);
}

int main()
{
    int NPoints = 1000;
    double a = 0;
    double b = 10;
    double dt = (b-a)/double(NPoints);
    double t = 0;
    vector<double> x = {1000, 0, 0, 50, 5000, 125, 0};
    
    cout << t << " ";
    for (auto val: x)
    {
       cout << val << " ";
    }
    cout << endl;
    
    for (int i=1;i<NPoints; ++i)
    {
        x = RK4(t, x, dt);
        t+= dt;
        cout << t << " ";
        for (auto val: x)
        {
           cout << val << " ";
        }
        cout << endl;
    }
}
