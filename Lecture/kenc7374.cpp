// binary search C++ string
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define NOTFOUND -1

void printArray(string a[], int s);
int binarySearch(string a[], int s, string lookingFor);
int binarySearchWork(string a[], int start, int end, string lookingFor);

const int SIZE =16;

int main(int argc, char *argv[])
{
    string array[SIZE] = {"auto","bus","car", "dogsled", "elephant", "f",
    "gocart", "hitchnike", "i", "j", "kite", "l", "motorboat", "p"};
    printArray(array, SIZE);

    char again = 'y';
    string lookingFor;
    int pos;

    do{
        cout << "Enter word to look for:";
        cin >> lookingFor;

        pos = binarySearch(array, SIZE, lookingFor);

        if (pos == NOTFOUND)
        {
            cout << "Not found" << endl;
        }
        else
        {
            cout << "Found at position " << pos << endl;
        }
        cout << "Do you wish to search again?[Y/N]";
        cin>> again;
    } while (again == 'Y' || again == 'y');

    system("PAUSE");
    return EXIT_SUCCESS;
}
 // this function is a wrapper to get parameters same
 int binarySearch(string a[], int s, string lookingFor)
 {
     return binarySearchWork(a, 0, s-1, lookingFor);
 }

 int binarySearchWork(string a[], int start, int end, string lookingFor)
 {
    if (end < start)
    {
        return NOTFOUND;
    }

    int middle = (start + end)/2;
    if ( a[middle]<lookingFor)
    {
        return binarySearchWork(a, middle+1, end, lookingFor);
    }
    else if (a[middle] > lookingFor)
    {
        return binarySearchWork(a, start, middle-1, lookingFor);
    }
    else
        return middle;
 }

 void printArray(string a[], int s)
 {
     int i;
     for (i=0; i<s; i++)
     {
         cout << i << setw(9) << a[i] << endl;
         if (i % 7 == 6)
         {
            // start a new line every 6 numbers
            cout << endl;
         }
     }
     cout << endl;
 }

 // linear search
 #include <iostream>
 #include <cstdlib>
 #include <iomanip>
 #include <ctime>
 
 using namespace std;
 
 void randomFill(int a[], int s);
 void printArray(int a[], int s);
 
 const int SIZE = 30;
 
 int main()
 {
     int array[SIZE];
     srand(time(0));
     randomFill(array, SIZE);
     printArray(array, SIZE);
     
     char again = 'y';
     bool found = false;
     int lookingFor;
     
     do{
         cout << "Enter number to look for:";
         cin >> lookingFor;
         
         for (int pos = 0; pos < SIZE; pos ++)
         {
             if (array[pos] == lookingFor)
             {
                 cout << "Found at postion " << pos << endl;
                 found = true;
                 break;
             }
         }
         if (!found) 
         {
             cout << "Not found" << endl;
         }
         cout << "Do you wish to search again?[Y/N]";
         cin >> again;
         } while (again == 'y' || again == 'Y');
 
    system("PAUSE");
    return EXIT_SUCCESS;
 }    
    
    void randomFill(int a[], int s)
{
    int i;
    for (i=0; i< s; i++)
    {
        a[i] == rand();
    }        
    
 }
 
 void printArray(int a[], int s)
 {
     int i;
     for (i=0;i<s; i++)
     {
         cout << setw(9) << a[i];
         if (i % 7 == 6)
         {
             cout << endl;
         }
     }
     cout << endl;
 }
 
   #include <iostream>
 #include <cstdlib>
 #include <iomanip>
 #include <ctime>

 using namespace std;

 #define NOTFOUND -1

 void randomFill(int a[], int s);
 void printArray(int a[], int s);
 int linearSearch(int a[], int s, int lookingFor);

 const int SIZE = 30;

 int main(int argc, char *argv[])
 {
     int array[SIZE];
     srand(time(0));
     randomFill(array, SIZE);
     printArray(array, SIZE);

     char again = 'y';
     int lookingFor;
     int pos;

     do{
         cout << "Enter number to look for:";
         cin >> lookingFor;

         pos = linearSearch(array, SIZE, lookingFor);
         if (pos == NOTFOUND)
         {
             cout << "Not found" << endl;
         }
         else
         {
            cout << "Found at position " << pos << endl;
         }

         cout << "Do you wish to search again?[Y/N]";
         cin >> again;
         } while (again == 'y' || again == 'Y');

    system("PAUSE");
    return EXIT_SUCCESS;
 }

    void randomFill(int a[], int s)
{
    int i;
    for (i=0; i< s; i++)
    {
        a[i] == rand();
    }

 }

 void printArray(int a[], int s)
 {
     int i;
     for (i=0;i<s; i++)
     {
         cout << setw(9) << a[i];
         if (i % 7 == 6)
         {
             cout << endl;
         }
     }
     cout << endl;
 }

 int linearSearch(int a[], int s, int lookingFor)
 {
    for (int pos = 0; pos < SIZE; pos ++)
    {
        if (a[pos] == lookingFor)
        {
            return pos;
        }
    }
    return NOTFOUND;
 }

 // binary search
 #include <iostream>
 #include <cstdlib>
 #include <iomanip>
 #include <ctime>
 
 using namespace std;
 
 #define NOTFOUND -1
 
 void randomFill(int a[], int s);
 void printArray(int a[], int s);
 int findLeast(int a[], int start, int end);
 void swap(int a[], int pos1, int pos2);
 void selectionSort(int a[], int s);
 int binarySearch(int a[], int s, int lookingFor);
 int binarySearchWork(int a[], int s, int lookingFor);
 
 const int SIZE = 30;
 
 int main()
 {
     int array[SIZE];
     srand(time(0));
     randomFill(array, SIZE);
     selectionSort(array, SIZE);
     printArray(array, SIZE);
     
     char again = 'y';
     int lookingFor;
     int pos;
     
     do{
         cout << "Enter number to look for: ";
         cin >> again;
         
         pos = binarySearch(array, SIZE, lookingFor);
         if (pos == NOTFOUND)
         {
             cout << "Not found" << endl;
         }
         else
         {
            cout << "Found at position" << pos << endl; 
         }
         cout << "Do you wish to search again?[Y/N]";
         cin >> again;
     } while (again == 'y' || again == 'Y');
     system("PAUSE");

 }
 
 int binarySearch(int a[], int s, int lookingFor)
 {
     return binarySearchWork(a, 0, s-1, lookingFor);
 }
 
 int binarySearchWork(int a[], int start, int end, int lookingFor)
 {
     if (end < start)
     {
         return NOTFOUND;
     }
     
     int middle = (start + end)/2;
     if (a[middle] < lookingFor)
     {
         return binarySearchWork(a, middle + 1, end, lookingFor);
     }
     else if( a[middle]> lookingFor)
     {
         return binarySearchWork(a, start, middle-1, lookingFor);
     }
     else 
         return middle;
 }
 
 
    void randomFill(int a[], int s)
{
    int i;
    for (i=0; i< s; i++)
    {
        a[i] == rand();
    }

 }

 void printArray(int a[], int s)
 {
     int i;
     for (i=0;i<s; i++)
     {
         cout << setw(9) << a[i];
         if (i % 7 == 6)
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
     for(i=start+1; i <= end;, i++)
     {
         if (a[i]<a[posSoFar])
             posSoFar = i;
     }
     return posSoFar;
 }
 
 void swap(int a[], int pos1, int pos2)
 {
     int temp = a[pos1];
     a[pos1] = a[pos2];
     a[pos2] = temp;
 }
 
 void selection(int a[], int s)
 {
     for (int pos = 0; pos < s; pos ++)
     {
         swap(a, pos, findLeast(a, pos, s-1));
     }
 }