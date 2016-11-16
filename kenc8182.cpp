// c++ strings
// a C++ string can be used as an array
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shuffle(string& str);

int main()
{
    string s;
    srand(time(0));
    cout << "Enter a string:";
    getline(cin,s);
    
    for (int i=0;i<s.size();i++)
    {
        cout << "Position " << i << " contains the character " << s[i] << endl;
    }
    shuffle(s);
    
    cout << "The shuffled string is: " << s << endl;
    
    return 0;
}

void shuffle(string& str)
{
    int randomPos;
    char temp;
    for (int i=0;i<str.size();i++)
    {
        randomPos = rand() %str.size();
        temp = str[i];
        str[i] = str[randomPos];
        str[randomPos] = temp;
        
    }
}

// size and length function
#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter a string:";
    getline(cin,s);
    
    cout << "The string you typed in has a size of " << s.size() << endl;
    cout << "The string you typed in has a size of " << s.length() << endl;
    
    return 0;
}

// inserting strings into other strings
#include <iostream>

using namespace std;
void shuffle(string& str);
int main()
{
    string nout;
    string verb;
    string sentence="The .";
    
    int times;
    cout << "Enter a noun:";
    getline(cin,nout);
    cout << "Enter a verb:";
    getline(cin,verb);
    
    sentence.insert(4,noun);
    sentence.insert(sentence.size()-1," ");
    sentence.insert(sentence.size()-1, verb);
    
    cout << sentence << endl;
    
    return 0;
}

//appending c++ strings two ways
#include <iostream>
using namespace std;
void shuffle(string& str);
int main()
{
    string s;
    string cop1="";
    string cop2="";
    int times;

    cout << "Enter a string:";
    getline(cin,s);
     // repeat s how many times
    cout << "Enter a number:";
    cin >> times;

    for (int i=0;i<times;i++)
    {
        cop1 += s;
    }

    for (int i=0;i<times;i++)
    {
        cop2.append(s);
    }

    cout << cop1 << endl;
    cout << cop2 << endl;

    return 0;
}

// uppercase and lowercase
// will return true or false
bool isupper(char c)
bool islower(char c)
// will return the uppper/lower conversion of the char c
char toupper(char c)
char tolower(char c)
// isdigit(), isalnum(),isalpha()

string stringToUpper(string strToConvert)
{
    for (unsigned int i=0;i<strToConvert.leng();i++)
    {
        strToConvert[i] = toupper(strToConvert[i]);
    }
    return strToConvert;
}

// C++ string method erase()
//string.erase(begin, span); default erase all 
#include <iostream>
using namespace std;

int main()
{
    string sentence = "Now is the time for all good men to come to the aid of their party.";
    cout << sentence << endl;
    // erase the word 'good' including the space after it
    sentence.erase(24, 5);
    cout << sentence << endl;
    // delete the last word and space, not including the period
    sentence.erase(sentence.size()-7,6);
    cout << sentence << endl;

    string example = "01234567";
    example.erase(1,2);
    cout << example;
    
    return 0;
}

//search for strings in a string
#include <iostream>
using namespace std;

int main()
{
    string sentence="Now is the time for all good men to come to the aid of their party.";
    cout << sentence << endl;
    cout << "The word 'time' is at position " << sentence.find("time") << endl;
    cout << "The word 'bus' is at position " << sentence.find("bus")<< endl;
    // string::npos, means until the end of the string, indicate no matches
    if (sentence.find("bus") == string::npos)
    {
        cout << "The word bus was not found." << endl;
    }
    
    return 0;
}

// string::npos
#include <iostream>
using namespace std;
int main()
{
    string str;
    int pos;
    cout << "Type in a string:";
    getline(cin,str);
    cout << "You typed in " << str << endl;
    while ((pos = str.find_first_of("aeiou"))!= string::npos)
    {
        str.erase(pos,1);
    }
    
    cout << "After removing all vowel, you have:" << str << endl;
    
    while((pos = str.find(" "))!= string::npos)
    {
        str.erase(pos,1);
    }
    
    cout << "After removing all spaces, you have:" << str << endl;
    
    return 0;
}

