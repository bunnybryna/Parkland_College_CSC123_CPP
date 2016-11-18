#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
 
using namespace std;
 
/// prototypes
void introduction();
void playGame();
void closing();
void initHorses(int &h1, int &h2, int &h3, int &h4);
void moveHorses(int roll, int &h1, int &h2, int &h3, int &h4);
void printWinner(int h1, int h2, int h3, int h4);
int rollDice();
bool winner(int h1, int h2, int h3, int h4);
void printHorses(int h1, int h2, int h3, int h4);
void pauseScreen();
void clearScreen();
void blankLines(int lines);
bool playAgain();
void printHorse(int h);
 
/// nasty globals
const int FINISHLINE=15;
 
int main()
{
    srand(time(0));
 
    introduction();
    do
    {
        playGame();
 
    } while ( playAgain() );
 
    closing();
 
    return 0;
}
 
/// welcome screen (get credit card #)
void introduction()
{
    cout << "Welcome to Horse Race" << endl;
    cout << "Version 0.000A" << endl;
    pauseScreen();
    clearScreen();
}
 
/// the main game loop
void playGame()
{
    int horse1, horse2, horse3, horse4;
    int diceRoll;
 
    initHorses(horse1, horse2, horse3, horse4);
    while ( !winner(horse1, horse2, horse3, horse4) )
    {
        diceRoll = rollDice();
        moveHorses(diceRoll, horse1, horse2, horse3, horse4);
        printHorses(horse1, horse2, horse3, horse4);
    }
    printWinner(horse1, horse2, horse3, horse4);
}
 
/// end of program stuff
void closing()
{
    cout  << "Thanks you for playing ... good bye";
}
 
/// put all the horses at the starting line
void initHorses(int &h1, int &h2, int &h3, int &h4)
{
    h1=0;
    h2=0;
    h3=0;
    h4=0;
}
 
/// move the horses
void moveHorses(int roll, int &h1, int &h2, int &h3, int &h4)
{
    if (roll == 1) h1++;
    if (roll == 2) h2++;
    if (roll == 3) h3++;
    if (roll == 4) h4++;
}
 
/// display the winner
void printWinner(int h1, int h2, int h3, int h4)
{
    if (h1 > FINISHLINE)
    {
        cout << "horse 1 won!";
    }
    if (h2 > FINISHLINE)
    {
        cout << "horse 2 won!";
    }
    if (h3 > FINISHLINE)
    {
        cout << "horse 3 won!";
    }
    if (h4 > FINISHLINE)
    {
        cout << "horse 4 won!";
    }
    blankLines(7+4);
}
 
/// roll the dice
int rollDice()
{
    int roll = rand() % 4 + 1;
    cout << "You rolled a " << roll << endl<<endl;
    return roll;
}
 
/// did a horse cross the finish line?
bool winner(int h1, int h2, int h3, int h4)
{
    if (h1 > FINISHLINE) return true;
    if (h2 > FINISHLINE) return true;
    if (h3 > FINISHLINE) return true;
    if (h4 > FINISHLINE) return true;
    return false;
}
 
/// show how the race is progressing
void printHorses(int h1, int h2, int h3, int h4)
{
    cout << "1: " << setw(3) << h1 ;
    printHorse(h1);
 
    cout << "2: " << setw(3) <<h2 ;
    printHorse(h2);
 
    cout << "3: " << setw(3) <<h3 ;
    printHorse(h3);
 
    cout << "4: " << setw(3) <<h4 ;
    printHorse(h4);
 
    blankLines(7);
    pauseScreen();
    clearScreen();
}
 
void pauseScreen()
{
    string inputBuffer;
    cout << "Press enter to continue:";
    getline(cin, inputBuffer);
}
 
void clearScreen()
{
 cout << "\n\n\n\n\n\n\n\n\n\n";
 cout << "\n\n\n\n\n\n\n\n\n\n";
}
 
void    blankLines(int lines)
{
    for (int i=0;i < lines; i++)
        cout << "\n";
}
 
/// ask if we wish to play again
bool playAgain()
{
    string inputBuffer;
    char ch;
    cout << "Play Again [y/n]?";
    getline(cin, inputBuffer);
    ch = inputBuffer[0];
    return tolower(ch) == 'y';
 
}
 
/// show one horse 'h' spaces across the screen
void printHorse(int h)
{
    /// skip 'h' spaces
    for (int i=0;i<h;i++)
        cout << "    ";
    /// print the horse
    cout << "~oo^";
    /// skip from h to finshline
    for (int i=h;i<FINISHLINE;i++)
        cout << "    ";
    /// print the finish line
    cout << "|";
 
    cout << endl;
}