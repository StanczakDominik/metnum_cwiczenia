#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <cmath>
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
void print_vector_part(vector<int> A, int left, int right)
{
    for (unsigned i=left; i<=right; i++)
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
        print_vector(A);
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

vector<int> cocktailSort(vector<int> A)
{
    unsigned N = A.size();
    bool any_have_moved = false;
    for (unsigned i=0; i < N/2; i++)
    {   
        //cout << endl;
        print_vector(A);
        any_have_moved = false;
        for (int j = i; j< N - i - 1; j++)
        {
            //print_vector(A);	
            if(A.at(j) > A.at(j+1))
            {
                any_have_moved=true;
                swap(A.at(i), A.at(j+1));
            }
            j++;
        }
        
        //cout << "pierwsza petla ";
        print_vector(A);
        
        
        for(unsigned k = N-i-2; k>=i+1; k--)
        {
            if(A.at(k) < A.at(k-1))
            {
                any_have_moved=true;
                swap(A.at(k),A.at(k-1));
            }
            k--;
        }        
        if(!any_have_moved)
        {
            break;
        }
    }
    return A;
}

void quickSort(vector<int> &A, int left, int right)
{
    int i = left;
    int j = right;
    int pivot = A.at(int((i+j)/2.));
    cout << "left: " << left << " right: " << right << " pivot: " << pivot << endl;
    while( i < j)
    {
        print_vector_part(A, left, right);
        while(A.at(i) < pivot)
        {
             i++;
        }
        while(A.at(j) > pivot)
        {
            j--;
        }   
    
        if(i<=j)
        {   if (i != j)
                swap(A.at(i),A.at(j));
            i++;
            j--;
        }
        else break;
    }
    if (left < j)
        quickSort(A, left, j);
    if (right > i)
        quickSort(A, i, right);	
}


void print_heap(vector<int> A)
{
    int N = A.size();
    int levels = log(N+1)/log(2); //do iteracji
    int i = 0;
    int level = 0;
    while(level < levels)
    {
        int j = i;
        int on_this_level = pow(2,level);
        int spaces_this_level = levels - level-1;
        //cout << spaces_this_level << endl;
        while(j<i+on_this_level)
        {
            for (int k=0; k<levels-level-1; k++)
                printf("   ");
            printf("%3d", A.at(j));
            j++;
            
        }
        cout << endl;
        i=j;
        level++;
    }
    
}

void downheap(vector<int> A, int i)
{
	while(true)
	{
	    int k = 2*i+1;
	    if (A[k+1] > A[k])
	    {
	        return;
	    }
	}
}

vector<int> heapSort(vector<int> A);

int main()
{
    vector<int> A = negatively_sorted_vector(31);////{0, 1, 1, 3, 2, 5, 1};//
    print_vector(A);
    print_heap(A);
    //selectionSort(A);
    //bubbleSort(A);
    //print_vector(selectionSort(A));
    //print_vector(insertSort(A));
    //cout << "bubblesort" << endl;
    //print_vector(bubbleSort(A));
    //cout << "cocktailsort" << endl;
    //print_vector(cocktailSort(A));
    //cout << "quickSort" << endl;
   // quickSort(A, 0, A.size()-1);
    //print_vector(A);
    //sort(A);
}
