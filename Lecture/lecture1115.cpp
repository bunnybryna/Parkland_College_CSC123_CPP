char name[10];
char another_name[]="Bryna";
// name="Bryna" doesn't work
strcpy(name,"Bryna");
// strcpy(to, from) (buffer overflow) will lose the null marker
// strncpy(to,from, maxsize) will keep the null market, but lose some info in the middle
// * is a pointer
void strcpy(char *s1, char *s2)
// substr() chops up a string
// strtok searches for characters in a string

// tombstones, innitializes to empty spaces

// 2d arrays
int table[5][4];
table[3][2]=19;
for (row=0;row<5;row++)
{
    for(col=0;col<4;col++)
    {
        cout << table[row][col];
    }
}    

// STL,standard template library, containers
// vector is a container that stores info like an array
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int main()
{
    vector<int> numbers;
    cout << "The vector has " << numbers.size() << " elements." << endl;
    numbers.push_back(45);
    numbers.push_back(39);
    cout << "The vector has " << numbers.size() << " elements." << endl;

    // does not add just change values
    numbers[1] = 20;
    for(int i=0;i<numbers.size();i++)
    {
        cout << numbers[i] << endl;
    
    // numbers.max_size() gives the max capacity
    cout << "The vector has hold " << numbers.capacity() << " elements." << endl;
    
    string name;
    name="Bryna Zhao";
    // same thing can do to strings
    cout << "The vector has hold " << name.capacity() << " elements." << endl;    
    cout << "The first 'e' is at " << name.find('e') << endl; 
    
    return 0;
}


#include <iostream>
#include <string>
using namespace std;


int main()
{
    string sentence, word;
    cout << "Enter a sentence:"<< endl;
    getline(cin, sentence);

    int pos = 0;
    // substr(position, length)
    while ((pos = sentence.find(' ')) != string::npos)
    {
        word = sentence.substr(0,pos);
        sentence = sentence.substr(pos+1);
        cout << "word:" << word << endl;
    }
    cout << "word:" << sentence<< endl;
    return 0;
}

// STL, containers, iterators, ...
// <algorithm>,put numbers in order
sort(numbers.begin(), numbers.end());