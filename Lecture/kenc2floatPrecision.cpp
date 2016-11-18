#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //float number1 = .1;
    double number1 = .1;
    //float number2 = .1;
    double number2 = .1;
    
    number1 /= 10.0;
    //cout << "Number 1 is " << number1 << endl;
    cout << "Number 1 is now" << setprecision(10) << number1 << endl;
    number1 /= 10.0;
    //cout << "Number 1 is " << number1 << endl;
    cout << "Number 1 is now" << setprecision(10) << number1 << endl;
    number1 /= 10.0;
    //cout << "Number 1 is " << number1 << endl;
    cout << "Number 1 is now" << setprecision(10) << number1 << endl;
    number1 *= 10.0;
    //cout << "Number 1 is " << number1 << endl;
    cout << "Number 1 is now" << setprecision(10) << number1 << endl;
    number1 *= 10.0;
    //cout << "Number 1 is " << number1 << endl;
    cout << "Number 1 is now" << setprecision(10) << number1 << endl;
    number1 *= 10.0;
    //cout << "Number 1 is " << number1 << endl;
    // because number1 is rounding the answer number1 won't equal to number2
    // you can look at more previse version of the number by setting precision
    // number1 is 0.09999999404, how about using double
    cout << "Number 1 is now" << setprecision(10) << number1 << endl;
    
    if (number1 == number2){
        cout << "Your numbers are the same";
    }
    if (number1 != number2){
        cout << "Your numbers are different";
    }
    return 0;
}