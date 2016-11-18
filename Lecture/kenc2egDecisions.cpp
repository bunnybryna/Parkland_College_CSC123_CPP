// relational operators with integers
// code revised by Bryna
#include <iostream>

using namespace std;

int main()
{
    int numberOfLives;
    
    cout << "Tell me how many lives do you have left?\n";
    cin >>4 numberOfLives;
    
    if (numberOfLives <= 3)
    {
        cout << "You are nearing death\n";
        if (numberOfLives == 1)
            cout << "Almost done! Click here to buy more!\n";
        else if (numberOfLives == 0)
            cout << "Game over!\n";
    }
    else if (numberOfLives > 10)
        cout << "Wrong number, try again! ";
    else
        cout << "You are good! Keep alive!";
    
    return 0;
}

// decisionsAndOr
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string inputBuffer;
    int number;
    cout << "Enter a number:";
    getline(cin, inputBuffer);
    number = atoi(inputBuffer.c_str());
    
    if(number >= 0 && number <= 100)
    {
        cout << "Does this work... yes.\n";
    }
    return 0;
}

// decisionsEvenOdd
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string inputBuffer;
    int number;
    cout << "Enter a number:\n";
    getline(cin, inputBuffer);
    number = atoi(inputBuffer.c_str());
    
    if (number %2 == 0)
    {
        cout << "Your number is even.\n";        
    }
    // or else if (number%2), when number%2 !=0, if true
    else if (number %2 == 1)
    {
        cout << "Your number is odd.\n";
        
    }
    
    return 0;
}

// decisionsIncorrectOr.cpp
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string inputBuffer;
    int number;
    cout << "Enter a number:\n";
    getline(cin, inputBuffer);
    number = atoi(inputBuffer.c_str());
    // if (number == 2 || 3 || 5 || 7 || 11 || 13 || 17 || 19)is wrong
    if (number == 2 || 
    number == 3 ||
    number == 5 ||
    number == 7 || 
    number == 11 || 
    number == 13 || 
    number == 17 ||
    number == 19)
    cout << "Prime\n";
    
    return 0;
    }

// decisionsLeapYear    
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int year;
    cout << "Enter a year: \n";
    cin >> year;
    
    if (year % 4 == 0)
    {
        cout << "It's a leap year(version1, Julian). \n";
    }
    // \ escape 
    cout << "Ken said, \"I thought I mentioned quotes!\"\n";
    cout << "\\\\ is the way to print a \\(backslash).\n";
    cout << "\\n is a newline \n\n\n\n\n\n\n\n";
    cout << "' is a singe quote.\n ";
    
    return 0;
}    

// decisionsStrings
#include <iostream>

using namespace std;

int main()
{
    string password;
    string gameChoice;
    
    cout << "Enter the password:\n";
    getline(cin,password);
    
    if (password == "joshua")
    {
        cout << "Shall we play a game?\n";
        getline(cin, gameChoice);
        if (gameChoice == "y")
        {
            cout << "Global Thermonuclear War?\n";
            cout << "Tic Tac Toe?\n";
        }
    }
    
    return 0;
}

// julianDay
/// a julian day is the number of days since the beginning of the year.
#include <cstdlib>
#include <iostream>
 
using namespace std;
 
int main()
{
    int month, day, year;
 
    int daysFromMonth=0;      // days added from previous months
    int daysFromDay=0;        // days added from this month
    int daysFromLeapYear=0;   // day added from leapyear
 
    cout << "Enter the month [1-12]: ";
    cin >> month;
 
    cout << "Enter the day [1-31]: ";
    cin >> day;
 
    cout << "Enter the year [4 digits]: ";
    cin >> year;
 
    cout << endl << "You entered: " << month << "/" << day << "/" << year << endl;
 
    daysFromDay = day;
 
    if ( (year % 4 == 0 && year % 100 != 0)  || (year % 400 == 0) ) {
       // the year is a leap year
       if (month > 2) {
          daysFromLeapYear = 1;
       }
    }
 
    if (month == 1) {
       daysFromMonth = 0;
    }
    if (month == 2) {
       daysFromMonth = 31;  /// number of days in january
    }
    if (month == 3) {
       daysFromMonth = 31 + 28; /// number of days in january & february
    }
    if (month == 4) {
       daysFromMonth = 31 + 28 + 31; /// number of days in january & february & march
    }
    if (month == 5) {
       daysFromMonth = 31 + 28 + 31 + 30;
    }
    if (month == 6) {
       daysFromMonth = 31 + 28 + 31 + 30 + 31;
    }
    if (month == 7) {
       daysFromMonth = 31 + 28 + 31 + 30 + 31 + 30;
    }
    if (month == 8) {
       daysFromMonth = 31 + 28 + 31 + 30 + 31 + 30 + 31;
    }
    if (month == 9) {
       daysFromMonth = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
    }
    if (month == 10) {
       daysFromMonth = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
    }
    if (month == 11) {
       daysFromMonth = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
    }
    if (month == 12) {
       daysFromMonth = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
    }
 
    cout << "The julian day number is "
         << daysFromMonth + daysFromDay + daysFromLeapYear << endl;
 
    return 0;
}