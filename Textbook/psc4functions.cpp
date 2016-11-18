// 4.1 a funciton call
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double COST_PER_SQFT= 10.50;
    double budget, area, length_side;
    
    cout << "Enter the amount budgeted for your dog house$";
    cin >> budget;
    
    area = budget/COST_PER_SQFT;
    length_side = sqrt(area);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"For a price of $" << budget << endl
        << "I can build you a luxurious square dog house\n"
        << "this is "<< length_side
        << " feet on each side.\n";
        
    return 0;
}

// simulate rolling a six-sided die
int die= (rand() % 6) + 1; 
// convert from int to double
//static_cast<double>(express_of_type_int)
int total_pot, number_of_winners;
double your_winnings;
your_winnings=static_cast<double>(total_pot)/number_of_winners;

// 4.3 a function definition
#include <iostream>
using namespace std;

// funciton declaration
double total_cost(int number_par,double price_par);

int main()
{
    double price, bill;
    int number;
    
    cout << "Enter the number of items purchased: ";
    cin >> number;
    cout << "Enter the price per item $";
    cin >> price;
    
    // function call
    bill = total_cost(number,price);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << number << " items at $" << price << " each.\n"
         << "Final bill, including tax, is $ " << bill<< endl;

    return 0;
}

// function definition
// funciton header, no semicolon at the end
double total_cost(int number_par, double price_par)
{
    // function body
    const double TAX_RATE = 0.05;
    double subtotal;
    subtotal = price_par * number_par;
    return (subtotal + subtotal * TAX_RATE);
}

// functions that return a bool
if (appropriate(rate)){
    
}

bool appropriate(int rate)
{
    return ((rate >= 10) && (rate < 20) || (rate == 0));
}

// 4.5 incorrectly ordered arguments
#include <iostream>
using namespace std;

char grade(int received_par, int min_score_par);
// returns P for passing, F for failing
int main()
{
    int score, need_to_pass;
    char letter_grade;
    
    cout << "Enter your score and the minimum needed to pass ";
    cin >> score >> need_to_pass;
    
    // wrong ordered argument:letter_grade= grade(need_to_pass,score);
    letter_grade = grade(score,need_to_pass);
    
    cout << "You received a score of " << score << endl
         << "Minimum to pass is " << need_to_pass << endl;
         
    if (letter_grade == 'P')
        cout << "You passed. Congratulations!\n";
    else 
        cout << "Sorry. You failed.\n";
    cout << letter_grade
         << " will be entered in your record.\n";
    
    return 0;
}  

char grade(int received_par, int min_score_par)
{
    if (received_par >= min_score_par)
        return 'P';
    else
        return 'F';
}

//4.9 nicely nested loops
#include <iostream>
using namespace std;

int get_one_total();

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
             cout << endl << "Enter the report of "
                  << "conservationist number " << count << endl;
             subtotal = get_one_total();
             cout << "Total egg count for conservationist number"
                  << count << " is " << subtotal << endl;
             grand_total = grand_total + subtotal;
         }
         cout << endl << "Total egg count for all reports = " << grand_total << endl;
         
         return 0;
}

int get_one_total()
{
    int total;
    cout << "Enter the number of eggs in each nest.\n"
         << "Place a negative integer at the end of your list.\n";

    total = 0;
    int next;
    cin>> next;
    // notice no ; after while()
    while ( next >= 0)
    {
        total = total + next;
        cin >> next;
    }
    return total;
    
}

//4.10 buying pizza
#include <iostream>
using namespace std;

double unitprice(int diameter, double price);

int main()
{
    int diameter_small, diameter_large;
    double price_small, unitprice_small, price_large, unitprice_large;
    
    cout << "Welcome to the Pizza Consumer Union.\n";
    cout << "Enter diameter of a small pizza (in inches):";
    cin >> diameter_small;
    cout << "Enter the price of a small pizza: $";
    cin >> price_small;
    cout << "Eneter diameter of a large pizza (in inches):";
    cin >> diameter_large;
    cout << "Enter the price of a large pizza: $";
    cin >> price_large;
    
    unitprice_small = unitprice(diameter_small, price_small);
    unitprice_large = unitprice(diameter_large, price_large);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Small pizza:\n"
         << "Diameter = " << diameter_small << " inches\n"
         << "Price = $" << price_small
         << "Per square inch = $" << unitprice_small<< endl
         << "Large pizza:\n"
         << "Diameter = " << diameter_large << " inches\n"
         << "Price = $" << price_large
         << "Per square inch = $" << unitprice_large << endl;
    if (unitprice_large < unitprice_small)
        cout << "The large one is the better buy.\n";
    else
        cout << "The small one is the better buy.\n";
    
    cout << "Buon Appetito!\n";
    
    return 0;
}

double unitprice(int diameter, double price)
{
    const double PI = 3.14159;
    double radius, area;
    
    radius = diameter / static_cast<double>(2);
    area = PI * radius * radius;
    return (price/area);
}

// 4.11 local varaibles
#include <iostream>
using namespace std;

double est_total(int min_peas, int max_peas, int pot_count);

