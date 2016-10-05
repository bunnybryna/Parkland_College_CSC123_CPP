#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
    int counter;
    cout << "Enter an integer and I'll start counting down:";
    cin >> counter;
    
    cout << "The counter is starting at " << counter << endl;
    
    counter --;
    cout << "The counter is now " << counter << endl;
    
    counter --;
    cout << "The counter is now " << counter << endl;
    
    counter --;
    cout << "The counter is now " << counter << endl;
    
    cout << "Now I'll start counting up: "<< endl << endl;
    
    counter ++;
    cout <<"The counter is now " << counter << endl;
    
    counter ++;
    cout << "The counter is now " << counter << endl;
    
    counter ++;
    cout << "The counter is now " << counter << endl;
    
    return 0;
}

#include <cstdlib>
#include <iostream>

using namespace std;
int main(int argc,char *argv[])
{
    int counter, copy1,copy2;
    cout << "Enter an integer:" ;
    cin >> counter;
    
    cout << "The counter is starting at "<< counter << endl<< endl;
    //copy the value
    copy1 = counter;
    copy2 = counter;
    // ++copy1 = 9,copy2++ = 8
    cout << "The value returned by the prefix ++ is " << ++copy1 << endl;
    cout << "After the operation, the value is " << copy1 << endl << endl;
    
    cout << "The value returned by the postfix ++ is " << copy2++ << endl;
    cout << "After the operation, the value is " << copy2 << endl << endl;
    
    return 0;
}

#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
    int counter, start, end;
    cout << "Enter an integer to start counting at: ";
    cin >> start;
    cout << "Enter an integer to end coutning at: ";
    cin >> end;
    
    // exit the code on invalid input_iterator
    if (start > end)
    {
        cout << "I need the starting point to be less than the ending point!\n";
        
        return 0;
    }
    // the looping partial_sort
    counter = start;
    cout << "The counter is starting at "<< counter << endl<< endl;
    
    while (counter < end)
    {
        cout << "The counter is now " << counter << endl;
        counter ++;
    }
    cout << "After the loop, the counter is now " << counter << endl;
    
    return 0;
}

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int grade = 0; 
    int count = 0;
    int sum = 0;
    cout << "Enter an integer grade (-1 to exit) ";
    cin >> grade;
    
    // if you enter a letter, it will become an infinite loop, be careful!
    while (grade != -1)
    {
        count ++;
        sum += grade;
        
        cout << endl << "Debugging info: *******" << endl;
        cout << "Count is now "<< count << endl;
        cout << "Sum is now " << sum << endl;
        cout << "*******" << endl << endl;
        
        cout << "Enter an integer grade (-1 to exit) ";
        cin >> grade;
        
    }
    cout << "Done, " << count << " grades were entered." << endl;
    
    // can't divide by zero!
    if (count > 0)
    {
        cout << "The average grade is " << sum / count << endl;
    }
    
    return 0;
}

// infinite loop with exit
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string funYet;
    while(1)
    {
        cout << "Are you having fun yet? :";
        getline(cin, funYet);
        if (funYet == "yes")
        {
            ///return 0;
            exit(0);
        }
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    // infinite loop
    while(1)
    {
        cout << "Hellow world";
    }
    return 0;
}

// loop with averaging 
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double grade;
    int numberOfGrades=0;
    double sumOfGrades=0;
    string inputBuffer;
    
    while (inputBuffer != "#end")
    {
        cout << "Enter a grade:";
        getline (cin, inputBuffer);
        
        if (inputBuffer != "#end")
        {
            grade = atof(inputBuffer.c_str());
            numberOfGrades ++;
            sumOfGrades += grade;
        }
    }
    cout << "Number of grade is " << numberOfGrades << endl;
    cout << "The sum of the grades is " << sumOfGrades << endl;
    if (numberOfGrades != 0)
    {
        cout << "The average is " << sumOfGrades/numberOfGrades << endl;
    }
}

#include <iostream>
using namespace std;