// C++ string method find_first_of
#include <iostream>
using namespace std;
int main()
{
    string sentence = "Now is the time for all good men to come to the aid of their party.";
    cout << sentence<< endl;
    
    cout << "The first vowel is at the position " << sentence.find_first_of("aeiou") << endl;
    cout << "The last vowel is at the position " << sentence.find_last_of("aeiou") << endl;
    cout << "The first consonant is at position " << sentence.find_first_not_of("aeiou") << endl;
    cout << "The last consonant is at position " << sentence.find_last_not_of("aeiou") << endl;
    
    //not found
    cout << "The letter of 'Z' or 'Y' is at position " << sentence.find_first_of("ZY") << endl;
    
    if (sentence.find_first_of("ZY") == string:: npos)
    {
        cout << "The sentence contains no capital Z or Y." << endl;
    }
}

// convert from C++ style string to an integer
// a handwritten version of atoi
#include <iostream>
#include <cstdlib>

using namespace std;

int getIntVal(string strConvert);
int myAtoi(const char cstring[]);

int main()
{
    string str;
    int i;

    do{
        cout << "Enter a string:";
        cin >> str;
        cout << "Your string is [" << str << "]" << endl;
        i = getIntVal(str);
        cout << "Adding 1 to your string is " << i+1 << endl;

    } while(1);

    return 0;
}

int getIntVal(string strConvert)
{
    int intReturn;
    // c_str()Returns a null-terminated c-string representing the current value of the string object
    intReturn = myAtoi(strConvert.c_str());

    return (intReturn);
}

//result = result * 10 + ( num[i] - '0' ) is how to do convert
int myAtoi(const char cstring[])
{
    int returnVal = 0;
    int pos = 0;
    // cstring[]="123", pos=0,returnVal=0,1;pos=1,rV=10,12;pos=2,rV=120,123;
    while (cstring[pos] != 0)
    {
        returnVal *= 10;
        // c=arrayA-arrayB, c holds the difference between two locations of arrayA and arrayB
        // returnVal holds the difference between pos(convert from ASCII) and '0'
        // if just use int(cstring[1]) will equal to 49, because in ASCII chart, '1'=49
        // but '1'-'0'= 1, so char number-'0' is a way to convert char number to real integer
        returnVal += cstring[pos] - '0';
        pos ++;
    }
    return returnVal;
}


// a handwritten version of strlen
#include <iostream>
#include <cstring>

using namespace std;
int myStrLen(char array[]);
int main()
{
    char name[40];
    cout << "Ener your name: ";
    cin.getline(name, 40);
    cout << name << endl;
    cout << "The name is " << myStrLen(name) << " characters long. The null isn't counted" << endl;
    return 0;
}

int myStrLen(char array[])
{
    int len = 0;
    // null is zero, so array['\0'] will turn false
    while(array[len])
    {
        len ++;
    }
    return len;
}

// converting c strings and c++ strings
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char name[40];
    string copyOfName;
    char anotherCopy[40];
    cout << "Enter your name: ";
    cin.getline(name,40);
    cout << name << endl;
    // you can directly store a c string into a c++ string
    copyOfName = name;
    cout << copyOfName << endl;
    // but anotherCopy = name won't work, you have to use strcpy()
    // strcpy(anotherCopy, name) will work
    // strcpy has to be used on c-strings, so converting copyOfName to c-string is necessary
    strcpy(anotherCopy, copyOfName.c_str());
    cout << anotherCopy << endl;
    
    return 0;
}

// copying c-strings
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char name[40];
    char copyOfName[40];
    
    cout << "Enter your name:";
    cin.getline(name,40);
    cout << name << endl;
    strcpy(copyOfName, name);
    cout << copyOfName << endl;
    
    return 0;
}

// c-strings are nul terminated character arrays
#include <iostream>
using namespace std;
int main()
{
    char name[] = "Bryna Zhao";
    cout << name << endl;
    for (int i=0;i<11;i++)
    {
        cout << "Postion " << i << " has a value of " << name[i]
             << " or as a number " << static_cast<int>(name[i]) << endl;
    }
    cout << "Notice the ascii value of the last one is 0, which means null." << endl;
    
    return 0;
}

// c-string handwritten version of strcpy
#include <iostream>
#include <cstring>

using namespace std;

void myStrcpy(char from[], char to[]);
int main()
{
    char name[40];
    char copyOfName[40];
    
    cout << "Enter your name:";
    cin.getline(name,40);
    
    cout << name << endl;
    myStrcpy(copyOfName, name);
    
    cout << copyOfName << endl;
    
    return 0;
}

void myStrcpy(char to[], char from[])
{
    int pos = 0;
    while(from[pos])
    {
        to[pos] = from[pos];
        pos ++;       
    }
    // put the null at the endl;
    to[pos] = '\0';
}
