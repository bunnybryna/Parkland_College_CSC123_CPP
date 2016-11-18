#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

const int SIZE=100;

using namespace std;
// function declaration goes here
void add(int& index, string n[], string d[], double p[], int q[]);
int search(string targetNum, string n[], int size);
void listAll(int count, string n[], string d[], double p[], int q[]);
void total(int count, double p[], int q[]);
void saveToFile(int count, string n[], string d[], double p[], int q[]);
void printFile();

int main()
{
    int ans;
    string number[SIZE], description[SIZE];
    double price[SIZE];
    int quantity[SIZE];
    // count has to stay out of the while loop
    // or in every iteration, four arrays goes empty
    int count = 0;

    while (true)
    {
        cout <<"-----------------------------------------------\n"
             << "Welcome to Bryna Inventory Management System!\n"
             << "Type 1 to add a new inventory item to the database;\n"
             << "Type 2 to search an item in the database;\n"
             << "Type 3 to list all items in the database;\n"
             << "Type 4 to calculate the total value of inventory;\n"
             << "Type 5 to save the database into a file;\n"
             << "Type 6 to print a database from a file;\n"
             << "Type 0 to exit the program.\n"
             << "What do you want me to do?\n";
        cin >> ans;
        switch(ans)
        {
            case 1:
            {
                char again;
                do{
                    add(count, number, description, price, quantity);
                    count ++;
                    cout << "Do you want to add more item?[y/n]\n";
                    cin >> again;
                } while (again == 'y');

                break;
            }

            case 2:
            {
                string targetNum;
                cout << "Please tell me the number of the item you would like to search for: \n";
                cin >> targetNum;
                int result;
                // now count already incremented after case 1
                result = search(targetNum, number, count);
                if (result == -1)
                {
                    cout << "Sorry, not found.\n";
                }
                else
                {
                     cout << "You've found item (" << number[result] << ") "
                            << description[result] << ", each price = $ " << price[result]
                            << " and quantity = "<< quantity[result] << endl;
                }
                break;
            }
            case 3:
                listAll(count, number, description, price, quantity);
                break;
            case 4:
                total(count, price, quantity);
                break;
            case 5:
                saveToFile(count, number, description, price, quantity);
                break;
            case 6:
                printFile();
                break;
            case 0:
                cout << "End of program. Thanks!\n";
                exit(1);
            default:
                cout << "Invalid option. Please try again!\n";
                break;
        }
    }
    return 0;
}

void add(int& index, string n[], string d[], double p[], int q[])
{


    cout << "Please enter the following data about the item:\n"
         << "Please type in item number:\n";
    cin >> n[index];
    cin.ignore();
    cout << "Please type in item description:\n";
    // getline(cin,d[]) is for string type d[], and c string should use cin.getline(d[],SIZE)
    getline(cin, d[index]);
    cout << "Please type in item price:\n";
    cin >> p[index];
    cout << "Please type in quantity on hand:\n";
    cin >> q[index];
    cout << "You've added item (" << n[index] << ") "
         << d[index] << ", each price = $ " << p[index]
         << " and quantity = "<< q[index] << endl;
}

// only need number[]
int search(string targetNum, string n[], int size)
{
    int i=0;
    bool found = false;
    while(i < size)
    {
        if (n[i] == targetNum)
        {
            found = true;
            break;
        }
        else
            i++;
    }
    if (found)
        return i;
    else
        return -1;
}

void listAll(int count, string n[], string d[], double p[], int q[])
{
    cout << "Here is your updated inventory:\n";
    cout << setw(10) << "Item Number"
         << setw(40) << "Item Description"
         << setw(10) << "Price"
         << setw(10) << "Quantity\n";
    for (int i=0;i<count;i++)
    {
        cout << setw(10) << n[i]
             << setw(40) << d[i]
             << setw(10) << p[i]
             << setw(10) << q[i]
             << endl;
        // pause every 15 lines
        if (i%15 == 14)
        {
            system("PAUSE");
        }
    }
    cout << "End of inventory." << endl << endl;

}

// only need price[] and quantity[]
void total(int count, double p[], int q[])
{
    double value, totalValue;
    for (int i=0;i<count;i++)
    {
        value = p[i] * q[i];
        totalValue = totalValue + value;
    }
    // format the output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The total value of your inventory is $" << totalValue << endl;
}

void saveToFile(int count, string n[], string d[], double p[], int q[])
{
    char out_file_name[16];
    ofstream outfile;
    string name;
    cout << "Please enter name and extension of the file you want to save to(maximum of 15 characters):\n";
    cin >> out_file_name;
    outfile.open(out_file_name);
    cin.ignore();
    for (int i=0;i<count;i++)
    {
        outfile << setw(10) << n[i]
                << setw(40) << d[i]
                << setw(10) << p[i]
                << setw(10) << q[i]
                << endl;
    }
    outfile.close();
    cout << "End of writing to file.\n";
}

void printFile()
{
    char in_file_name[16];
    ifstream infile;
    string next;
    cout << "Please enter the name and extension of the file you would like to open(maximum of 15 characters):\n";
    cin >> in_file_name;
    infile.open(in_file_name);
    if (infile.fail())
    {
        cout << "File opening failed.\n";
    }
    else
    {
        cout << "Here is the inventory in your file:\n";
        cout << setw(10) << "Item Number"
             << setw(40) << "Item Description"
             << setw(10) << "Price"
             << setw(10) << "Quantity\n";
        char next;
        do{
            infile.get(next);
            cout << next;
        } while(!infile.eof());
        cout << "\nEnd of the file.\n";
    }
}