int main()
{
    string funYet;
    int numberOfInteration = 0;
    
    cout << "Are we having fun?";
    getline(cin, funYet);
    
    while (funYet!= "yes" && numberOfInteration < 10)
    {
        numberOfInteration ++;
        cout << "How about now?";
        getline (cin, funYet);
    }
    cout << "It took " << numberOfInteration << " times to have fun" << endl;
    
    return 0;
}

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    for (i = 10; i >0; i--)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i;
    cout << "Even numbers to 100" << endl;
    
    for (i = 0; i < 100; i += 2)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    
    cout << "Powers of 2 to 10000000" << endl;
    for (i = 1; i < 10000000; i *= 2)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    
    return 0;
}

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int outer, inner;
    
    for (outer = 0; outer < 5; outer ++)
    {
        cout << "Outer loop " << outer << endl;
        
        for (inner = 100; inner < 103; inner ++)
        {
            cout << "\tInner loop "<< inner << endl;
        }
    }
    return 0;
}

// 100 bottles of beer
#include <iostream>
using namespace std;

int main()
{
    int numberOfBottles;
    
    for (numberOfBottles = 100; numberOfBottles > 0; numberOfBottles --)
    {
        cout << numberOfBottles << " bottles of beer on the wall,\n";
        cout << numberOfBottles << " bottles of beer.\n";
        cout << "If one of those bottles should happen to fall: \n";
        cout << numberOfBottles-1 << " bottles of beer on the wall.\n";
        cout << endl;
    }
    return 0;
}

// dowhile input verification 
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string inputBuffer;
    double number;
    
    do {
        cout << "Enter a number: ";
        getline(cin, inputBuffer);
        number = atof(inputBuffer.c_str());
    } while (number <=0 );
    return 0;
}

// for counting 
#include <iostream>
using namespace std;

int main()
{
    int countDown;
    for (countDown = 10; countDown > 0; countDown--)
    {
        cout << countDown << endl;
    }
    cout << "Blast off" << endl;
    
    return 0;
}

// for declarations
#include <iostream>

using namespace std;

int main()
{
    int countDown1;
    
    for (countDown1 = 10; countDown1 > 0; countDown1--)
    {
        cout << countDown1 << endl;
    }
    cout << "Blast off" << endl;
    cout << countDown1 << " is the value of countDown1 after the loop\n";
    
    for (int countDown2 = 10; countDown2 > 0; countDown2--)
    {
        cout << countDown2 << endl;
    }
    // because countDown2 is a local variable within for loop
    // the next line won't print out
    //cout << countDown2 << " is the value of countDown2 after the loop\n";
    cout << "Blast off" << endl;
    return 0;
}

// for examples
#include <iostream>
using namespace std;
// do something 100 times, i is the generic counting variable
int main()
{
    int i;
    for (i=0;i<100;i++)
    {
        cout << "Bryna ";
    }
    return 0;
}

// for nested rectangle
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string inputBuffer;
    int rows, cols;
    int r,c;
    // both rows and cols are positive nonzero integers
    do{
        // collect my input
        do
        {
            cout << "Enter the number of rows:";
            getline(cin, inputBuffer);
            rows = atoi(inputBuffer.c_str());
        } while(rows <=0);

        do
        {
            cout << "Enter the number of columns:";
            getline(cin, inputBuffer);
            cols = atoi(inputBuffer.c_str());
        }while (cols <= 0);

        for (r = 0; r<rows; r++)
        {
            for(c = 0; c<cols; c++)
            {
                cout << "X";
                // this for line is to add a little time after print one X
                // so that user can see clearly how X form a rectangle
                for (int wait = 0; wait < 10000000; wait ++);
            }
            cout << endl;
        }
        cout << "Do this again?[y/n]";
        getline(cin, inputBuffer);
        // this for loop is to print 24 blank lines 
        for (int lines = 0; lines < 24; lines ++)
        {
            cout << endl;
        }
    } while(inputBuffer != "n");

    return 0;
}


// while counting
#include <iostream>
using namespace std;

int main()
{
    int countDown = 10;
    while (countDown > 0)
    {
        cout << countDown << endl;
        countDown --;
    }
    cout << "Blast off!\n";
    
    return 0;
}

// while input verification 
#include <iostream>
#include <cstdlib>

using namespace std;

int main()

{
    stirng inputBuffer;
    double number;
    cout << "Program to force a positive, non-zero number to be entered:\n";
    cout << endl << endl;
    
    cout << "Enter a number";
    getline(cin,inputBuffer);
    number = atof(inputBuffer.c_str());
    
    while (number <= 0)
    {
        cout << "Enter a number";
        getline(cin, inputBuffer);
        number = atof(inputBuffer.c_str());
    }
    return 0;
}