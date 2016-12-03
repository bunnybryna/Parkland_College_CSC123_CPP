// dereferencing
#include <iostream>
using namespace std;
int main()
{
    int i=36;
    int *ptr = &i;
    cout << "Ptr is " << ptr << endl;
    cout << "The address where i is stored is " << &i << endl;
    
    cout << "Dereferecing ptr gives: " << *ptr << endl;
    cout << "Dereferecing the address where i is stored is " << *(&(i)) << endl;
    cout << "Dereferecing the address where i is stored is " << *&i << endl;
    
    return 0;
}

// using pointers to change values
#include <iostream>
using namespace std;
int main()
{
    int i=36;
    int *ptr;
    ptr = &i;
    cout << "i is " << i << endl;
    *ptr = 105;
    cout << "i is now " << i << endl;
    
    return 0;
}

// arrays are pointers
#include <iostream>
#include <cstdlib>
using namespace std;
// int *a points to the beginning of the array
void storeRandom(int *a, int size);
void printArray(int *a, int size);

int main()
{
    int numbers[10];
    storeRandom(numbers,10);
    printArray(numbers,10);

    return 0;
}

void storeRandom(int *a, int size)
{
    // treat a as an array
    for (int i=0;i<size;i++)
    {
        a[i] = rand();
    }
}

void printArray(int *a, int size)
{
    // treat a as an iterator
    for (int i=0;i<size;i++)
    {
        cout << *a << endl;
        a++;
    }
}


// sizeof() returns the number of bytes needed to store an element of the type 
#include <iostream>
using namespace std;
int main()
{
    cout << "An int uses " << sizeof(int) << " bytes!" << endl;
    cout << "A float uses " << sizeof(float) << " bytes!" << endl;
    cout << "A double uses " << sizeof(double) << " bytes!" << endl;
    cout << "A char uses " << sizeof(char) << " bytes!" << endl;
    cout << "A string uses " << sizeof(string) << " bytes!" << endl;
    
    return 0;
}

// malloc()
// malloc (size_t size) allocates a block of size bytes of memory, returning a pointer to the beginning of the block
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // size of the array
    int n = 100;
    // pointer to where the array is stored
    int *array;
    
    array = static_cast<int *>(malloc(n * sizeof(int)));
    for (int i=0;i<n;i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}

// a function to allocate space
#include <iostream>
#include <cstdlib>


using namespace std;
void getSpace(int **a, int n);

int main()
{
    int *array;
    getSpace(&array, 1000);
    for (int i=0;i<1000;i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}

void getSpace(int **a, int n)
{
    *a = static_cast<int *>(malloc(n*sizeof(int)));
}

// memory leaks
#include <iostream>
#include <cstdlib>

using namespace std;

void createSpace1();
void createSpace2();
void createSpace3();

int main()
{
    int count = 10000000;
    for (int i=0;i<count;i++)
    {
        createSpace1();
        //createSpace2();
        //createSpace3();
    }
    
    return 0;
}
// memory leak, not freeing up memory I allocated
void createSpace1()
{
    int array[1000];
}

void createSpace2()
{
    int n=1000;
    int *array;
    array = static_cast<int *>(malloc(n * sizeof(int)));
}

void createSpace3()
{
    int n=1000;
    int *array;
    
    array=static_cast<int *>(malloc (n*sizeof(int)));
    // making the block of memory available again
    free(array);
}

// passing pointers into functions
void addTo(int *)
int main()
{
    int value = 10;
    int *ptr = &value;
    addTo(ptr);
}
// if you have the address of a variable, you can do whatever to that variable
void addTo(int *pv)
{
    *pv += 10;
}

vod addToPtr(int *, int);

int main()
{
    int ivalue=10;
    int *iptr=&vialue;
    printf("ivalue before funciton is called: %d\n", ivalue);
    addToPtr(iptr,10);
    printf("ivalue after function is called: %d\n", ivalue);
    return 0;
}

void addToPtr(int *valuePtr,int x)
{
    *valuePtr += x;
}

// pass arrays into functions
// same as void addToArray(int *, int)
void addToArray(int [], int);
void main()
{
    int iarray[3] = {10, 20, 30};
    printf("iarray values before function is called: %d %d %d\n"), iarray[0], iarray[1], iarray[2]);
    addToArray(iarray, 10);
    printf("iarray values before function is called: %d %d %d\n"), iarray[0], iarray[1], iarray[2]);    
}
// void addToArray(int *array, int x) 
void addToArray(int iarray[], int x)
{
    // or *(iarray + 0) += x; that's pointer arithmetic
    iarray[0] += x;
    iarray[1] += x;    
    iarray[2] += x;
}

// pass by address
#include <iostream>
using namespace std;
void setToZero(int *ptr);
int main()
{
    int i=36;
    cout << "i is " << i << endl;
    setToZero(&i);
    cout << "i is now " << i << endl;
    
    return 0;
}

void setToZero(int *ptr)
{
    *ptr=0;
}