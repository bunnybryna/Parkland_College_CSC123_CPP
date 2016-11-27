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

// a function ao allocate space
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
