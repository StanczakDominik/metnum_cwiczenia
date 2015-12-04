#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
using namespace std;

vector<int> random_vector(unsigned n)
{
    srand(time(NULL));
    vector<int> A;
    for(unsigned i=0; i<n; i++)
    {
        A.push_back(int(n*(double(rand())/double(RAND_MAX))));
    }
    return A;
}

vector<int> negatively_sorted_vector(unsigned n)
{
    vector<int> A;
    for(int i=n; i>0; i--)
    {
        A.push_back(i);
    }
    return A;
}

void print_vector(vector<int> A)
{
    for (unsigned i=0; i<A.size(); i++)
    {
        cout << A.at(i) << " ";
    }
    cout << endl;
}

vector<int> selectionSort(vector<int> A)
{
    unsigned N = A.size();
    for (unsigned i=0; i<N; i++)        //na ktore miejsce wstawiamy w tej chwili?
    {
        //print_vector(A);
        int min = i;
        for (unsigned j = i; j<N; j++)  //ktory element sprawdzamy czy bedzie 
        {
            if(A.at(j)<A.at(min))
            {
                min = j;
            }
        }
        swap(A.at(min), A.at(i));
    }
    return A;
}

vector<int> insertSort(vector<int> A)
{
    unsigned N = A.size();
    for (unsigned i=1; i<N; i++)        //czesc posortowana
    {   
        //cout << endl;
        //print_vector(A);
        unsigned j = i;
        while(j > 0 and A.at(j-1) > A.at(j))
        {
            swap(A.at(j),A.at(j-1));
            //print_vector(A);
            j--;
        }
    }
    return A;
}

vector<int> bubbleSort(vector<int> A)
{
    unsigned N = A.size();
    bool any_have_moved = false;
    for (unsigned i=0; i<N; i++)
    {   
        //cout << endl;
        //print_vector(A);
        any_have_moved = false;
        for(unsigned j=i; j<N; j++)
        {
            //print_vector(A);	
            if(A.at(i) > A.at(j))
            {
                any_have_moved=true;
                swap(A.at(i), A.at(j));
            }
        }
        
        if(!any_have_moved)
        {
            break;
        }
    }
    return A;
}
vector<int> quickSort(vector<int> A);
vector<int> heapSort(vector<int> A);

int main()
{
    vector<int> A = random_vector(10000);
    //print_vector(A);
    //print_vector(selectionSort(A));
    //print_vector(insertSort(A));
    selectionSort(A);
    //print_vector(bubbleSort(A));
}
