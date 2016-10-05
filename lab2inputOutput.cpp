// lab2 input/output
#include <iostream>
using namespace std;
int main()
{
    string adj1, noun1, adj2, body, madeUp, adj3, adj4;
    string food, name, city, state, adj5, noun2, space;
    cout << "Hey, my name is Bryna. Let's play a game!\n"
         << "Please answer 13 questions,\n"
         << "and I will write you a great story!\n"
         << "First, please tell me the first adjective that pops into your head: \n";
    cin >> adj1;
    cout << "Then please tell me a plural noun(whatever it is): \n";
    cin >> noun1;
    cout << "Another adjective please: \n";
    cin >> adj2;
    cout << "What's your favorite body part: \n";
    cin >> body;
    cout << "Make up a funny word for me: \n";
    cin >> madeUp;
    cout << "Please give me a different adjective: \n";
    cin >> adj3;
    cout << "Another adjective please: \n";
    cin >> adj4;
    cout << "What is your least favorite food: \n";
    cin >> food;
    cout << "Your nick name(no space): \n";
    cin >> name;
    cout << "In which city your were born: \n";
    cin >> city;
    cout << "And state: \n";
    cin >> state;
    cout << "Almost there, give me the last adjective: \n";
    cin >> adj5;
    cout << "And last, a singular noun please: \n";
    cin >> noun2;
    cout << endl << endl << endl;
    cout << "Ready? Go!\n"
         << "Type 'y' to read the story\n";
    cin >> space;
    if (space == "y")
    {
        cout << "Are you bothered by "<< adj1 << " " << noun1 << "?\n"
            << "Do you feel " << adj2 << " every day?\n"
            << "Does your "<< body << " hurt?\n"
            << "Then " << madeUp << " is for you!\n"
            << "This "<< adj3 << " " << adj4 << " treat is chock-full of " << food << endl;
        cout << "Here is what " << name << " of " << city << ", " << state << " had to say about "<< madeUp << ". "
             << "I start every day with " << madeUp << ". It's simply " << adj5 << "! Even my " << noun2 << " loves it.\n";
        cout << endl;
        cout << "Don't delay! Buy " << madeUp << " today!\n";
    }
    else
        cout << "Are you sure? Bye-bye!\n";
    return 0;
}
