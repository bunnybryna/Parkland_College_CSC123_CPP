
// string lab
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// functions go here
bool check(string wordToCheck);
int calculate(string wordToCal);

int main()
{
    char ans;
    do{
    string word;
    cout << "Welcome to Ken's word game!\n"
         << "How to score a point in this game?\n"
         << "Each letter has the following values:\n"
         << "A, E, I, M, Q, U, Y are worth 1 point;\n"
         << "B, F,  J, N, R, V, Z are worth 2 points;\n"
         << "C, G, K, O, S, W  are worth 3 points;\n"
         << "D, H, L, P, T, X are worth 5 points.\n"
         << "Any word that contains two (or more) of the same letter in a row has it's value doubled.\n"
         << "But you can only double things once.\n"
         << "Please type in a word (only lowercase) and I will calculate your score for you:)\n";
    getline(cin, word);
    cout << "The word you chosed is " << word << endl;
    cout << "First, let me check if it's a valid word.\n";
    bool result;
    result = check(word);
    if (result == false)
    {
        cout << "Sorry, it's not a valid word. \n"
             << "End of game!\n"
             << "----------------------------------------------------\n";
    }
    else
    {
        cout << "Yes, it's a valid word.\n";
        cout << "Then I'm going to calculate how many points you scored:\n";
        system("PAUSE");
        int total;
        total = calculate(word);
        cout << "Congratulations! Your total point is " << total << endl
             << "End of game!\n"
             << "----------------------------------------------------\n";
    }
    cout << "Would you like to play again?(y/n)\n";
    cin >> ans;
    cin.ignore();
    }while (ans == 'y');

    cout << "Thank you and goodbye!\n";
    return 0;
}

bool check(string wordToCheck)
{
    bool found = false;
    ifstream dictionary;
    dictionary.open("web2.txt");
    if (dictionary.fail())
        cout << "Can't open dictionary.\n";
    string next;
    while (!dictionary.eof() && (dictionary >> next))
    {
        if (next == wordToCheck)
        {
            found = true;
            dictionary.close();
            return found;
        }
        // because dictionary is sorted, when next>wordToCheck
        // there is no need to continue searching
        else if (next > wordToCheck)
        {
            dictionary.close();
            return found;
        }
    }
    system("PAUSE");
    dictionary.close();
    return found;
}

int calculate(string wordToCal)
{
    string point1("aeimquy"), point2("bfjnrvz"), point3("cgkosw"), point5("dhlptx");
    string str(wordToCal);
    int total=0;
    cout << wordToCal << " = (";
    for (int i=0;i<str.length();i++)
    {
        // check responding value for each letter
        string aChar = str.substr(i,1);
        if (point1.find(aChar) != string::npos)
        {
            total += 1;
            cout << "1 + ";
        }
        if (point2.find(aChar) != string::npos)
        {
            total += 2;
            cout << "2 + ";
        }
        if (point3.find(aChar) != string::npos)
        {
            total += 3;
            cout << "3 + ";
        }
        if (point5.find(aChar) != string::npos)
        {
            total += 5;
            cout << "5 + ";
        }
    }
    //check if 2 or more letters in a row
    cout << "0) * ";
    for (int i=0;i<str.length()-1;i++)
    {
        if (str.at(i) == str.at(i+1))
        {
            total *= 2;
            cout << "2 = " << total << endl;
            return total;
        }
    }
    cout << "1 = " << total << "( the last 0 is just for formatting )"<<endl;
    return total;
}
