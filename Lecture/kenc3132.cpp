#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int number;
    cout << "Enter an integer grade and I'll tell you its letter grade:";
    cin >> number;
    if (number >= 97)
    {
        cout << "You scored an A+\n";
    }
    else if (number >= 92)
    {
        cout << "You scored an A\n";
    }
    else if (number >= 90)
    {
        cout << "You scored an A-\n";
    }
    else if (number >= 87)
    {
        cout << "You scored a B+\n";
    }    
    else if (number >= 82)
    {
        cout << "You scored a B\n";
    }
    else if (number >= 80)
    {
        cout << "You scored a B-\n";
    }
    else if (number >= 77)
    {
        cout << "You scored a C+\n";
    }
    else if (number >= 72)
    {
        cout << "You scored a C\n";
    }
    else if (number >= 70)
    {
        cout << "You scored a C-\n";
    }
    else if (number >= 67)
    {
        cout << "You scored a D+\n";
    }
    else if (number >= 62)
    {
        cout << "You scored a D\n";
    }
    else if (number >= 60)
    {
        cout << "You scored a D-\n";
    }
    else if (number >= 0)
    {
        cout << "You scored an F\n";
    }
    else
    {
        cout << "Wow, I've never seen a grade that bad!\n";
    }
    return 0;
}

// multiwayDaysInMonth
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string inputBuffer;
    int month;
    int daysInMonth;
    cout << "Enter the month as a number:";
    getline(cin,inputBuffer);
    
    month = atoi(inputBuffer.c_str());
    
    cout << "You entered "<< month << endl;
    
    if (month == 1 || 
        month == 3 ||
        month == 5 ||
        month == 7 ||
        month == 8 ||
        month == 10 ||
        month == 12)
    {
        daysInMonth = 31;
    }
    else if (month == 2)
    {
        daysInMonth = 28;
    }
    else if (month == 4 ||
             month == 6 ||
             month == 9 ||
             month == 11)
             {
                 daysInMonth = 30;
             }
    else
    {
        cout << "Invalid month!!!\n";
        daysInMonth = -1;
    }
    if (daysInMonth != -1)
    {
        cout << "There are " << daysInMonth << " days in the month!\n";
    }
    return 0;
}

// multiwayGrades
#include <iostream>

using namespace std;

int main()
{
    double grade;
    cout << "Enter a number:\n";
    cin >> grade;
    
    cout << "You entered " << grade << endl;
    
    if (grade >= 90)
    {
        cout << "if only assigns an A\n";
    }
    if (grade >= 80 && grade < 90)
    {
        cout << "if only assigns a B\n";
    }    
    if (grade >= 70 && grade < 80)
    {
        cout << "if only assigns a C\n";
    }
    if (grade >= 60 && grade < 70)
    {
        cout << "if only assigns a D\n";
    }
    if (grade < 60)
    {
        cout << "if only assigns an F\n";
    }
    // with if else if
    if (grade >= 90)
    {
        cout << "ifelseif gives an A\n";
    }
    else if (grade >= 80)
    {
        cout << "ifelseif gives a B\n";
    }
    else if (grade >= 70)
    {
        cout << "ifelseif gives a C\n";
    }
    else if (grade >= 60)
    {
        cout << "ifelseif gives a D\n";
    }    
    else
    {
        cout << "ifelseif gives an F\n";
    }
    
    return 0;
}

// multiwayOddEven
#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter an integer:\n";
    cin >> number;
    
    cout << "You entered "<< number << endl;
    
    if (number % 2 ==0)
    {
        cout << "That number is even\n";
    }
    else
    {
        cout << "That number is odd\n";
    }
    
    return 0;
}

// switchMenu
#include <iostream>

using namespace std;

int main()
{
    char menuChoice;
    
    cout << "Rock Menu:\n"
         << "A) Ingenous\n"
         << "B) Metamorphic \n"
         << "C) Sedimentary \n"
         << "\n"
         << "Enter your choice:";
    cin >> menuChoice;
    
    switch (menuChoice)
    {
        case 'A':
        case 'a':
            cout << "granite\n";
            break;
        case 'B':
        case 'b':
            cout << "slate\n";
            break;
        case 'C':
        case 'c':
            cout << "shale\n";
            break;
        default:
            cout << "Invalid Choice!\n";
            break;
    }
    
    return 0;
}