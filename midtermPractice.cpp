// practice 1.1
#include <iostream>

using namespace std;

void setToZero(int& number);
int main()
{
    
    int x, y, z;
    setToZero(x);
    setToZero(y);
    setToZero(z);
    cout << x << y << z;
    return 0;
}

void setToZero(int& number)
{
    number = 0;
}

// 1.2
#include <iostream>
// 1.2
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int randomYear(int startNum, int remainer);

int main()
{
int y1, y2, y3;

y1 = randomYear(1000, 1999);
// 1000 <= y1 <= 1999
y2 = randomYear(1996, 2008);
// 1996 <= y2 <= 2008
y3 = randomYear(1970, 1980);
// 1970 <= y3 <= 1980

cout << y1 << endl << y2 << endl << y3;

return 0;

}

int randomYear(int startNum, int endNum)
{
    srand(time(0));
    int remainer;
    remainer = endNum - startNum;
    return (rand()%remainer + startNum);
}


// 1.3 
#include <iostream>

using namespace std;

void printRange(int start, int end);

int main()
{
    printRange(10, 15);
// 10 11 12 13 14 15 is output
printRange(9, 6);
// 9 8 7 6 is output
printRange(7, 7);
// 7 is output

    return 0;
}

void printRange(int start, int end)
{
    int i;
    for (i = start; i <= end; i++)
    {
        cout << i;
    }
    
}

// 1.4
// between in this case means not equal to the bounds.  
// 10 is not between 10 and 15,
// 15 is not between 10 and 15,
// 12 is between 10 and 15,
#include <iostream>
using namespace std;

bool isBetween(int numA, int numB, int numTest);

int main()
{
    
    if (isBetween(10, 15, 20)) 
        cout << "20 is between 10 and 15."<< endl;
    else
        cout << "20 is not between 10 and 15."<< endl;
    if (isBetween(10, 15, 15)) 
        cout << "15 is between 10 and 15."<< endl;
    else
        cout << "15 is not between 10 and 15."<< endl;
    if (isBetween(10, 15, 10)) 
        cout << "10 is between 10 and 15."<< endl;
    else
        cout << "10 is not between 10 and 15."<< endl;
    if (isBetween(10, 15, 12)) 
        cout << "12 is between 10 and 15."<< endl;
    else
        cout << "12 is not between 10 and 15."<< endl;

    return 0;
}


bool isBetween(int numA, int numB, int numTest)
{
    if (numTest > numA && numTest < numB)
    {
        return true;
    }
    else
        return false;
}

// 1.5
#include <iostream>

using namespace std;

void repeatString(string sth, int num);

int main()
{
    repeatString("x",14);
    repeatString(":=",8);
    return 0;
}

void repeatString(string sth, int num)
{
    int i;
    for (i=0;i<=num;i++)
        cout << sth;

}

// 2.1
#include <iostream>

using namespace std;

void setToCSC123(string& anything);

int main()
{
    string label1, label2, label3;
    setToCSC123(label1);
    setToCSC123(label2);
    setToCSC123(label3);

    // the values of label1, label2 and label3 are now 'csc123'.

    cout << "This following line should be three copies of csc123" << endl;
    cout << label1 << label2 << label3 << endl;
}

void setToCSC123(string& anything)
{
    anything = "csc123";

}

// 2.2
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int midtermRandom(int num);

// nothing in main() can change!
int main()
{
    srand(time(0));

    cout << "Here's a random number from 1 to 20: ";
    cout << midtermRandom(20) << endl;

    cout << "Here's a random number from 1 to 100: ";
    cout << midtermRandom(100) << endl;

    cout << "Here's a random number from 1 to 6: ";
    cout << midtermRandom(6) << endl;
}

int midtermRandom(int num)
{
    return (rand()%(num-1) +1 );
}

// 2.3
#include <iostream>


using namespace std;

void midtermEvenPrint(int start, int end);

int main()
{
    srand(time(0));

    cout << "Print the even numbers from 1 to 10 ";
    cout << "(should be 2, 4, 6, 8, 10)";
    midtermEvenPrint(1, 10);

    cout << "Print the even numbers from 4 to 15 ";
    cout << "(should be 4, 6, 8, 10, 12, 14)";
    midtermEvenPrint(4, 15);

    cout << "Print the even numbers from -3 to 3 ";
    cout << "(should be -2, 0, 2)";
    midtermEvenPrint(-3, 3);

    return 0;
}

void midtermEvenPrint(int start, int end)
{
    int i;
    for (i = start; i < end; i++ )
    {
        if (start%2 == 0)
        {
            cout << i;
            i ++;
        }
        else
        {
            cout << ++i;
        }
    }

}


// 2.4
double maxCSC123(double num1, double num2, double num3)
{
    double maxnum;
    if (num1 >= num2)
    {
        if (num1 >= num3)
        {
            maxnum = num1;
        }
        else
        {
            maxnum = num3;
        }
    }
    else
    {
        maxnum = num2;
        if (num2 >= num3)
        {
            maxnum = num2;
        }
        else
            maxnum = num3;
    }

    return maxnum;

}

// 2.5
#include <iostream>

using namespace std;


bool isOdd(int num);

int main()
{
    int i;

    i = 5;
    if (isOdd(i))
    {
        cout << "5 is odd: " << endl;
    }
    else 
    {
        cout << "My program thinks 5 is even!! " << endl;
    }


    i = 202;
    if (isOdd(i))
    {
        cout << "My program thinks 202 is odd!!: " << endl;
    }
    else 
    {
        cout << "202 is even. " << endl;
    }

}

bool isOdd(int num)
{
    if (num%2 == 0)
        return false;
    else
        return true;
}