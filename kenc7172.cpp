
// declaring arrays
#include <iostream>

using namespace std;

int main()
{
    double brightness[6];
    string name[6];
    int index;
    
    brightness[0]= -1.44;
    brightness[1]= -0.62;
    brightness[2]= -0.05;
    brightness[3]= -0.01;
    brightness[4]= +0.03;
    brightness[5]= +0.08;
    
    name[0] = "Sirius";
    name[1] = "Canopus";
    name[2] = "Arcturus";
    name[3] = "Rigel Kent A";
    name[4] = "Vega";
    name[5] = "Capella";
    
    index = 2;
    cout << "The third brightness star is "
         << name[index]
         << " with an apparent magnitude of "
         << brightness[index]
         << endl;
         
    return 0;
}

// arrays and loops
#include <iostream>
#include <iomanip>

using namespace std;

void initBright(double b[]);
void initName(string n[]);

int main()
{
    double brightness[6];
    string name[6];
    int i;
    // note when calling the function
    // argument is brightness not brightness[]
    initBright(brightness);
    initName(name);
    
    for (i=0;i<6;i++)
    {
        cout << setw(30) << name[i]
             << setw(10) << brightness[i]
             << endl;
    }
    return 0;
    
}

void initBright(double b[])
{
    b[0]= -1.44;
    b[1]= -0.62;
    b[2]= -0.05;
    b[3]= -0.01;
    b[4]= +0.03;
    b[5]= +0.08;    
}

void initName(string n[])
{
    n[0] = "Sirius";
    n[1] = "Canopus";
    n[2] = "Arcturus";
    n[3] = "Rigel Kent A";
    n[4] = "Vega";
    n[5] = "Capella";    
}

// out of bounds?
#include <iostream>

using namespace std;

int main()
{
    int number1 = 30;
    int a[10];
    int number2 = 10;
    
    cout << "Number1 is " << number1
         << " and Number 2 is " << number2 << endl;

    a[-1] = 999;
    cout << "After setting a[-1], number1 is " << number1
         << " and Number2 is " << number2 << endl;
         
    cout << "Number1 is stored at memory location " << &number1 << endl;
    cout << "Number2 is stored at memory location " << &number2 << endl;
    cout << "a is stored at memory location " << a << endl;
    cout << "a[-1] is stored at memory location " << &a[-1] << endl;
    
    return 0;
}

// shorts to initialize arrays
#include <iostream>
using namespace std;

int main()
{
    int month;
    string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug","Sep", "Oct", "Nov", "Dec"};
    int monthSize[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    do {
        cout << "Enter the number for a month[1-12]";
        cin >> month;
    } while (month < 1 || month > 12);
    
    cout << "Di you know there were " << monthSize[month-1]
         << " days in " << monthNames[month-1] << endl;

    return 0;
}

// filling an array with random numbers and printing them
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomFill(int a[], int s);
void printArray(int a[], int s);

const int SIZE = 150;

int main()
{
    int array[SIZE];
    srand(time(0));
    
    randomFill(array,SIZE);
    printArray(array,SIZE);
    
    return 0;
}

void printArray(int a[], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        a[i] = rand();
    }
}

void randomFill(int a[], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        cout << setw(9) << a[i];
        if (i%7== 6){
            cout << endl;
        }
    }
    cout << endl;
}

// parallel arrays
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void addName(string f[], string l[], int& s);
void listName(string f[], string l[], int s);
void putInOrder(string f[], string l[], int pos);

int main()
{
    string firstName[100];
    string lastName[100];
    // initialize size here
    int size = 0;

    while (!cin.eof())
    {
        // first add (then sort) and list
        addName(firstName, lastName, size);
        listName(firstName, lastName, size);
    }

    return 0;
}

void addName(string f[], string l[], int& s)
{
    cout << "Enter first name:";
    getline(cin, f[s]);
    cout << "Enter last name:(Ctrl-Z to end)";
    getline(cin, l[s]);

    if(!cin.eof())
    {
        // sort the list from 0 ... s-1
        s++;
        putInOrder(f,l,s-1);
    }
}
// make a new list, sort by last name alphetical order
void putInOrder(string f[], string l[], int pos)
{
    int spotInArray = pos-1;
    string itemToInsert_last= l[pos];
    string itemToInsert_first = f[pos];

    // make sure sort from f[1] and l[1]
    while (spotInArray >= 0)
    {
        // eg: you have l[0],l[1],l[2] and want to insert l[3]
        // spotInArray = 2,  first compare l[2]&l[3]
        // if l[2]value <= l[3] value
        // in the new list, l[2]'s next position should be l[3]'s value
        // and this function ends
        if (l[spotInArray] <= itemToInsert_last)
        {
            l[spotInArray + 1] = itemToInsert_last;
            f[spotInArray + 1] = itemToInsert_first;

            return ;
        }
    // if not, l[2]'value will take l[3]'s posiiton
    // and spotInArray = 2, then enter next iteration in the while loop
    // compare l[1]&l[3]'s value, same processure 
    // if necessary compare l[0]&l[3]'s value, till find some value smaller than l[3] value
    // l[3] value should take that one's next position
    l[spotInArray + 1] = l[spotInArray];
    f[spotInArray + 1] = f[spotInArray];
    spotInArray --;
    }
    // if there is no smaller, l[3] will be the first value in the next list
    l[0] = itemToInsert_last;
    f[0] = itemToInsert_first;

    return ;
}


