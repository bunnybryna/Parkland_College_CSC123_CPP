
// variables
#include <iostream>
using namespace std;
int main()
{
    int age = 23;
    cout << "You are " << age << " years old." << endl;
    
    int turnsLeft = 5;
    cout << "There are " << turnsLeft << " turns left." << endl;
    
    double distance = 45.2;
    cout << "The distance is " << distance << endl;
    
    double interestRate = 5.25;
    cout << "The interes rate is " << interestRate << "%" << endl;
    
    return 0;    
}

// new line endl vs \n
#include <iostream>
using namespace std;
int main()
{
    cout << "Now is the time for all good men to come "
         << "to the aid of their party. The quick brown "
         << "fox jumped over the lazy dog's tail. " << endl;
         
    cout << endl << endl << endl;
    
    cout << "Now is the time for all good men to come " << endl
         << "to the aid of their party. The quick brown " << endl
         << "fox jumped over the lazy dog's tial" << endl;
         
    cout << endl << endl << endl;     
    
    cout << "Now is the time for all good men to come " << endl;
    cout << "to the aid of their party. The quick brown " << endl;
    cout << "fox jumped over the lazy dog's tial" << endl;
    
    cout << endl << endl << endl;     
    
    cout << "Now is the time for all good men to come\n";
    cout << "to the aid of their party. The quick brown\n";
    cout << "fox jumped over the lazy dog's tial\n";
         
    return 0;     
}

// operations
#include <iostream>
using namespace std;
int main()
{
    int number = 12;
    
    cout << "Number starts out at " << number << endl;
    
    number += 7;
    number += 7;
    cout << "Number (after 2 instances of += 7) is now " << number << endl;
    
    number -= 5;
    cout << "Number (after -= 5) is now " << number << endl;
    
    number *= 4;
    cout << "Number (after *= 4) is now " << number << endl;
    
    number /= 2;
    cout << "Number (after /= 2) is now " << number << endl;

    return 0;
}


// strings, C++ has string type, don't have to include other library
#include <iostream>
using namespace std;
int main()
{
    int x;
    x = 67;
    cout << x + 7 << endl;
    
    // A string
    string firstName; 
    string lastName;
    string fullName;
    
    firstName = "Bryna";
    lastName = " Zhao";
    fullName = firstName + " " + lastName;
    cout << fullName << endl;
    return 0;
}

// concatenate 
string inputBuffer;
int number;
getline(cin,inputBuffer);
// concatenate string to integer
//http://www.cplusplus.com/reference/cstdlib/atoi/
number = atoi(inputBuffer.c_str());

string inputBuffer;
double percent;
getline(cin,inputBuffer);
// concatenate string to double
//http://www.cplusplus.com/reference/cstdlib/atof/
percent = atof(inputBuffer.c_str())


#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double tempF, tempC;
    string inputBuffer;

    // get the temperature (as a series of characters)
    cout << "Enter the temperature in fahrenheit:";
    getline(cin,inputBuffer);

    // convert to an integer
    tempF = atoi(inputBuffer.c_str());

    // check the conversion
    cout << "You entered " << tempF << " degrees F" << endl;

    // convert to celsius using
    // c = 5/9(f-32)
    tempC = 5.0 / 9.9 * (tempF - 32.0);

    // output the new tempC
    cout << "You got " << tempC << " degrees C" << endl;

    return 0;
 
}

// cin vs getline()
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string name, quest, favoriteColor;
    
    cout << "STOP!" << endl << endl;
    
    cout << "Who would cross the bridge of death must answer me" << endl
         << " these questions three, ere the other side he see." << endl;
    cout << "What is your name?";
    cin >> name;
    
    cout << "What is your quest?";
    cin >> quest;
    
    cout << "What is your favoriteColor?";
    cin >> favoriteColor;
    
    cout << "Right, off you go" << endl;
    
    // cin will read until it encounters a whitespace
    // if name you typed Bryna Zhao, name=Bryna,quest=Zhao
    // only color question will pop up
    cout << "For the record, the computer picked up:" << endl
         << "[" << name << "] for name, " << endl
         << "[" << quest << "] for quest, and" << endl
         << "[" << favoriteColor << "] for favoriteColor, "<< endl << endl;
         
    cout << "Notice that the cin only picks up one word at a time!" << endl;
    return 0;
}

// getline works for multiple words, instead of cin 
// getline won't be affected by whitespace and just take the whole line 
#include <iostream>
using namespace std;
int main(int argc, char * argv[])
{
    string name, quest, favoriteColor;
    
    cout << "STOP!" << endl << endl;
    
    cout << "Who would cross the bridge of death must answer me" << endl
         << "these questions three, ere the other side he see." << endl;
         
    // difference: cin can take int and str but getline only takes str
    // if you use both cin and getline(), cin will skip the next getline()
    // solution: only use getline(), and convert strings to other types 
    cout << "What is your name?";
    getline(cin,name);
    
    cout << "What is your quest?";
    getline(cin,quest);
    
    cout << "What is your favorite color?";
    getline(cin,favoriteColor);
    
    cout << "Right, off you go" << endl;
    
    cout << "For the record, the computer picked up:" << endl
         << "[" << name << "] for name, " << endl
         << "[" << quest << "] for quest, and" << endl
         << "[" << favoriteColor << "] for favoriteColor, "<< endl << endl;
         
    cout << "Notice that the cin only picks up one word at a time!" << endl;
    return 0;    
}
