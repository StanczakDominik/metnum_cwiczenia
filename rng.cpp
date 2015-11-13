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
    int a = 33;
    int c = 1;
    int m = 1024;
	static int x = 0;
	x = (a*x+c) % m;
	return x;
}

vector<unsigned int> histogram(vector<int> dane, unsigned int N, int x_min = 0, int x_max = 1024)
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
    vector<int> dane;
    
    for (int i=0; i<N; i++)
    {   
        dane.push_back(rng());
    }
    vector<unsigned int> hist = histogram(dane, N_bins);
    for (auto val: hist)
    {
        cout << val << endl;
    }
    
    int i = 0;
    
    for (int i = 3;i<15;i*=2
}