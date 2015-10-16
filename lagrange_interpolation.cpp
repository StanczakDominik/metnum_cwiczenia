#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

double L(double x_val, vector<double>& xi, vector<double>& yi)
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

void load_data(string file_name, vector<double>& x_points, vector<double>& y_points)
{
    ifstream data_file(file_name);
    while(true)
    {
        double x;
        double y;
        data_file >> x;
        data_file >> y;   
        if (data_file.eof())
        {
            return;
        }
        x_points.push_back(x);
        y_points.push_back(y);     
    }
}

double min(vector<double> x)
{
    double result = x[0];
    for (unsigned int i=1; i<x.size(); ++i)
    {
        if (x[i] < result)
        {
            result = x[i];
        }
    }
    return result;
}
double max(vector<double> x)
{
    double result = x[0];
    for (unsigned int i=1; i<x.size(); ++i)
    {
        if (x[i] > result)
        {
            result = x[i];
        }
    }
    return result;
}
int main(int argc, char** argv)
{
    cout << setiosflags(ios::fixed) << setprecision(12) << endl;
        
    vector<double> xi;
    vector<double> yi;
    
    load_data(argv[1], xi, yi);
    
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
    
    ofstream fit_file(argv[2]);
    
    for (unsigned int i=0; i<x.size(); i++)
    {
        fit_file << x[i] << "\t" << y[i] << endl;
    }
    
    cout << "min, max" << endl;
    cout << min(xi) << "\t" << max(xi) << endl;
}
