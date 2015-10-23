#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

//Neville
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

vector<double> polynomial_coefficients(vector<double>& xi, vector<double>& yi)
{
    vector<double> ci;
    
    unsigned N = xi.size();
    vector<double> x_temp = xi;
    vector<double> y_temp = yi;
    // GAUSSIAN ELIMINATION
    for (unsigned i=0; i<N; ++i)
    {
        double c = L(0,x_temp, y_temp);
        ci.push_back(c);
        for (unsigned j=0; j<y_temp.size(); j++)
        {
            y_temp[j]=(y_temp[j]-c)/(x_temp[j]);
        }
        unsigned min_index = min_abs_index(x_temp);
        x_temp.erase(x_temp.begin()+min_index);
        y_temp.erase(y_temp.begin()+min_index);        
    }
    return ci;
}

int main(int argc, char** argv)
{
    cout << setiosflags(ios::fixed) << setprecision(12) << endl;
        
    vector<double> xi;
    vector<double> yi;
    
    load_data(argv[1], xi, yi);
    
    vector<double> ci = polynomial_coefficients(xi, yi);
    
    
    for (unsigned i=0; i<ci.size(); i++)
    {
        if(i>0)
        {
            cout<< " + ";
        }
        cout << ci[i] << "*x**"<<i;
    }
    cout<<endl;
    
}
