#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;

class Card{
public:
    void setRank(int r);
    int getRank();
    void setSuit(int s);
    int getSuit();
    void print();
    string toString();
private:
    int myRank;
    int mySuit;
};

void newDeck(vector<Card> &vectorDeck);
void printDeck(vector<Card> vectorDeck);
void printLine();
bool myCompare(Card c1, Card c2);
void evaluate(vector<Card> vectorHand);

int main()
{
    vector<Card> deck;
    cout << "Let's play poker! I will shuffle the deck, then show you a hand and evaluate the hand for you."<< endl;
    // 1. create a standard deck
    newDeck(deck);
    // 2. print the deck
    printDeck(deck);
    system("PAUSE");
    printLine();
    // 3. shuffle the deck and print again
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
    cout << "After shuffled, " << endl;
    printDeck(deck);
    // 4. create a hand (copy to a new vector)
    vector<Card> hand;
    for (int i=0;i<5;i++)
        hand.push_back(deck[i]);
    printDeck(hand);
    // 5. sort the hand
    sort(hand.begin(),hand.end(), myCompare);
    cout << "After sorted, " << endl;
    printDeck(hand);
    // 5. evaluate the hand
    evaluate(hand);

    return 0;
}

void Card::setRank(int r)
{
    myRank = r;
}

int Card::getRank()
{
    return myRank;
}

void Card::setSuit(int s)
{
    mySuit = s;
}

int Card::getSuit()
{
    return mySuit;
}

void Card::print()
{
    cout << setw(20)<< toString();
}

string Card::toString()
{
    string sString, rString, cardString;
    if (mySuit == 1)
        sString = "Spade";
    else if (mySuit == 2)
        sString = "Heart";
    else if (mySuit == 3)
        sString = "Club";
    else
        sString = "Diamond";
    if (myRank <= 10 && myRank >= 2)
    {
        //convert intergers to strings
        stringstream convert;
        convert << myRank;
        rString = convert.str();
    }
    else if (myRank == 11)
        rString = "J";
    else if (myRank == 12)
        rString = "Q";
    else if (myRank == 13)
        rString = "K";
    else
        rString = "A";
    cardString = sString + " " + rString;
    return cardString;
}

void newDeck(vector<Card> &vectorDeck)
{
    for (int i=0;i<13;i++)
    {
        Card c;
        c.setSuit(1);
        int r;
        r = i+2;
        c.setRank(r);
        vectorDeck.push_back(c);
    }
    for (int i=0;i<13;i++)
    {
        Card c;
        c.setSuit(2);
        int r;
        r = i+2;
        c.setRank(r);
        vectorDeck.push_back(c);
    }
    for (int i=0;i<13;i++)
    {
        Card c;
        c.setSuit(3);
        int r;
        r = i+2;
        c.setRank(r);
        vectorDeck.push_back(c);
    }
    for (int i=0;i<13;i++)
    {
        Card c;
        c.setSuit(4);
        int r;
        r = i+2;
        c.setRank(r);
        vectorDeck.push_back(c);
    }
}

void printDeck(vector<Card> vectorDeck)
{
    cout << "This deck is " << endl;
    for (int i=0;i<vectorDeck.size();i++)
    {
        vectorDeck[i].print();
    }
    cout << endl;
}

void printLine()
{
    cout << "----------------------------------------------------------------------"<< endl;
}

bool myCompare(Card c1, Card c2)
{
    if (c1.getRank() != c2.getRank())
        return (c1.getRank() < c2.getRank());
    else
        return (c1.getSuit() < c2.getSuit());
}

void evaluate(vector<Card> vectorHand)
{
    Card c1, c2, c3, c4, c5;
    c1 = vectorHand[0];
    c2 = vectorHand[1];
    c3 = vectorHand[2];
    c4 = vectorHand[3];
    c5 = vectorHand[4];
    // check one-pair
    if ((c1.getRank() == c2.getRank()) ||
        (c2.getRank() == c3.getRank()) ||
        (c3.getRank() == c4.getRank()) ||
        (c4.getRank() == c5.getRank()))
        {
         // check three-of-a-kind
        if ((c1.getRank() == c3.getRank())||
            (c2.getRank() == c4.getRank()) ||
            (c3.getRank() == c5.getRank()))
        {
            // check four-of-a-kind
            if ((c1.getRank() == c4.getRank())||
                (c2.getRank() == c5.getRank()))
                {
                    cout << "There is a four-of-a-kind in this hand." << endl;
                }
            // check full-house
            else if ((c1.getRank() == c2.getRank() &&
                    c1.getRank() != c3.getRank() &&
                    c3.getRank() == c4.getRank() &&
                    c4.getRank() == c5.getRank()) ||
                   (c1.getRank() == c2.getRank() &&
                    c2.getRank() == c3.getRank() &&
                    c3.getRank() != c4.getRank() &&
                    c4.getRank() == c5.getRank()))
            cout << "There is a full-house in this hand." << endl;
            else
            {
                cout << "There is a three-of-a-kind in this hand." << endl;
            }
        }
         // check two-pair
        else if (((c1.getRank() == c2.getRank())&&
        ((c3.getRank() == c4.getRank()) ||
        (c3.getRank() == c5.getRank()) ||
        (c4.getRank() == c5.getRank()))) ||
        ((c2.getRank() == c3.getRank()) &&
        (c4.getRank() == c5.getRank())))
        {
            cout << "There is a two-pair in this hand." << endl;
        }
        else
        {
            cout << "There is one pair in this hand." << endl;
        }
        }
    if((c1.getRank() == c2.getRank()-1) &&
            (c2.getRank() == c3.getRank()-1) &&
            (c3.getRank() == c4.getRank()-1) &&
            (c4.getRank() == c5.getRank()-1))
        cout << "There is a straight in this hand." << endl;
    if ((c1.getSuit() == c2.getSuit()) &&
        (c2.getSuit() == c3.getSuit()) &&
        (c3.getSuit() == c4.getSuit()) &&
        (c4.getSuit() == c5.getSuit()))
        {
            if (c1.getSuit() == 1)
                cout << "There is a Spade flush in this hand." << endl;
            else if (c1.getSuit() == 2)
                cout << "There is a Heart flush in this hand." << endl;
            else if (c1.getSuit() == 3)
                cout << "There is a Club flush in this hand." << endl;
            else
                cout << "There is a Diamond flush in this hand." << endl;
        }

}
