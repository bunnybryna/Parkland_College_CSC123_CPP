
//2.1 
#include <iostream>
using namespace std;
int main()
{
    int number_of_bars;
    double one_weight, total_weight;
    
    cout << "Enter the number of candy bars in a package\n";
    cout << "and the weight in ounces of one candy bar.\n";
    cout << "Then press return.\n";
    cin >> number_of_bars;
    cin >> one_weight;
    
    total_weight = one_weight * number_of_bars;
    
    cout << number_of_bars << "candy bars\n";
    cout << one_weight << "ounces each\n";
    cout << "Total weight is " << total_weight << "ounces.\n";
    
    cout << "Try another brand.\n";
    cout << "Enter the number of candy bars in a package\n";
    cout << "and the weight in ounces of one candy bar.\n";
    cout << "Then press return.\n";
    cin >> number_of_bars;
    cin >> one_weight;
    
    total_weight = one_weight * number_of_bars;
    
    cout << number_of_bars << "candy bars\n";
    cout << one_weight << "ounces each\n";
    cout << "Total weight is " << total_weight << " ounces.\n";
    
    cout << "Perhaps an apple would be healthier.\n";
    
    return 0;
}

//some examples 
#include <iostream>
using namespace std;
#include <iostream.h>

int count, number_of_dragons, number_of_trolls;
double distance;

distance = rate * time;
count = count + 2;

int count = 0, limit = 10, fudge_factor = 2;
double distance = 999.99;

int count(0), limit(10), fudge_factor(2);
double distance(999.99);

cout << number_of_bars << " candy bars\n";
// same thing as the above
cout << number_of_bars;
cout << " candy bars\n";
cout << "The total cost is $" << (price + tax);

cout << number_of_bars << " candy bars\n";
cout << one_weight << " ounces each\n";
// same thing 
cout << number_of_bars << " candy bars\n" << one_weight << " ounces each\n";
// same thing
cout << number_of_bars << " candy bars\n"
     << one_weight << " ounces each\n";
     
cout << fist_number << " " << second_number
    
cout << "\n";
// same as 
cout << endl
// examples
cout << "Fuel efficiency is "
     << mpg << " miles per gallon\n";
cout << "You have definitely won\n"
     << "one of the following prizes:\n";
cout << "You entered " << number << endl     
cout << "You have difinitely won"<< endl
     << "one of the following prizes:"<< endl
     
// set how many digits after the decimal point
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

cin >> number_of_bars >> one_weight;
cin >> time_to_go
    >> points_needed;
    
cout << "Enter the cost per person: $";
cin >> cost_per_person;
    
// 2.3 the type Char
#include <iostream>
using namespace std;
int main()
{
    char symbol1,symbol2,symbol3;
    
    cout << "Enter two initials, without any periods:\n";
    cin >> symbol1>> symbol2;
    cout << "The two initials are:\n";
    cout << symbol1 << symbol2 << endl;
    cout << "Once more with a space:\n";
    symbol3 = ' ';
    cout << symbol1 << symbol3 << symbol2 << endl;
    cout << "Thats all.";
    return 0;
}

// 2.4 the string class
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string middle_name, pet_name;
    string alter_ego_name;
    cout << "Enter your middle name and the name of your pet.\n";
    cin >> middle_name;
    cin >> pet_name;
    
    alter_ego_name = pet_name + " " + middle_name;
    
    cout << "The name of your alter ego is ";
    cout << alter_ego_name << "." << endl;
    
    return 0;
}     

// 2.7 an if-else statement
// test case: 20.00-3=>600.00;10.00-41=>415.00
#include <iostream>

using namespace std;

int main()
{
    int hours;
    double gross_pay, rate;
    cout << "Enter the hourly rate of pay: $";
    cin >> rate;
    cout << "Enter the number of hours worked,\n"
         << "rounded to a whole number of hours: ";
    cin >> hours;
    if (hours > 40)
        gross_pay = rate * 40 + 1.5 * rate * (hours - 40);
    else 
        gross_pay = rate * hours;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Hours = " << hours<< endl;
    cout << "Hourly pay rate = $" << rate << endl;
    cout << "Gross pay = $" << gross_pay << endl;
    return 0;
}

// 2.10 compound statements used with if-else
if (my_score > your_score)
{
    cout << "I win!\n";
    wager = wager + 50;
}
else
{
    cout << "I wish these were golf scores.\n";
    wager = 0;
}

// 2.14 a do-while loop
#include <iostream>
using namespace std;
int main()
{
    char ans;
    
    do 
    {
        cout << "Hello\n";
        cout << "Do you want another greetings?\n"
             << " Press y for yes, n for no,\n"
             << "and then press return: ";
        cin >> ans;
    } 
    // in do-while loop, ; after while() is so important! 
    while (ans == 'y' || ans == 'Y');
    cout << "Good-Bye\n";
    return 0;
}

// 2.15 charge card program
#include <iostream>
using namespace std;
int main()
{
    double balance = 50.00;
    int count = 0;
    cout << "This is program tells you how long it takes\n"
         << "to accumulate a debt of $100, starting with\n"
         << "an initial balance of $50 owed.\n"
         << "The interest rate is 2% per month.\n";
    while(balance < 100.00)
    {
        balance = balance + 0.02 ^ balance;
        count ++;
    }
    cout << "After " << count << " months,\n";
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Your balance due will be $" << balance<< endl;
    
    return 0;
}