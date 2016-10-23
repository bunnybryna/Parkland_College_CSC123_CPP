// revised version:changed the condition statements for testing short straight
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int num1, num2, num3, num4, num5;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
    // initialize ans to "No" at the beginning, only change to "Yes" when the condition is met
    string ansThree="No", ansFour="No", ansFive="No", ansFull="No", ansLS="No", ansSS="No";

    cout << "Enter first number: \n";
    cin >> num1;

    switch(num1)
    {
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 5:
            count5++;
            break;
        case 6:
            count6++;
            break;
        // using default to make sure num1 is an integer between 1 and 6
        default:
            cout << "Invalid input! Exit the program.";
            exit(1);
    }
    // same procedure for num2 and so on
    cout << "Enter second number: \n";
    cin >> num2;
    switch(num2)
    {
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 5:
            count5++;
            break;
        case 6:
            count6++;
            break;
        default:
            cout << "Invalid input! Exit the program.";
            exit(1);
    }
    cout << "Enter third number: \n";
    cin >> num3;
    switch(num3)
    {
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 5:
            count5++;
            break;
        case 6:
            count6++;
            break;
        default:
            cout << "Invalid input! Exit the program.";
            exit(1);
    }
    cout << "Enter fourth number: \n";
    cin >> num4;
    switch(num4)
    {
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 5:
            count5++;
            break;
        case 6:
            count6++;
            break;
        default:
            cout << "Invalid input! Exit the program.";
            exit(1);
    }
    cout << "Enter fifth number: \n";
    cin >> num5;
    switch(num5)
    {
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 5:
            count5++;
            break;
        case 6:
            count6++;
            break;
        default:
            cout << "Invalid input! Exit the program.";
            exit(1);
    }
    // print out the count for all dice numbers
    cout << "There are " << count1 << " ones.\n";
    cout << "There are " << count2 << " twos.\n";
    cout << "There are " << count3 << " threes.\n";
    cout << "There are " << count4 << " fours.\n";
    cout << "There are " << count5 << " fives.\n";
    cout << "There are " << count6 << " sixes.\n";

    // first nested loop is to answer 3/4/5 of a kind and full house question
    // fist check base case: three of a kind
    if (count1 >= 3 ||
        count2 >= 3 ||
        count3 >= 3 ||
        count4 >= 3 ||
        count5 >= 3 ||
        count6 >= 3)
    {
        ansThree = "Yes";
        // 3+2=> full house
        if (count1 == 2||
            count2 == 2||
            count3 == 2||
            count4 == 2||
            count5 == 2||
            count6 == 2)
        {
            // full house=>no chance to have four/five of a kind
            ansFull = "Yes";
        }
        // not full house then check four of a kind
        else
        {
            // three of a kind && not fullhouse =>four of a kind
            if (count1 >= 4 ||
                count2 >= 4 ||
                count3 >= 4 ||
                count4 >= 4 ||
                count5 >= 4 ||
                count6 >= 4)
            {
                ansFour = "Yes";
                // four of a kind => five of a kind
                if (count1 >= 5 ||
                    count2 >= 5 ||
                    count3 >= 5 ||
                    count4 >= 5 ||
                    count5 >= 5 ||
                    count6 >= 5)
                {
                    ansFive = "Yes";
                }
            }
        }
    }
    // no three of a kind, then no chance to have full house or four/five of a kind


    // second nested loop is to answer long straight and short straight question
    // if you want 12345,23456;1234,2345,3456, one 3 and one 4 are necessary
    if (count3 >= 1 && count4 >= 1)
    {
        // small short needs at least1234,2345,3456 three scenarios
        // count can be 2, ex:11234,12343...
        if ((count1 >=1 && count2 >= 1 )||
            (count2 >=1 && count5 >= 1 )||
            (count5 >=1 && count6 >= 1 ))
        {
            ansSS = "Yes";
            // long short 12345,23456 two scenarios
            if ((count1 == 1 && count2 == 1 && count5 == 1 )||
                (count2 == 1 && count5 == 1 && count6 == 1))
            {
                ansLS = "Yes";
            }
        }
    }

    cout << ansThree << " three of a kind\n";
    cout << ansFour << " four of a kind\n";
    cout << ansFive << " five of a kind\n";
    cout << ansFull << " full house\n";
    cout << ansLS << " long straight\n";
    cout << ansSS << " short straight\n";
    return 0;
}
