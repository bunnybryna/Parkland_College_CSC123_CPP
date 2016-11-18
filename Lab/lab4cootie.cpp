#include <iostream>
// to use srand() and rand()
#include <cstdlib>
#include <ctime>

using namespace std;

// function declaration
void intro();
int rollDice();
void assemble(int diceNum, int& bodyNum, int& headNum, int& antNum, int& wingNum, int& stNum, int& legNum, int& eyeNum );

// main program
int main()
{
    int dice;
    string answer;

    // function intro() gives the rule of how to play the game
    intro();

    // put the srand()out of the loop
    srand(time(0));

    while (true)
    {
        // initialize count and numbers at the beginning of the outer loop means
        // in each iteration of the outer loop(every new round)they are 0
        int bodyNum=0, headNum=0 ,antNum=0, wingNum=0, stNum=0, legNum=0,eyeNum=0;
        int count=0;
        // no need to check bodyNum and headNum, cause they are the prerequisites
        while (antNum != 2 || wingNum != 2 || stNum != 1 || legNum != 4 || eyeNum != 6)
        {
        dice = rollDice();
        assemble(dice, bodyNum, headNum, antNum, wingNum, stNum, legNum, eyeNum);
        count ++;
        }
        cout << "Your cootie was completed in " << count << " dice rolls.\n";
        cout << "Do you want to play again[y/n]\n";
        cin >> answer;
        if (answer == "y")
            continue;
        else
            break;
    }
    cout << "Buy! Have a nice day!\n";

    return 0;
}
// function definition
// 1 function intro() return nothing just print out introduction of the game to the screen
void intro()
{
    cout<< "Hi there, let's play the Game of Cootie!\n"
        << "Here is the rule:\n";
    cout<< "You must roll dice to assemble your cootie bug.\n"
        << "Each number represents a different part of the cootie:\n";
    cout<< "1 = Body(max 1, required part: none)\n"
        << "2 = Head(max 1, required part: Body)\n"
        << "3 = Antenna(max 2, required part: Head)\n"
        << "4 = Wings(max 2, required part: Body)\n"
        << "5 = Stinger(max 1, required part: Body)\n"
        << "6 = Legs(max 4, required part: Body)\n"
        << "7 = Eyes(max 6, required part: Head)\n"
        << endl << endl<< "Now let's rock and roll!\n" << endl << endl;
}

// 2 function rollDice() return a random number between 1-7
int rollDice()
{
    int randD;
    randD = rand()%7+1;

    return randD;
}

// 3 function assemble() assembles the cootie depending on what number the dice is
// returns nothing, but print out the procedure to the screen
void assemble(int diceNum, int& bodyNum, int& headNum, int& antNum, int& wingNum, int& stNum, int& legNum, int& eyeNum )
{

    if (diceNum == 1 )
    {
        cout << "Dice roll is a 1\n";
        if (bodyNum < 1)
        {
            bodyNum ++;
            cout << "Yeah, you can add the body!\n";
        }
        else
        {
            cout << "Sorry, You already have a body :(\n";
        }
    }
    else if (diceNum == 2)
    {
        cout << "Dice roll is a 2\n";
        if (bodyNum == 1 && headNum < 1)
        {
            headNum ++;
            cout << "Yeah, you can add the head!\n";
        }
        else if (bodyNum < 1)
        {
            cout << "Sorry, no body, can't add a head.\n";
        }
        else
        {
            cout << "Sorry, you already have a head :(\n";
        }
    }
    else if (diceNum == 3)
    {
        cout << "Dice roll is a 3\n";
        if (headNum == 1 && antNum < 2)
        {
            antNum ++;
            cout << "Yeah, you can add an antenna!\n";
        }
        else if (headNum < 1)
        {
            cout << "Sorry, no head, can't add an antenna.\n";
        }
        else
        {
            cout << "Sorry, you already have two antennas :(\n";
        }
    }
    else if (diceNum == 4)
    {
        cout << "Dice roll is a 4\n";
        if (bodyNum == 1 && wingNum < 2)
        {
            wingNum ++;
            cout << "Yeah, you can add a wing!\n";
        }
        else if (bodyNum < 1)
        {
            cout << "Sorry, no body, can't add a wing.\n";
        }
        else
        {
            cout << "Sorry, you already have two wings :(\n";
        }
    }
    else if (diceNum == 5)
    {
        cout << "Dice roll is a 5\n";
        if (bodyNum == 1 && stNum < 1)
        {
            stNum ++;
            cout << "Yeah, you can add the stinger!\n";
        }
        else if (bodyNum < 1)
        {
            cout << "Sorry, no body, can't add a stinger.\n";
        }
        else
        {
            cout << "Sorry, you already have a stinger :(\n";
        }
    }
    else if (diceNum == 6)
    {
        cout << "Dice roll is a 6\n";
        if (bodyNum == 1 && legNum < 4)
        {
            legNum ++;
            cout << "Yeah, you can add a leg!\n";
        }
        else if (bodyNum < 1)
        {
            cout << "Sorry, no body, can't add a leg.\n";
        }
        else
        {
            cout << "Sorry, you already have four legs :(\n";
        }
    }
    else if (diceNum == 7)
    {
        cout << "Dice roll is a 7\n";
        if (headNum == 1 && eyeNum < 6)
        {
            eyeNum ++;
            cout << "Yeah, you can add an eye!\n";
        }
        else if (headNum < 1)
        {
            cout << "Sorry, no head, can't add an eye.\n";
        }
        else
        {
            cout << "Sorry, you already have six eyes :(\n";
        }
    }
    else
    {
        cout << "Wrong dice number!";
    }
    cout << "Cootie so far " << bodyNum << " body, " << headNum << " head, "
         << antNum << " antennas, " << wingNum << " wings, " << stNum << " stingers, "
         << legNum << " legs, " << eyeNum << " eyes " << endl << endl;
}
