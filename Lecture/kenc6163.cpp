// write to a file
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream.outFile;
    outFile.open("Myfile.txt");
    
    outFile << "Hello Disk!" << endl;
    
    outFile.close();
    
    return 0;
}

// read a file
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("MyFile.txt");
    outfile << "HelloDisk!" << endl;
    outfile.close();
    
    string inputBuffer;
    ifstream infile;
    infile.open("MyFile.txt");
    
    // note that >> operator will stop at the blank
    // >> uses spaces not newlines as delimiter
    // so leave no space in the string "HelloDisk"
    // for "Hello Disk" you can use getline(infile, inputBuffer);
    // getline reads entire line
    infile >> inputBuffer;
    cout << inputBuffer;
    
    infile.close();
    
    return 0;
}

// get() reads a single character from the file
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    char inputBuffer;
    ifstream infile;
    infile.open("MyFile.txt");
    // read the first char
    // same as inputBuffer = infile.get()
    infile.get(inputBuffer);
    cout << inputBuffer;
    // read the second char
    inputBuffer = infile.get();
    cout << inputBuffer;
    
    return 0;
}

// check if the input file opened
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    string inputBuffer;
    ifstream infile;
    infile.open("Myfilenotthere.txt");
    if (infile.fail())
    {
        // message to error stream
        cerr << "File not found" << endl;
        
        system("PAUSE");
        exit(1);
    }
    getline(infile, inputBuffer);
    cout << inputBuffer;
    
    infile.close();
    
    return 0;
}

// read the whole file
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("MyFile.txt");
    outfile << "Hello Disk!" << endl;
    outfile << "Here\nIs\nMore" << endl;
    
    outfile.close();
    
    string inputBuffer;
    ifstream infile;
    // it can be a whole path C:\\Users\\kurban\\DeskTop\\sample.txt
    infile.open("MyFile.txt");
    
    while (!infile.eof())
    {
        // getline skip \n, print out Hello Disk!HereIsMore
        getline(infile,inputBuffer);
        //check is data or EOF marker
        if (!infile.eof())
        {
            cout << inputBuffer;
        }
    }
    infile.close();
    
    return 0;
}

// filename as variables

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string inputBuffer;
    string infileName;
    ifstream infile;
    
    cout << "Enter a file name to open:";
    getline(cin,infileName);
    
    infile.open(infileName.c_str());
    if(infile.fail())
    {
        cerr << "File not found" << endl;
        system("PAUSE");
        exit(1);
    }
    else{
        cout << "Your file opened" << endl;    
    }
    infile.close();
    return 0;
}
// files and functions
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
// when passing streams as parameters, make sure to use ostream& and istream&
void starPrefix(ostream& out, string s);

int main()
{
    ofstream outfile;
    outfile.open("MyFile.txt");
    // call the function twice, one using outfile, another using cout 
    // input/out stream is versatile 
    starPrefix(outfile, "Hellow Disk!\n");
    starPrefix(cout, "Hello Disk!\n");
    
    starPrefix(outfile, "Last thing in the file.\n");
    starPrefix(cout, "Make sure you examine MyFile.txt!\n");
    
    outfile.close();
    
    return 0;
}

void starPrefix(ostream& out, string s)
{
    out << "**** " << s;
    
}

// getline() and >> don't work together

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i;
    string s;
    cout << "Enter an integer: ";
    cin >> i;
    cout << "Integer is: " << i << endl;
    // the program won't allow you to enter the string
    // becuase \n you pressed after the integer is still in cin input buffer
    // getline read that \n but cin >> s; will be fine
    cout << "Enter a string:";
    getline(cin, s);
    cout << "String is " << s << endl;
    
    return 0;
    
}

 // another solution:
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i;
    string s;
    cout << "Enter an integer: ";
    cin >> i;
    cin.ignore();
    cout << "Integer is: " << i << endl;

    cout << "Enter a string:";
    getline(cin, s);
    cout << "String is " << s << endl;
    
    return 0;
    
}

// I/O manipulators
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Let's look at some I/O manipulators." << endl << endl;
    double n = 2.264243431;
    cout << "Number (without anything):" << n << endl << endl;
    
    cout << "Number with setw(15)" << setw(15) << n << endl;
    cout <<                       123456789012345<< endl << endl;
    
    cout << "Number with setprecision(8)" << setprecision(8) << n << endl;
    cout << "Number with setprecision(5)" << setprecision(5) << n << endl;
    cout << "Number with setprecision(2)" << setprecision(2) << n << endl;
    cout << "Number with setprecision(1)" << setprecision(1) << n << endl;
    
    return 0;
}