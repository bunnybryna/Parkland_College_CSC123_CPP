//Write a complete function called lowestPosition() which takes as array (of double) and the number of elements used in the array (as an int) and returns the position of the element with the least value (as an int).  You may assume the number of elements is >= 1.

#include <iostream>
using namespace std;

int lowestPosition(double a[], int size);
int main()
{
    double a[]={-3, -1, -9};
    int position;
    position = lowestPosition(a,3);
    cout << "Smallest element is at position " << position;

    return 0;
}
int lowestPosition(double a[], int size)
{
    int smIndex;
    double smValue;
    smIndex = 0;
    smValue = a[0];
    for (int i=0;i<size;i++)
    {
        if (a[i]<smValue)
        {
            smIndex = i;
            smValue = a[i];
        }
    }
    return smIndex;
}


//Write a function called setToMin() that will work with the following section of code. It works for any integer variable and will set it to the lowest of the subsequent three integer parameters.  You don't need to put in the prototype, but you need to write a complete function.  All the variables are integers.

int x, y, z;
setToMin(x, 1, 4, -6);
// the value of x is now -6

setToMin(y, 4, 2, 8);
// the value of y is now 2

setToMin(z, -9, -8, -7);
// the value of z is now -9

#include <iostream>
using namespace std;
void setToMin(int &number, int n1, int n2, int n3);
int main()
{
    int x, y, z;
    setToMin(x, 1, 4, -6);
    cout << x << endl;
    // the value of x is now -6
    setToMin(y, 4, 2, 8);
    // the value of y is now 2
    cout << y << endl;
    setToMin(z, -9, -8, -7);
    // the value of z is now -9
    cout << z << endl;
    int n;
    setToMin(n, -1, 0, 3);
    cout << n << endl;
    return 0;

}
void setToMin(int &number, int n1, int n2, int n3)
{
    int smNumber;
    if (n1 <= n2)
    {
        if(n2 <= n3)
        {
            smNumber = n1;
        }
        else
        {
            if (n1<= n3)
            {
                smNumber = n1;
            }
            else
            {
                smNumber = n3;
            }
        }

    }
    else
    {
        if(n2 >= n3)
        {
            smNumber = n3;
        }
        else
        {
            smNumber = n2;
        }
    }
    number = smNumber;
}

//Write a function called printBackwards() that will work with a C++ string.  The function will print any C++ string backwards. You don't need to put in the prototype, but you need to write a complete function.  

string name="Oliver Twist";
printBackwards(name);
// tsiwT revilO is sent to cout

printBackwards("nothing");
// gnihtin is sent to cout
#include <iostream>
using namespace std;
void printBackwards(string oldString);
int main()
{
    string name="Oliver Twist";
    printBackwards(name);
    printBackwards("nothing");
    printBackwards("Bryna");
    return 0;
}
void printBackwards(string oldString)
{
    string newString;
    for (int i=oldString.length()-1;i>=0;i--)
    {
        newString += oldString[i];
    }
    cout << newString << endl;
}
