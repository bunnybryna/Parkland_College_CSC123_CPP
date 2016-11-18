// user defined function
#include <cstdlib>
#include <iostream>

using namespace std;
int add2num(int num1, int num2);

int main()
{
	int returnVal;
	returnVal = add2num(12,20);
	cout << "The sum of 12 and 20 is " << returnVal << endl;
	returnVal = add2num(13,2);
	cout << "The sum of 13 and 2 is " << returnVal << endl;	
	returnVal = add2num(-4,42);
	cout << "The sum of -4 and 42 is " << returnVal << endl;

	return 0;
}

int add2num(int num1, int num2)
{
	return (num1 + num2);
}


// void function
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

void skipTwoLines();
void prettyPrint(int num);

int main(int argc, char * argv[])
{
	int i;
	for (i=5;i>0;i--)
	{
		prettyPrint(i);
		skipTwoLines();
	}
	
	system("PAUSE");
	return EXIT_SUCCESS;
	
}

void skipTwoLines()
{
	cout<<endl<< endl;
}

void prettyPrint(int num)
{
	cout << "***********" << endl;
	cout << "*         *" << endl;
		// setw(7) forces the width of the next item to be 7 spaces
	cout << "* " << setw(7) << num << " *"<< endl;
	cout << "*         *" << endl;
	cout << "***********" << endl;
}

// 
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void setSevenIncorrect(int parm);
int setSevenCorrect();

int main()
{
	int parm = 1;
	cout << "Parm starts at "<< parm << endl;
	setSevenIncorrect(parm);
	cout << "After the incorrect call parm is now " << parm << endl;
	parm = setSevenCorrect();
	cout << "After the correct all parm is now " << parm << endl;
	
	return 0;
}

void setSevenIncorrect(int parm)
{
	parm = 7;
}

int setSevenCorrect()
{
	return 7;
}

// 100bottlesof beer
#include <iostream>
using namespace std;

void printVerse(int bottles);
string getPlural(int bottles);

int main()
{
	int bottles;
	cout << "In main, bottles is stored at "<< &bottles << endl;
	
	for (bottles = 2; bottles >0; bottles--)
	{
		printVerse(bottles);
	}
	return 0;
}
// a funciton call another function
void printVerse(int bottles)
{
	cout << "In printVerse, bottles is stored at " << &bottles << endl;
	cout << bottles << " bottle" << getPlural(bottles) << " of beer on the wall " << endl
		 << bottles << " bottle" << getPlural(bottles) << " of beer." << endl
		 << "If one of those bottles should happen to fall; " << endl
		 << bottles -1 << " bottle " << getPlural(bottles-1) << " of beer on the wall." << endl << endl;
}

string getPlural(int bottles)
{
	cout << "In getPlural, bottles is stored at "<< &bottles << endl;
	if (bottles == 1)
		return "";
	else
		return "s";
}

#include <iostream>

using namespace std;

void printMyName();
void someFnverCall();
string addSuffix(string name);

int main()
{
	int i;
	string myName = "Bryna";
	string newName;
	// print Bryna Zhao here
	printMyName();
	cout << "---";
	newName = addSuffix(myName);
	// print Bryna Jr. here
	cout << newName << endl;
	cout << "---";

	myName = addSuffix(myName);
	myName = addSuffix(myName);
	myName = addSuffix(myName);

	cout << "---";
	// print Bryna Jr. Jr. Jr. here
	cout << myName << endl;
	cout << i << endl;
	cout << "---";

	return 0;
}

void printMyName()
{
	int i;
	i = 15;
	cout << "Bryna Zhao" << endl;
	return ;
}

string addSuffix(string name)
{
	string returnVal;
	returnVal = name + "Jr.";
	return returnVal;
}

// Here's a program that uses lots of functions.
#include <cstdlib> // needed for srand() and rand()
#include <iostream>
#include <ctime> // needed for time()


using namespace std;

// prototypes

void introduction();
int firstRoll();
void restOfRolls(int);
int rollDice();
void checkForWin(int);
void checkForLoss(int);

int main(int argc, char *argv[])
{
    srand(time(0));
    int point;

    introduction();
    point = firstRoll();
    restOfRolls(point);

    return 0;
}


void introduction() {
    cout << "Craps version 0.01a" << endl;
}

int firstRoll() {
    int diceRoll;
    // cout << "The First Roll" << endl;
    diceRoll = rollDice();
    checkForWin(diceRoll);
    checkForLoss(diceRoll);
    return diceRoll;
}


void restOfRolls(int point) {
    // cout << "The rest of the rolls" << endl;
    int diceRoll;

    do {
        diceRoll = rollDice();

        if (diceRoll == point) {
            cout << "Winner!!!:" << endl;
            exit(0);
        }
        else if (diceRoll == 7) {
            cout << "Loser!!!:" << endl;
            exit(0);
        }
    } while (1);

}

int rollDice() {
    // cout << "Rolling Dice" << endl;
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    cout << "Total is :" << die1 + die2 << endl;
    return die1 + die2;
}

void checkForWin(int diceRoll) {
    // cout << "Checking for win" << endl;
    if (diceRoll ==7 || diceRoll == 11) {
        cout << "Winner!!!:" << endl;
        system("PAUSE");
        exit(1);
    }
}

void checkForLoss(int diceRoll) {
    //cout << "Checking for loss" << endl;
    if (diceRoll == 2 || diceRoll == 3 || diceRoll == 12) {
        cout << "Loser!!!:" << endl;
        system("PAUSE");
        exit(1);
    }
}

