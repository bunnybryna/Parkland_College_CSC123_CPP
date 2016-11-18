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