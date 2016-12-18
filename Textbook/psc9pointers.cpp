// 9.2 basic pointer manipulations
#include <iostream>
using namespace std;

int main()
{
    // note that * is in front of p1 not after int
    int *p1,*p2;
    
    p1 = new int;
    *p1 = 42;
    // changes p2 so it points to the same thing that p1 is currently pointing to
    // so p2 changes and p1 has to change with p2 
    // if *p2 = *p1, then no one changes with another one(both call by value)
    p2 = p1;
    cout << " *p1 == " << *p1 << endl;
    cout << " *p2 == " << *p2 << endl;
    
    *p2 = 53;
    cout << " *p1 == " << *p1 << endl;
    cout << " *p2 == " << *p2 << endl;

    p1 = new int;
    *p1 = 88;
    cout << " *p1 == " << *p1 << endl;
    cout << " *p2 == " << *p2 << endl;
    cout << "Hope you got the point of this exmaple!\n";
    return 0;
}

// after this call to delete, the value of p is undefined, p is an uninitialized variable(dangling pointers)
delete p;

// defining pointer types, so that IntPtr p; is the same as int *p;
typedef int* IntPtr;

// arrays and pointers variables
#include <iostream>
using namespace std;
typedef int* IntPtr;

int main()
{
    IntPtr p;
    int a[10];
    int index;
    
    for (index=0;index<10;index++)
        a[index] = index;
    
    p=a;
    
    for (index=0;index<10;index++)
        cout << p[index] << " ";
    cout << endl;
    
    for (index=0;index<10;index++)
        p[index] = p[index] + 1;
    
    // that changes to the array p are also changes to the array a
    for (index=0;index<10;index++)
        cout << a[index] << " ";
    cout << endl;
    
    return 0;
}

// a dynamic array
#include <iostream>
#include <cstdlib>
#include <cstddef>

typedef int* IntArrayPtr;

void fill_array(int a[], int size);
void sort(int a[], int size);
void swap_values(int& v1, int& v2);
int index_smallest(const int a[], int start_index, int number_used);

int main()
{
    using namespace std;
    cout << "This program sorts numbers from lowest to highest.\n";
    
    int array_size;
    cout << "How many numbers will be sorted?";
    cin >> array_size;
    
    IntArrayPtr a;
    // new operator creates dynamic arrays
    a = new int[array_size];
    
    fill_array(a, array_size);
    sort(a, array_size);
    
    cout << "In sorted order the numbers are:\n";
    for (int index=0;index < array_size; index++)
        cout << a[index] << " " ;
    cout << endl;
    // so the memory used by this dynamic array is returned to the freestore
    // [] tell C++ that a dynamic array variable is being elminated
    delete [] a;
    
    return 0;
}

void fill_array(int a[], int size)
{
    using namespace std;
    cout << "Enter " << size << " integers.\n";
    for (int index=0; index<size; index++)
        cin >> a[index];
}

void sort(int a[], int size)
{
    int index_next_small ;
    for (int index = 0; index < size -1; index ++)
    {
        index_next_small= index_smallest(a, index, size);
        swap_values(a[index], a[index_next_small]);
    }   
}

void swap_values(int& v1, int& v2)
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int index_smallest(const int a[], int start_index, int number_used)
{
    int min = a[start_index], index_min = start_index;
    for (int index= start_index + 1; index < number_used; index ++)
        if (a[index] < min)
        {
            min = a[index];
            index_min = index;
        }
    return index_min;
}

// they are equivalent, subtract two pointers is the number of indexed variable between the two addresses
for (int i=0;i<array_size;i++)
{
    cout << *(d+i) << " ";
}
for (int i=0;i<array_size;i++)
    cout << d[i] << " ";

// 9.7 a two-dimensional dynamic array
#include <iostream>
using namespace std;

typedef int* IntArrayPtr;

int main()
{
    int d1,d2;
    cout << "Enter the row and column dimensions of the array:\n";
    cin >> d1 >> d2;
    
    IntArrayPtr *m = new IntArrayPtr[d1];
    int i,j;
    for (i=0;i<d1;i++)
        // m is now a d1 by d2 array
        m[i] = new int[d2];
    cout << "Enter " << d1 << " rows of " << d2 << " integers each:\n";
    for (i=0;i<d1;i++)
    {
        for (j=0;j<d2;j++)
            cin >> m[i][j];
    }
    
    cout << "Echoing the two-dimensional array:\n";
    for (i=0;i<d1;i++)
    {
        for(j=0;j<d2;j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    for (i=0;i<d1;i++)
        // must call delete[] to for each item
        delete[ ] m[i];
    delete[] m;
    
    return 0;
}