void listName(string f[], string l[], int s)
{
    for (int i=0;i<s;i++)
    {
        cout << setw(3) << i << ")" << f[i] << " " << l[i] << endl;
    }
}

// find the lowest element in the array
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

void randomFill(int a[], int s);
void printArray(int a[], int s);
int findLeast(int a[], int start, int end);

const int SIZE = 30;

// int main() also works 
int main(int argc, char *argv[])
{
    int array[SIZE];
    srand(time(0));
    int posLeast;
    
    randomFill(array, SIZE);
    printArray(array, SIZE);
    
    posLeast = findLeast(array, 0, SIZE-1);
    cout << endl
         << "The smallest element is at position " << posLeast
         << " and it's value is " << array[posLeast]<< endl;
    
    printArray(array, SIZE);
    // note it's "PAUSE" instead of 'PAUSE'
    system("PAUSE");
    return EXIT_SUCCESS;
}

void randomFill(int a[], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        a[i]=rand();
    }
}

void printArray(int a[], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        cout << setw(9) << a[i];
        if (i%7 == 6)
        {
            cout << endl;
        }
    }
    cout << endl;
}

int findLeast(int a[], int start, int end)
{
    int posSoFar = start;
    int i;
    for (i=start + 1; i<= end; i++)
    {
        if (a[i]<a[posSoFar])
        {
            posSoFar = i;
        }
    }
    return posSoFar;
}

// swapping two array elements
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomFill(int a[], int s);
void printArray(int a[], int s);
int findLeast(int a[], int start, int end);
void swap(int a[], int pos1, int pos2);

const int SIZE=30;

int main()
{
    int array[SIZE];
    srand(time(0));
    int posLeast;
    
    randomFill(array, SIZE);
    printArray(array, SIZE);
    
    posLeast = findLeast(array, 0, SIZE-1);
    cout << endl
         << "The smallest element is at position " << posLeast
         << " and it's value is " << array[posLeast]<< endl;
    
    swap(array, 0, posLeast);
    cout << "Now that element has been swapped to the beginning:" << endl;
    
    printArray(array, SIZE);
    system("PAUSE");
    return EXIT_SUCCESS;
        
}

void randomFill(int a[], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        a[i]=rand();
    }
}

void printArray(int a[], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        cout << setw(9) << a[i];
        if (i%7 == 6)
        {
            cout << endl;
        }
    }
    cout << endl;
}

int findLeast(int a[], int start, int end)
{
    int posSoFar = start;
    int i;
    for (i=start + 1; i<= end; i++)
    {
        if (a[i]<a[posSoFar])
        {
            posSoFar = i;
        }
    }
    return posSoFar;
}

void swap(int a[], int pos1, int pos2)
{
    int temp = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = temp;
}

//selection sort
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomFill(int a[], int s);
void printArray(int a[], int s);
int findLeast(int a[], int start, int end);
void swap(int a[], int pos1, int pos2);

const int SIZE=10;

int main()
{
    int array[SIZE];
    srand(time(0));
    int posLeast;

    randomFill(array, SIZE);
    printArray(array, SIZE);

    int start;

    for (start=0;start <= SIZE-1;start++){
        posLeast = findLeast(array, start, SIZE-1);
        swap(array, start, posLeast);
        printArray(array, SIZE);
    }
    
    cout << "Now that list has been sorted:" << endl;
    
    printArray(array, SIZE);

    system("PAUSE");
    return EXIT_SUCCESS;

}

void randomFill(int a[], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        a[i]=rand();
    }
}

void printArray(int a[], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        cout << setw(9) << a[i];
        if (i%7 == 6)
        {
            cout << endl;
        }
    }
    cout << endl;
}

int findLeast(int a[], int start, int end)
{
    int posSoFar = start;
    int i;
    for (i=start + 1; i<= end; i++)
    {
        if (a[i]<a[posSoFar])
        {
            posSoFar = i;
        }
    }
    return posSoFar;
}

void swap(int a[], int pos1, int pos2)
{
    int temp = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = temp;
}
