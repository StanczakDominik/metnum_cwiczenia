#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double L(double x_val, vector<double> xi, vector<double> yi)
{
    double Lx = 0.0;
    for (unsigned int i = 0 ; i<xi.size(); i++)
    {
        double P = yi[i];
        for (unsigned int j=0; j < yi.size(); j ++)
        {
           if(j!=i)
           {
                P *=  (x_val-xi[j])/(xi[i]-xi[j]);
           }
        }
        Lx += P;
    }
    return Lx;
}
    

int main()
{
    cout << setiosflags(ios::fixed) << setprecision(12) << endl;
    
    vector<double> xi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> yi = {1, 4, 9, 16, 25, 36, 49, 64, 81};
    
    vector<double> x;
    vector<double> y;
    for (double i =0.0; i< 10.0; i+=0.1)
    {
        x.push_back(i);
    }
    
    
    for (auto x_val: x)
    {   
        double Lx = L(x_val, xi, yi);
        y.push_back(Lx);
    }
    
    for (unsigned int i=0; i<x.size(); i++)
    {
        cout << x[i] << "\t" << y[i] << endl;
    }
               
}
