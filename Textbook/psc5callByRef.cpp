// 5.2 void functions
#include <iostream>

void initialize_screen();
double celsius(double fahrenheit);
void show_results(double f_degrees, double c_degrees);

int main()
{
    using namespace std;
    double f_temperature, c_temperature;
    
    initialize_screen();
    cout << "I will convert a Fahrenheit temperature to Celsius.\n"
         << "Enter a temperature in Fahrenheit: ";
    cin >> f_temperature;
    
    c_temperature = celsius(f_temperature);
    
    show_results(f_temperature,c_temperature);
    
    return 0;
}

void initialize_screen()
{
    using namespace std;
    cout << endl;
    // this return is optional
    return ;
}

double celsius(double fahrenheit)
{
    return (5.0/9.0)*(fahrenheit-32);
}

void show_results(double f_degrees, double c_degrees)
{
    using namespace std;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << f_degrees << " degrees Fahrenheit is equivalent to "
         << c_degrees << " degrees Celsius.\n";
    return ;     
}

// 5.3 use of return in a void functions
void ice_cream_div(int number, double total_weight);

void ice_cream_div(int number, double total_weight)
{
    using namespace std;
    double portion;
    
    if (number == 0)
        return ;
    portion = total_weight/number;
    cout.setf(ios::fixed);
    cout.set(ios::showpoint);
    cout.precision(2);
    cout << "Each one receives " << portion << " ounces of ice cream." << endl;
}

// 5.4 call-by-reference parameters
#include <iostream>

// with &, the parameters are not given values but given the memory locations associated with the name
// so call-by-reference parameters can change later
// when function exits, the local variables gone, but those parameters can continue 
void get_numbers(int& input1, int& input2);
void swap_values(int& variable1, int& variable2);
void show_results(int output1, int output2);

int main()
{
    int first_num = 0, second_num = 0;
    
    get_numbers(first_num, second_num);
    swap_values(first_num, second_num);
    show_results(first_num, second_num);
    
    return 0;
}

void get_numbers(int& input1, int& input2)
{
    using namespace std;
    cout << "Enter two integers:";
    // 5, 10 => input1, input2=>memory location 1010, 1012=>first_num, second_num
    // when input1, input2 gone, first_num and second_num stay in the main scope
    cin >> input1 >> input2;
    
}

void swap_values(int& variable1, int& variable2)
{
    int temp;
    // variable1 = variable2;
    // variable2 = variable1; won't work
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

void show_results(int output1, int output2)
{
    using namespace std;
    cout << "In reverse order the numbers are:"
         << output1 << " " << output2 << endl;
}

// 5.6 comparing argument mechanism
#include <iostream>

void do_stuff(int par1_value, int& par2_ref);

int main()
{
    using namespace std;
    int n1,n2;
    
    n1 = 1;
    n2 = 2;
    do_stuff(n1,n2);
    cout << "n1 after function call = " << n1 << endl;
    cout << "n2 after function call = " << n2 << endl;
    
    return 0;
}

void do_stuff(int par1_value, int& par2_ref)
{
    using namespace std;
    par1_value = 111;
    cout << "par1_value in function call = " << par1_value << endl;
    par2_ref = 222;
    cout << "par2_ref in function call = " << par2_ref << endl;
    // after the function call, par1_value is 1, par2_ref is 222
    // because n1 is a local varialbe, any change of n1 has no effect outside the function body
    
    
}

// 5.8 function calling another function
#include <iostream>
void get_numbers(int& input1, int& input2);
void swap_values(int& variable1, int& variable2);
void order(int& n1, int& n2);
void show_results(int output1, int output2);

int main()
{
    int first_num, second_num;
    
    get_numbers(first_num, second_num);
    order(first_num, second_num);
    show_results(first_num, second_num);
    
    return 0;
}

void get_numbers(int& input1, int& input2)
{
    using namespace std;
    cout << "Enter two integers:";
    // 5, 10 => input1, input2=>memory location 1010, 1012=>first_num, second_num
    // when input1, input2 gone, first_num and second_num stay in the main scope
    cin >> input1 >> input2;
    
}

void swap_values(int& variable1, int& variable2)
{
    int temp;
    // variable1 = variable2;
    // variable2 = variable1; won't work
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

void order(int& n1, int& n2)
{
    if(n1>n2)
        swap_values(n1,n2);
}

void show_results(int output1, int output2)
{
    using namespace std;
    cout << "In reverse order the numbers are:"
         << output1 << " " << output2 << endl;
}

// 5.9 supermarket pricing
#include <iostream>

const double LOW_MARKUP = 0.05;
const double HIGH_MARKUP = 0.10;
const int THRESHOLD = 7;

void introduction();
void get_input(double& cost, int& turnover);
double price(double cost, int turnover);
void give_output(double cost, int turnover, double price);

int main()
{
    double wholesale_cost, retail_price;
    int shelf_time;
    introduction();
    get_input(wholesale_cost, shelf_time);
    retail_price = price(wholesale_cost, shelf_time);
    give_output(wholesale_cost, shelf_time, retail_price);
    
    return 0;
}

void introduction()
{
    using namespace std;
    cout << "This program determines the retail price for\n"
         << "an item at a Quick-Shop supermarket store.\n";
}

// note the vales change in the funciton, need call-by-reference parameters
void get_input(double& cost, int& turnover)
{
    using namespace std;
    cout << "Enter the wholesale cost of item: $";
    cin >> cost;
    cout << "Enter the expected number of days until sold: ";
    cin >> turnover;
}

// no change, using call-by-value 
void  give_output(double cost, int turnover, double price)
{
    using namespace std;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Wholesale cost = $" << cost << endl
         << "Expected time until sold = " << turnover << " days" << endl
         << "Retail price = $" << price << endl;
}

// no change
double price(double cost, int turnover)
{
    if (turnover <= THRESHOLD)
        return (cost + (LOW_MARKUP * cost));
    else
        return (cost + (HIGH_MARKUP * cost));
}

// 5.10 driver program
// allow you to retest the function on different arguments without returning the program
do {
    get_input(wholesale_cost, shelf_time);
    
    cout << "Wholesale cost is now $" << wholesale_cost << endl;
    cout << "Days until sold is now " << shelf_time << " days" << endl;
    
    cout << "Test again?" << "Type y for yes or n for no:";
    cin >> ans;
    cout << endl;
} while (ans == 'y' || ans == 'Y');

// 5.11 program with a stub
// price() function is a stub
double price(double cost, int turnover)
{
    return 9.99;
    // not correct, but good enough for testing
}