#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

double L(double x_val, vector<double>& xi, vector<double>& yi)
{
    vector<double> P = yi;
    for (unsigned int i = 1 ; i<xi.size(); i++)
    {
        for (unsigned int j=0; j < yi.size()-i; j ++)
        {
            P[j]=((x_val - xi[i+j])*P[j]-(x_val-xi[j])*P[j+1])/(xi[j]-xi[i+j]);
        }
    }
    return P[0];
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
unsigned min_abs_index(vector<double> x)
{
    double result = fabs(x[0]);
    unsigned result_index = 0;
    for (unsigned int i=1; i<x.size(); ++i)
    {
        if (fabs(x[i]) < result)
        {
            result = fabs(x[i]);
            result_index = i;
        }
    }
    return result_index;
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
    
    vector<double> ci;
    
    double c0 = L(0, xi, yi);
    ci.push_back(c0);
    
    for (unsigned i=0; i<xi.size(); ++i)
    {
        unsigned min_index = min_abs_index();
              
    }
    
}
