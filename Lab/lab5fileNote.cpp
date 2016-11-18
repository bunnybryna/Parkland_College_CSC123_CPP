#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void display();
void add();
//function display,add,showAll

int main()
{
    int choice;

	while (true)
    {
        cout << "What do you want me to do?\n"
             << "Choose 1 to display the names of your chosen file;\n"
             << "Choose 2 to add a name to the list;\n"
             << "Choose 3 to show all the lists;\n"
             << "Choose 4 to exit the program.\n"
             << "Please type in a number:\n";

        cin >> choice;
        switch(choice)
        {
            case 1:
                display();
                break;
            case 2:
                add();
                break;
            case 4:
                cout << "End of program. Bye bye!";
                exit(1);

        }

    }
    return 0;
}

void display()
{
    char in_file_name[16];
    ifstream infile;

    cout << "Please enter name and extension of the file you want to open:";
    // note here file_name instead of file_name[16]
    cin >> in_file_name;
    infile.open(in_file_name);
    if (infile.fail())
    {
        cout << "File opening failed. The file doesn't exist.\n";
    }
    // if file exists, then go ahead
    else
    {
        string next;
        while (!infile.eof())
        {
            int i;
            for (i=0; i<20; i++)
            {
                // solution1: while + for + if
                // test extraction first 
                if (infile >> next)
                  cout << next << " ";
            } 
                /* solution2: inside for loop
                infile >> next;
                if (!infile.eof())
                    cout << next << " ";
                // when eof turns true, force to cout next 
                // and then break from the loop 
                else
                {
                  cout << next << "\n";
                  cout << "This is the end of your file!\n";
                  break;
                }
            }    
            //solution3: while + while 
            int i = 0;
            // extraction first then cout next 
            // when inner while loop ends
            // move to next iteration of outer while loop 
            // then test eof 
            while ((infile >> next) && (i<20))
            {
                cout << next << " ";
                i ++ ;
            }*/
                system("PAUSE");
        }
        infile.close();
        cout << "End of displaying the file.\n";
    }
}

void add()
{
    char out_file_name[16];
    ofstream outfile;
    string name;

    cout << "Please enter name and extension of the file you want to add a name to:\n";
    cin >> out_file_name;
    outfile.open(out_file_name,ios::app);
    // to ignore the \n so that getine() can take an input
    cin.ignore();
    // no need to check fail() here
    cout << "Please enter the name you want to add to the file:\n";
    getline(cin, name);
    cout << name;
    outfile << name;
    outfile.close();
    cout << "End of appending to file.\n";
}
