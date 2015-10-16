#include <iostream>

using namespace std;

float f(float& x)
{
    x +=1;
}

int main()
{
    float x = 3.141592;
    f(x);
    cout << x << endl;
}