int main()
{
    int max_count, min_count, pod_count;
    double average_pea, yield;
    
    cout << "Enter minimum and maximum number of peas in a pod:";
    cin >> min_count >> max_count;
    cout << "Enter the number of pods:";
    cin >> pod_count;
    cout << "Enter the weight of an average pea(in ounces):";
    // this average_pea is local to the main part of the program
    cin >> average_pea;
    
    yield = est_total(min_count, max_count, pod_count) * average_pea;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << "Min number of peas per pod = " << min_count << endl
         << "Max number of peas per pod = " << max_count << endl
         << "Pod count = " << pod_count << endl
         << "Average pea weight = " << average_pea<< " ounces" << endl
         << "Estimated average yield = " << yield << " ounces" << endl;
         
    return 0;
            
}

double est_total(int min_peas, int max_peas, int pod_count)
{
    // this average_pea is locla to the function est_total
    double average_pea;
    average_pea = (max_peas + min_peas)/2.0;
    return (pod_count * average_pea);
}

// 4.12 a global named constant
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

double area(double radius);

double volume(double radius);

int main()
{
    double radius_of_both, area_of_circle, volume_of_sphere;
    
    cout << "Enter a radius ot use for bothe a circle and a sphere (in inches:)";
    cin >> radius_of_both;
    
    area_of_circle = area(radius_of_both);
    volume_of_sphere = volume(radius_of_both);
    
    cout << "Radius = " << radius_of_both << " inches\n"
         << "Area of circle = " << area_of_circle << " square inches\n"
         << "Volume of sphere = " << volume_of_sphere << " cubic inches\n";
         
    return 0;
}

double area(double radius)
{
    return (PI * pow(radius, 2));
}

double volume(double radius)
{
    return ((4.0/3.0) * PI * pow(radius, 3));
}

// 4.15 using namespace 
#include <iostream>
#include <cmath>

const double PI = 3.14159;

double area(double radius);

double volume(double radius);

int main()
{
    using namespace std;
    
    double radius_of_both, area_of_circle, volume_of_sphere;
    
    cout << "Enter a radius ot use for bothe a circle and a sphere (in inches:)";
    cin >> radius_of_both;
    
    area_of_circle = area(radius_of_both);
    volume_of_sphere = volume(radius_of_both);
    
    cout << "Radius = " << radius_of_both << " inches\n"
         << "Area of circle = " << area_of_circle << " square inches\n"
         << "Volume of sphere = " << volume_of_sphere << " cubic inches\n";
         
    return 0;
}

double area(double radius)
{
    // place using namespace std; inside {}
    // then using directive applies to only this function definitions
    using namespace std;
    
    return (PI * pow(radius, 2));
}

double volume(double radius)
{
    using namespace std;
    
    return ((4.0/3.0) * PI * pow(radius, 3));
}

// 4.17 overlading a funciton name
#include <iostream>

double ave(double n1, double n2);

double ave(double n1, double n2, double n3);

int main()
{
    using namespace std;
    // the compiler will check the number and types of the arguments
    // to determine which definition applies 
    cout << "The average of 2.0, 2.5, and 3.0 is "
         << ave ( 2.0, 2.5, 3.0) << endl;
    cout << "The average of 4.5 and 5.5 is "
         << ave ( 4.5, 5.5) << endl;
    
    return 0;
}

double ave(double n1, double n2)
{
    return ((n1+n2)/2.0);
}
double ave(double n1, double n2, double n3)
{
    return ((n1+n2+n3)/3.0);
}

//4.18 overloading a function name
#include <iostream>

double unitprice(int diameter, double price);
double unitprice(int length, int width, double price);

int main()
{
    using namespace std;
    int diameter, length, width;
    double price_round, unitprice_round, price_rec, unitprice_rec;
    
    cout << "Welcome to the Pizza Consumer Union.\n";
    cout << "Enter the diameter in inches of a round pizza:";
    cin >> diameter;
    cout << "Enter the price of a round pizza: $";
    cin >> price_round;
    cout << "Eneter length and width in inches of a rectangular pizza:";
    cin >> length>> width;
    cout << "Enter the price of a rectangular pizza: $";
    cin >> price_rec;
    
    unitprice_round = unitprice(diameter, price_round);
    unitprice_rec = unitprice(length, width, price_rec);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Round pizza:\n"
         << "Diameter = " << diameter << " inches\n"
         << "Price = $" << price_round
         << "Per square inch = $" << unitprice_round<< endl
         << "Rectangular pizza:\n"
         << "Length = " << length << " inches\n"
         << "Width = " << width << " inches\n"
         << "Price = $" << price_rec
         << "Per square inch = $" << unitprice_rec << endl;
    if (unitprice_round < unitprice_rec)
        cout << "The round one is the better buy.\n";
    else
        cout << "The rectangular one is the better buy.\n";
    
    cout << "Buon Appetito!\n";
    
    return 0;
}

double unitprice(int diameter, double price)
{
    const double PI = 3.14159;
    double radius, area;
    
    radius = diameter / static_cast<double>(2);
    area = PI * radius * radius;
    return (price/area);
}

double unitprice(int length, int width, double price)
{
    double area = length * width;
    return (price/area);
}
