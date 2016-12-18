//Write a function that returns the average of an array of integers.  The function returns an int and is passed an array of ints and it's size as an int.
#include <iostream>
using namespace std;

int ave(int array[], int size);

int main()
{
    int arr[6] = {0,1,2,3,4};
    int av = ave(arr, 5);
    cout << av << endl;
    return 0;
}
int ave(int array[], int size)
{
    int sum = 0;
    int count = 0;
    for (int i=0;i<size;i++)
    {
        sum += array[i];
        count = i+1 ;
        cout << sum << count;
    }
    return (sum/count);
}

//Write a function that returns the average of a file that contains one integer per line.  The function returns as int and is passed a string which contains the filename.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int aveFile(string infileName);
int main()
{
    string infileName;
    cout << "Enter a file name to open:";
    getline(cin, infileName);
    aveFile(infileName);

    return 0;
}

int aveFile(string infileName)
{

    ifstream infile;
    infile.open(infileName.c_str());
    if(infile.fail())
    {
        cout << "File not found." << endl;
        exit(1);
    }
    else{
        int next;
        int sum = 0;
        int count = 0;
        while((!infile.eof())&&(infile >> next))
        {
            cout << next << " ";
            sum += next;
            count ++;
        }
        cout << "sum = " << sum << " count = " << count << endl;
        cout << "average = " << (sum/count) << endl;
        infile.close();
        cout << "File closed."<< endl;
        return (sum/count);
    }
}

//Write a function that counts the number of occurrences of a specific character in a string.  The function returns as int and is passed a string which is searched and a char which is searched for.

#include <iostream>
#include <string>
using namespace std;
int count(string aString, char aChar);
int main()
{
    string theString;
    char theChar;
    cout << "Enter a string :" << endl;
    getline(cin, theString);
    cout << "Enter a char :" << endl;
    cin.get(theChar);
    int howMany = count(theString, theChar);
    cout << "There are " << howMany << " " << theChar << "s in the " << theString << endl;
    return 0;
}
int count(string aString, char aChar)
{
    int count = 0;
    for (int i=0;i<aString.length();i++)
    {
        if(aString[i] == aChar)
        count ++;
    }
    return count;
}

//Create a two dimension array that can be used as a target based on a number that is passed as a parameter (up to 100) ... here's the number 5 
#include <iostream>
using namespace std;
typedef int* IntArrayPtr;
int main()
{
    int d;
    cout << "Enter the row/column of the array:" << endl;
    cin >> d;
    
    
 
}

if n==1
vector<int> myArray[1][1]=1;

if n>1;
array[n-1]
myArray.insert(myArray.begin(),n);
myArray.pushback(n);
array[m][n]=array


//Write a function that determines if there are three of the same value in a row in an array.  The function returns a bool and is passed an array of ints and it's size as an int.
#include <iostream>
using namespace std;

bool three(int array[], int size);
int main()
{
    int arr[6]={0,1,2,1,2};
    bool answer = three(arr,5);
    if (answer)
        cout << "Yes, there are three same values in a row in this array." << endl;
    else
        cout << "No, there aren't.";
    return 0;
}
bool three(int array[], int size)
{
    for (int i=1; i<size-1; i++)
    {
        if((array[i-1]==array[i])&&(array[i]==array[i+1]))
            return true;
    }
    return false;
}


//Write a function that determines if there are three of the same line in a row in a file.  The function returns a bool and is passed a string which contains the filename.
// 0,1,2,3,4,5,5,5 turns false, cause n3 cann't read the last digit... 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
bool threeLines(string infileName);
int main()
{
    string infileName;
    cout << "Enter a file name to open:";
    getline(cin, infileName);
    bool answer = threeLines(infileName);
    if (answer)
        cout << "Yes, there are three same lines in a row in this file." << endl;
    else
        cout << "No, there aren't.";

    return 0;
}

bool threeLines(string infileName)
{

    ifstream infile;
    infile.open(infileName.c_str());
    if(infile.fail())
    {
        cout << "File not found." << endl;
        exit(1);
    }
    else{
        int n1, n2, n3;
        while((!infile.eof())&&(infile >> n1)&&(infile>>n2) && (infile >> n3))
        {
            cout << n1 << endl << n2 << endl << n3;
            if ((n1 == n2) && (n2== n3))
            return true;      
        }
        
        return false;
    }
}

//better way
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
bool threeLines(string infileName);
int main()
{
    string infileName;
    cout << "Enter a file name to open:";
    getline(cin, infileName);
    bool answer = threeLines(infileName);
    if (answer)
        cout << "Yes, there are three same lines in a row in this file." << endl;
    else
        cout << "No, there aren't.";

    return 0;
}

bool threeLines(string infileName)
{

    ifstream infile;
    infile.open(infileName.c_str());
    if(infile.fail())
    {
        cout << "File not found." << endl;
        exit(1);
    }
    else{
        string n1, n2, n3;
        while(!infile.eof())
        //while((!infile.eof())&&((infile >> n1)&&(infile>>n2)&&(infile >> n3)))
        {
            getline(infile,n1);
            cout << "n1 " << n1 << endl;
            getline(infile,n2);
            cout << "n2 " << n2 << endl;
            getline(infile,n3);
            cout << "n3 " << n3 << endl;
            if ((n1 == n2) && (n2== n3))
                return true;
        }

        return false;
    }
}


//Write a function that determines if there are two words that are the same in a row in a string. The function returns a bool and is passed a string.
#include <iostream>
#include <string>
using namespace std;
bool same(string aString);
int main()
{
    string stringTest;
    cout << "Enter a string for test:" << endl;
    getline(cin,stringTest);
    bool answer = same(stringTest);
    if (answer)
        cout << "Yes, there are two same words in a row in this string." << endl;
    else
        cout << "No, there aren't."<<endl;
    return 0;
}

bool same(string aString)
{
    for (int i=0;i<aString.length();i++)
    {
        for (int j=i+1; j<aString.length();j++)
        {
            if (aString[i]==aString[j])
            {
                cout << "i " << i << " j " << j << endl;
                if (aString.substr(i,(j-i))==aString.substr(j,(j-i)))
                {
                    cout << "same part " << aString.substr(i,(j-i)) << endl;
                    return true;
                }
            }
        }
    }
    return false;
}
