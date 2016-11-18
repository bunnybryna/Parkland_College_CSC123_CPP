// 1
#include <iostream>
using namespace std;

void setToValue(double& before, double after);

int main()
{
 double weight, height, pi, avagadrosNumber;

// here are some possible calls to the function you need to write
 setToValue(height, 65.7);
 setToValue(weight, 210);
 setToValue(pi, 3.14156);
 setToValue(avagadrosNumber, 6.02e-23);

// here's the code that tests the above calls
 cout << "This should be 65.7 --> " << height << endl;
 cout << "This should be 210 --> " << weight << endl;
 cout << "This should be 3.14156 --> " << pi << endl;
 cout << "This should be 6.02e-23--> " << avagadrosNumber << endl;
}

void setToValue(double& before, double after)
{
    before = after;
}


//2
/*Write a function called countGenerator( ... ) that will work with the following section of code.
It will take a string parameter and return an integer accord to the following rules:
If the string passed to it is exactly "Red", the function will return a random number from 1 to 4.
If the string passed to it is exactly "Blue", the function will return a random number from 1 to 6.
If the string passed to it is exactly "Green", the function will return a random number from 1 to 8.
If the string passed to it is anything else, the function will return a 0 (zero).*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int countGenerator(string color);

int main()
{
  // seed the random number generator
  srand(time(0));

  // test "Red" parameter
  cout << "I will now print 20 numbers from 1 to 4:" << endl;
  for (int i=0;i<20;i++)
  {
    cout << countGenerator("Red") << " ";
  }
  cout << endl;

  // test "Blue" parameter
  cout << "I will now print 20 numbers from 1 to 6:" << endl;
  for (int i=0;i<20;i++)
  {
    cout << countGenerator("Blue") << " ";
  }
  cout << endl;

  // test "Green" parameter
  cout << "I will now print 20 numbers from 1 to 8:" << endl;
  for (int i=0;i<20;i++)
  {
    cout << countGenerator("Green") << " ";
  }
  cout << endl;

  // test the returning a zero if the name isn't valid
  cout << "I will now print 5 zeros:" << endl;
  cout << countGenerator("green") << " ";
  cout << countGenerator("red") << " ";
  cout << countGenerator("blue") << " ";
  cout << countGenerator("BLUE") << " ";
  cout << countGenerator("") << " ";
  cout << endl;
}

 int countGenerator(string color)
 {
     int num; 
     if (color == "Red")
     {
        num = rand()% 3 + 1;         
     }    
     else if (color == "Blue")
     {
        num = rand()%5 + 1; 
     }
     else if (color == "Green")
     {
         num = rand()%7 + 1;
     }
     else
         num = 0;
     
     return num;
 }
 
 // 3
 /*Write a function called divisors( ... ) that will work with the following section of code.
It will take three integer parameters and return nothing.
The first pararmeter is the number we are looking for divisors of.
The second parameter is where to start looking
The third parameter is where to stop looking.  This number is included in the checking for divisors!
It will print a list of all the divisors of the first number that are between the second and third parameter. (Include those parameters in the check.)
Print the numbers out with a single space between them.  
If there are no divisors, nothing will be printed.
The third parameter will always be greater than the second parameter, so you can check from low to high numbers.
You can use the % operator to determine if one number is a divisor of another. 
Something is a divisor when there is a remainder or zero when they are divided.
You don't need to put in the prototype*/

#include <iostream>
using namespace std;

void divisors(int numD, int numS, int numE);

int main()
{
 cout << "Divisors of 12 from 1 to 10 ";
 cout << "(should be 1 2 3 4 6)";
 divisors(12, 1, 10);
 cout << endl;

 cout << "Divisors of 24 from 6 to 12 ";
 cout << "(should be 6 8 12)";
 divisors(24, 6, 12);
 cout << endl;

 cout << "Divisors of 100 from 26 to 49 ";
 cout << "(nothing should be printed )";
 divisors(100, 26, 49);
 cout << endl;
}

void divisors(int numD, int numS, int numE)
{
    int i;
    for ( i = numS; i <= numE; i++)
    {
        if (numD % i == 0)
        {
            cout << i << " ";
        }
    }
}