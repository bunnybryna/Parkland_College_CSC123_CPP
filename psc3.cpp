// 3.4 the importance of braces
// test case: 01; 0.5
// 0.1 no difference;0.5 fuel over 3/4 will run
#include <iostream>
using namespace std;
int main()
{
    double fuel_gauge_reading;
    
    cout << "Enter fuel gauge reading: ";
    cin >> fuel_gauge_reading;
    
    cout << "First with braces:\n";
    if (fuel_gauge_reading < 0.75)
    {
        if (fuel_gauge_reading <0.25)
            cout << "Fuel very low. Caution!\n";
    }
    else
    {
        cout << "Fuel over 3/4. Don't stop now!\n";
    }
    // the compiler will always pairs an else with the nearest previous if
    // instead of if 0.75(if 0.25) and else, it will run if 0.75 (if 0.25 and else)
    cout << "Now without braces:\n";
    if (fuel_gauge_reading < 0.75)
        if (fuel_gauge_reading < 0.25)
            cout << "Fuel very low. Caution!\n";
    else
        cout << "Fuel over 3/4. Don't stop now!\n" ;
    
    return 0;
}

// 3.5 multiway if-else statement
// test case: 251000
#include <iostream>
using namespace std;
// no tax on income up to $150,000
// 5% on income between $15,001 and $25,000
// 10% on income over $25,000
int main()
{
    int net_income;
    double tax_bill;
    double five_tax,ten_tax;
    
    cout << "Enter net income (rounded to whole dollars)$";
    cin >> net_income;
    
    if (net_income <= 15000)
        tax_bill = 0;
    else if (net_income > 15000 && net_income <= 25000)
        tax_bill = 0.05 * (net_income-15000);
    else
    {
        five_tax = 0.05 * 10000;
        ten_tax = 0.10 * (net_income-25000);
        tax_bill = five_tax + ten_tax;
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Next income = $" << net_income << endl
         << "Tax bill = $ " << tax_bill << endl;
         
    return 0;
} 

// 3.6 a switch statement
#include <iostream>
using namespace std;
int main()
{
    char grade;
    cout << "Enter youro midterm grade and press Return:";
    cin >> grade;
    
    switch(grade)
    {
        case 'A':
            cout << "Excellent."
                 << "You need not take the final.\n";
                 // if you forget break; 
                 //program will go on to also execute the next case
                 break;
        case 'B':
             cout << "Very good.";
             grade = 'A';
             cout << "Your midterm grade is now " << grade << endl;
             break;
        case 'C':
             cout << "Passing.\n";
             break;
        // you can have two case labels for the same section of code
        case 'D':
        case 'F':
             cout << "Not good."
                  << "Go study.\n";
             break;
        default:
             cout << "That is not a possible grade.\n";
    }
    cout << "End of program.\n";
    return 0;
}

// 3.7 a menu
#include <iostream>
using namespace std;

int main()
{
    int choice;
    
    do 
    {
        cout << endl
             << "Choose 1 to see the next homework assignment.\n"
             << "Choose 2 for your grade the last assignment.\n"
             << "Choose 3 for assignment hints.\n"
             << "Choose 4 to exit this program.\n"
             << "Enter your choice and press Return:";
        cin >> choice;
        switch(choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                cout << "Not a valide choice.\n"
                     << "Choose again!\n";
        }
    // don't forget the semicolon after while()!    
    } while (choice !=4);
    
    return 0;
}

// 3.8 block with a locla variable
#include <iostream>
using namespace std;
int main()
{
    const double TAX_RATE = 0.05;
    char sale_type;
    int number;
    double price,total;
    
    cout << "Enter price $";
    cin >> price;
    cout << "Enter number purchased:";
    cin >> number;
    cout << "Type W if this is a wholesale purchase.\n"
         << "Type R if this is a retail purchase.\n"
         << "Then press Return.\n";
    cin >> sale_type;
    
    if (sale_type == 'W' || sale_type == 'w')
    {
        total = price * number;
    }    
    else if (sale_type == 'R' || sale_type == 'r')
    {
        double subtotal;
        subtotal = price * number;
        total = subtotal + subtotal * TAX_RATE;
    }    
    else
    {
        cout << "Error in input.\n";
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << number << " items at $ " << price << endl;
    cout << "Total Bill = $" << total;
    if (sale_type == 'R' || sale_type == 'r')
        cout << " including sales tax.\n";
    
    return 0;
}

// increment and decrement
// number ++, incrementing is done after the value is returned 
// ++ number, incrementing is done before the value is returned
int number = 2;
int value_produced = 2 * (++number);
//print 6 and 3
cout << value_produced << endl;
cout << value << endl;
// print 4 and 3
int number = 2;
int value_produced = 2 * (number++);
cout << value_produced << endl;
cout << value << endl;

// 3.10 the increment operators as an expression
#include <iostream>
using namespace std;
int main()
{
    int number_of_items, count, calories_for_item, total_calories;
    cout << "How many items did you eat today? ";
    cin >> number_of_items;
    
    total_calories = 0;
    count = 1;
    cout << "Enter the number of calories in each the\n"
         << "number_of_items" << "items eaten:\n";
    while (count++ <= number_of_items)
    {
        cin >> calories_for_item;
        total_calories = total_calories + calories_for_item;
    }
    cout << "Total calories eaten today = "
         << total_calories << endl;
    return 0;
}

// 3.13
for (int number = 100;number >= 0; number--)
{
    cout << number
         << "bottles of beer on the self.\n";
    if (number > 0)
        cout << "Take one down and pass it around.\n";
}

// 3.14 a break statement in a loop
#include <iostream>
using namespace std;

int main()
{
    int number, sum = 0,count = 0;
    cout << "Enter 10 negative number:\n";
    // notice here is ++count not count++
    while (++count <= 10)
    {
        cin >> number;
        
        if (number >= 0)
        {
            cout << "Error: positive number"
                 << " or zero was entered as the\n"
                 << count << "th number! Input ends "
                 << "with the " << count << "th number.\n"
                 << count << "th number was not added in.\n";
            break;
        }
        sum = sum + number;
    }
    cout << sum << " is the sum of the first "
         << (count - 1 ) << " numbers.\n";
    return 0;     
} 

// 3.15 explicitly nested loop
#include <iostream>
using namespace std;

int main()
{
    cout << "This program tallies conservationist reports\n"
         << "on the green-necked vulture.\n"
         << "Each conservationist's report consists of\n"
         << "a list of numbers. Each number is the count of\n"
         << "the eggs observed in one "
         << "green-necked vulture nest.\n"
         << "This program then tallies"
         << "the total number of eggs.\n";
         
    int number_of_reports;
    cout << "How many conservationist reports are there?";
    cin >> number_of_reports;
    
    int grand_total = 0, subtotal, count;
    for (count = 1; count <= number_of_reports; count ++)
    {
        cout << endl<< "Enter the report of "
             << "conservationist number " << count << endl;
        cout << "Enter the number of eggs in each nest.\n"
             << "Place a nagative integer at the end of your list.\n";
        subtotal = 0;
        int next;
        cin >> next;
        while (next >= 0)
        {
            subtotal = subtotal + next;
            cin >> next;
        }
        cout << "Total egg count for conservationist number "
             << count << " is " << subtotal << endl;
             
        grand_total = grand_total + subtotal;
    }
    cout << endl << "Total egg count for all conservationist = "
         << grand_total << endl;
    return 0;
} 