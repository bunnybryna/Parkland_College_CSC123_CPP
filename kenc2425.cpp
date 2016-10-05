// booleen, 0 is false, non-zero is true
#include <iostream>

using namespace std;

int main()
{
    cout << "3+4 is " << 3+4 << endl;
    cout << "3-4 is " << 3-4 << endl;
    cout << "3<4 is " << (3<4) << endl;
    // 3<=4 is 1 
    cout << "3<=4 is " << (3<=4) << endl;
    cout << "3>4 is " << (3>4) << endl;
    cout << "3>=4 is " << (3>=4) << endl;
    cout << "3!=4 is " << (3!=4) << endl;
    // 3==4 is 0
    cout << "3==4 is " << (3==4) << endl;
}

// floating and precision
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


// equal sign
#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
    int number1, number2;
    
    cout << "Enter an integer:";
    cin >> number1;
    cout << "Enter another integer:";
    cin >> number2;
    // note here should use == instead of =
    // number 2 = 1,0,-1
    // when number2=1,if (number1 = number2)=>if number1 = 1, the value of number1=1 is 1=> if true
    // when number2=0=>if 0=>if false
    if (number1 == number2) 
    {
        cout << "They are the same!" << endl;
    }
    
    return 0;
}

// leaving out the {}
#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Enter an integer grade and I'll tell all sorts\n"
         << "of stuff about it: Make sure to try a number\n"
         << "that is bigger than 45: ";
    cin >> number;
    

    if (number > 34)
        cout << "1. Your number is GREATER THAN 34\n";
    else if (number < 34)
        cout << "2. Your number is LESSER THAN 34\n";
    else
        cout << "3. Your number is 34.\n";
    return 0;
}