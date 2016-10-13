#include <iostream>
#include <cstdlib>

using namespace std;

void fun1(int number);

int main()
{
    int number = 12;
    cout << "Before fun1, number is " << number << endl;
    fun1(number);
    cout << "After fun1, number is " << number << endl;
    
    return 0;
}

void fun1(int number)
{
    cout << "Entering fun1, number is " << number << endl;
    number = 45;
    cout << "Leaving fun1, number is " << number << endl;
}

// use of global variable using const

#include <iostream>
#include <cstdlib>

using namespace std;

const double PI= 3.14159;

double perimeterCircle(double r);

int main()
{
    double degrees, radius;
    cout << "Enter a number of degrees, I will tell you radians:";
    cin >> degrees;

    cout << "That's equal to " << degrees /180 * PI << endl;

    cout << "Enter a radius length, I will tell the diameter:";
    cin >> radius;

    cout << "That's equal to " << perimeterCircle(radius) << endl;

    return 0;
}

double perimeterCircle(double r)
{
    return (2 * PI * r);
}

// bool functions
#include <iostream>
using namespace std;
bool isEven(int number);

int main()
{
    int i;
    while(1)
    {
        cout << "Enter a number:";
        cin >> i;
        
        if (isEven(i)) 
            cout << "Even!\n";
        if (!iEven(i))
            cout << "Odd!\n";
    }
}

bool isEven(int number)
{
    if(number %2 == 0)
    {
        return true;
    }
    else
        return false;
}

// modified function 
#include <iostream>

using namespace std;
bool isOdd(int number);

int main()
{
    int number;
    cout << "Enter a number, I will tell you if it is odd:";
    cin >> number;
    
    if (isOdd(number))
    {
        cout << "The number is odd\n";
    }
    return 0;
}

bool isOdd(int number)
{
    return number%2 != 0;
}

#include <iostream>
using namespace std;

int main()
{
    int number;
    int& aliasNum = number;
    // aliasNum and number are the same item with two names
    // they are always the same value
    //34,34
    number = 34;
    cout << "1. number is " << number << endl;
    cout << " aliasNum is " << aliasNum << endl;
    // 102, 102
    aliasNum = 102;
    cout << "2. number is " << number << endl;
    cout << " aliasNum is " << aliasNum << endl;
    // 18,18
    number = 18;
    cout << "3. number is " << number << endl;
    cout << " aliasNum is " << aliasNum << endl;
    
    cout << &(number) << endl;
    cout << &(aliasNum) << endl;
    
    return 0;
}

// two ways to change a variable value using functions
// a shortcut to determine whether to use pass-by-reference or pass-by-value
// if the value of a variable should be changed by the function
// yes then reference and put & in the parameter list.
#include <iostream>
#include <cstdlib>

using namespace std;

int addOneA(int number);
void addOneB(int& number);

int main()
{
    int number = 12, caseA, caseB;
    
    caseA = addOneA(number);
    
    caseB = number;
    addOneB(caseB);
    
    cout << "caseA is now:" << caseA << endl;
    cout << "caseB is now:" << caseB << endl;
    
    return 0;
    
}
// call by value, return a value
int addOneA(int number)
{
    return number + 1;
}

// call by reference, return nothing
void addOneB(int& number)
{
    number ++;
}

// maslib 
#include <iostream>

using namespace std;

void getInput(string& noun, string& verb, string& adj, string& adv);

void printMadlib(string noun, string verb, string adj, string adv);

int main()
{
    string noun, verb, adj, adv;
    
    getInput(noun, verb, adj, adv);
    printMadlib(noun, verb, adj, adv);
    
    return 0;
}

void getInput(string& noun, string& verb, string& adj, string& adv)
{
    cout << "Enter a noun:";
    cin>> noun;
    cout << "Enter a verb (past tense):";
    cin >> verb;
    cout << "Enter an adjective:";
    cin >> adj;
    cout << "Enter an adverb:";
    cin >> adv;
}

void printMadlib(string noun, string verb, string adj, string adv)
{
    cout << "The " << adj << " " << noun << " "
         << verb << " " << adv << "." << endl;
}

// parameter example
#include <iostream>
using namespace std;

void printmt(string text, int count);
void printmt(int count, string text);
void printmt(string text);
void printmt(string text, int count, bool newline);

int DEF = 400;

int main()
{
    // text count
    printmt("Hello", 20);
    // text count ('A'=65,'b'=98, ASCII)
    printmt("X", 'A');
    // text count
    printmt("bus\n", 3.14);
    // text
    printmt("h");
    // count text
    printmt(30,"wheels");
    // text count bool
    printmt("Q",5, true);
    printmt("w",5,false);
    
    return 0;
    
}

void printmt(string text, int count)
{
    for (int i=0; i<count; i++)
    {
        cout << text;
    }
}

void printmt(string text)
{
    for (int i=0;i<DEF;i++)
    {
        cout << text;
    }
}

void printmt(int count, string text)
{
    printmt(text,count);
}

void printmt(string text, int count, bool newline)
{
    for (int i=0;i<count;i++)
    {
        cout << text;
        if (newline)
        {
            cout << endl;
        }
    }
}

// reference example
#include <iostream>
using namespace std;

int main()
{
    int x = 15;
    int& y = x;
    // y is x's reference, you can't do & y = 4 
    // reference can't set to constants or expressions
    // references must be the same type
    // char var; int &j = var; 
    
    cout << "x is stored at memory location " << &x << endl;
    cout << "y is stored at memory location " << &y << endl;
    
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    // since y is a reference to x, what happens to y also happens to x
    // two differrent names for the same memory location
    y = 45;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}

// reference parameters
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void roll2Dice(int& d1, int& d2);

int main()
{
    srand(time(0));
    int dice1, dice2;
    
    roll2Dice (dice1, dice2);
    // 3,2
    cout << "Roll1 = " << dice1 << endl;
    cout << "Roll2 = " << dice2 << endl;
    
    roll2Dice (dice1, dice2);
    // 4,5
    cout << "Roll1 = " << dice1 << endl;
    cout << "Roll2 = " << dice2 << endl;
    
    return 0;
}

void roll2Dice (int& d1, int& d2);
{
    d1 = rand() %6 +1;
    d2 = rand() %6 +1;
}

// exercise 6
#include <iostream>

using namespace std;

int doSomething(int value);

int main()
{
    int i=0;
    //cout << doSomething(i);
    i = doSomething(i);
    // i will be 35 i = doSomething(i);
    // i will stay 0 if just doSomething(i);
    cout << "i " << i;
    return 0;
}
int doSomething(int value)
{
value = 35;
return value;
value = 13;
}

// compare to the program above
#include <iostream>

using namespace std;

int doSomething(int& value);

int main()
{
    int i=0;
    cout << doSomething(i);
    // i will be 35 because it's a call-by-reference parameter
    // what happened in the function changed i 
    cout << "i " << i;
    return 0;
}
int doSomething(int& value)
{
value = 35;
return value;
value = 13;
}
