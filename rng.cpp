#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

int N = 1000000;
int N_bins = 1024;
int rng()
{
    int a = 1103515245;
    int c = 12345;
    int m = (int)1024;
	static int x = 0;
	x = (a*x+c) % m;
	return x;
}

vector<unsigned int> histogram(vector<double> dane, unsigned int N, int x_min = 0, int x_max = 1)
{
    vector<unsigned int> v(N,0);
    double dx = (double)(x_max-x_min)/(double)N;
    
    unsigned int N_dane = dane.size();
    for (unsigned int i=0; i<N_dane; i++)
    {
        int dana_bin = (int)(dane.at(i)/dx);
        v.at(dana_bin)++;
    }

    return v;
}

int main()
{
    vector<double> dane;
    
    for (int i=0; i<N; i++)
    {   
        dane.push_back(random()/(double)RAND_MAX);
    }
    vector<unsigned int> hist = histogram(dane, N_bins);
    for (auto val: hist)
    {
        cout << val << endl;
    }
   
}
