
// built in functions
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double parameter;
    double returnValue;
    
    cout << "Enter a decimal number I will return the "<< endl
         << "Square root:";
    cin >> parameter;
    
    returnValue = sqrt(parameter);
    
    cout << "The square root of "<< parameter << " is "
         << returnValue;
         
    return 0;
}

//type casting
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int parameter;
    double returnValue;
    
    cout << "Enter a decimal number I will return the " << endl
         << " sqaure root:";
         
    cin >> parameter;
    
    returnValue = sqrt(static_cast<double>(parameter));
    
    cout << "The square root of " << parameter << " is "
         << returnValue;
    system("PAUSE");
    return 0;
}

// srand()
// bad code
for (int i=0; i<1000; i++){
    srand((unsigned)time(0))
    cout << rand();
    
}

// good code
// the pseudo-random number generator should only be seeded once
// before any calls to rand(), and the start of the program
// It should not be repeatedly seeded or reseeded every time you wish to generate a new batch of pseudo-random numbers
srand((unsigned)time(0));
for (int i=0;i<1000;i++){
    cout << rand();
}

//an example of srand() and rand()
//https://www.youtube.com/watch?v=PZZUJ1fxG04
#include <cstdlib>
#include <iostream>
#include <ctime>
 
int main() 
{
    std::srand(std::time(0)); //use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
}

//rand() example
#include <iostream>
#include <cstdlib>
// for time()
#include <ctime>
// for setw()
#include <iomanip>

using namespace std;
int main()
{
	int i;
	srand(time(0));
	for (i=0;i<15;i++)
	{
		cout << rand() << " ";
	}
	cout << endl << endl;

	// flip a coin
	for (i=0;i<20;i++)
	{
		if (rand()%2==0)
		{
			cout << "HEADS ";
		}
		else
		{
			cout << "TAILS ";
		}
	}
	cout << endl << endl;

	// roll a dice
	for (i=0;i<20;i++)
	{
		cout << rand()%6+1 << " ";
	}
	cout << endl << endl;

	// pick a random year in parkland's history 1966-2016
	for (i=0;i<20;i++)
	{
		cout << rand()%51 + 1966 << " ";
	}
	cout << endl << endl;

	// roll 2 six dice and add them
	for (i=0;i<20;i++)
	{
		cout << rand()%6+1+rand()%6+1 << " ";
	}
	cout << endl << endl;

	// roll a d20
	int d20roll;
	for (i=0;i<20;i++)
	{
		d20roll = rand()%20 + 1;
		cout << d20roll << " ";
		if (d20roll == 20)
		{
			cout << "CRIT";
		}
	}
		cout << endl << endl;

	// % of time, event1 15%,event2 20%,event4 5%
	int randP;
	for (i=0;i<20;i++)
	{
		randP = rand()%100;
		if (randP < 15)
		{
			cout << "event1 ";
		}
		else if (randP < (15+20))
		{
			cout << "event2 ";
		}
		else if (randP < (15+20+5))
		{
			cout << "event3 ";
		}
		else
		{
			cout << "nothing ";
		}
    }
	cout << endl << endl;


	// using setw
	for (i=0;i<20;i++)
	{
		cout << setw(10)<<rand();
	}
	cout << endl << endl;

	return 0;
}