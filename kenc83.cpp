// vector front(), back() and pop_back()
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numberList;
    numberList.push_back(20);
    numberList.push_back(30);
    numberList.push_back(40);
    numberList.push_back(10);    
    
    cout << "The first element on the list is " << numberList.front() << endl;
    cout << "The last element on the list is " << numberList.back() << endl;
    // pop_back removes the last one from the list
    numberList.pop_back();
    
    cout << "numberList has " << numberList.size() << " elements!" << endl;

    for (int i=0;i<numberList.size();i++)
    {
        cout << "numberList position " << i << " has the value " << numberList.at(i) << endl;
    }
    return 0;
}

// vector constructors
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // create an empty vector of integers 
    vector<int> numberList;
    cout << "numberList has " << numberList.size() << " elements!" << endl;
    // create a vector with 20 empty strings
    vector<string> nameList(20);
    cout << "nameList has " << nameList.size() << " elements!" << endl;
    // create a vector with 100 copies of pi
    vector<double> piList(100,3.1415);
    cout << "piList has " << piList.size() << " elements!" << endl;
    for (int i=0;i<piList.size();i++)
    {
        cout << piList.at(i) << " ";
    }
    return 0;
}

// using vector as an array
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void printList(vector<string> list);
void addWords(vector<string>& list);

int main()
{
    vector<string> wordList(10,"empty");
    // cout << wordList[10] << endl;
    printList(wordList);
    addWords(wordList);
    printList(wordList);

    return 0;
}

void printList(vector<string> list)
{
    int i;
    for (i=0;i<list.size();i++)
    {
        cout << setw(3) << i << " )" << list[i] << endl;
    }
}

void addWords(vector<string>& list)
{
    int i;
    for (i=0;i<list.size();i++)
    {
        cout << "Enter word " << i+1 << " of " << list.size() << ":";
        getline(cin,list[i]);
    }
}


// version 2 of using a vector as an array
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
void printList(vector<string> list);
void addOneWord(vector<string>& list);
int main()
{
    vector<string> wordList;
    while(1)
    {
        addOneWord(wordList);
        sort(wordList.begin(),wordList.end());
        // random_shuffle and sort are functions of algorithm
        random_shuffle(wordList.begin(),wordList.end());
        printList(wordList);
    }
    return 0;
}

void printList(vector<string> list)
{
    int i;
    for (i=0;i<list.size();i++)
    {
        cout << setw(3) << i << " )" << list[i] << endl;
    }
}

void addOneWord(vector<string>& list)
{
    string word;
    cout << "Enter word: ";
    getline(cin,word);
    list.push_back(word);
}