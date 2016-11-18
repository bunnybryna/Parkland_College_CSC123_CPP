// 6.1 simple file input/output_iterator
#include <fstream>
int main()
{
    using namespace std;
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("infile.dat");
    out_stream.open("outfile.dat");
    int first, second, third;
    in_stream >> first >> second >> third;
    out_stream << "The sum of the first 3\n"
               << "numbers in infile.dat\n"
               << "is " << (first + second + third)
               << endl;
    in_stream.close();
    out_stream.close();
    return 0;
}


// 6.2 file I/O with checks on open
#include <fstream>
// <iostream> for cout
#include <iostream>
// <cstdlib> for exit()
#include <cstdlib>

int main()
{
    using namespace std;
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("infile.dat");
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    out_stream.open("outfile.dat");
    if (out_stream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    int first, second, third;
    in_stream >> first >> second >> third;
    out_stream << "The sum of the first 3\n"
               << "numbers in infile.dat\n"
               << "is " << (first + second + third)
               << endl;
    // different close functions, because they associated with different type/objects
    // in_stream1.close and in_stream2.close have the same member functions
    // even though they have different values
    in_stream.close();
    out_stream.close();
    return 0;
}

// 6.3 appending to a file
#include <fstream>
#include <iostream>
#include <cstdlib>

int main()
{
    using namespace std;

    cout << "Opening data.txt for appending.\n";
    ofstream fout;
    // :: means use the meaning of app in the context of ios
    fout.open("data.txt",ios::app);
    if (fout.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    fout << "5 6 pick up sticks.\n"
         << "7 8 ain't C++ great!\n";

    fout.close();
    cout << "End of appending to file.\n";

    return 0;
}

// 6.4 inputting a file name
#include <fstream>
#include <iostream>
#include <cstdlib>

int main()
{
    using namespace std;
    //16 is the the max number of characters you can have in a string stored in the variable
    // char a[] is an array, can hold more than one vs char: hold single letter, digit  
    char in_file_name[16], out_file_name[16];
    ifstream in_stream;
    ofstream out_stream;
    
    cout << "I will sum three numbers taken from an input\n"
         << "file and write the sum to an output file.\n";
    cout << "Enter the input file name (maximum of 15 characters):\n";
    cin >> in_file_name;
    cout << "Enter the output file name (maximum of 15 characters):\n";
    cin >> out_file_name;
    
    cout << "I will read numbers from the file "
         << in_file_name << " and place the sum in the file "
         << out_file_name << endl;
         
    in_stream.open(in_file_name);
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    out_stream.open(out_file_name);
    if (out_stream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    int first, second, third;
    in_stream >> first >> second >> third;
    out_stream << "The sum of the first 3\n"
               << "numbers in " << in_file_name << endl
               << " is " << (first + second + third)
               << endl;
               
    in_stream.close();
    out_stream.close();
    
    cout << "End of Program.\n";
    return 0;
    
}

// checking for the end of a file
double next, sum=0;
int count=0;
while (There are sill numbers to be read)
{
    in_stream>> next;
    sum = sum + next;
    count ++
}
the average is sum/count.


// 6.6 formatting output
#include <iostream>
#include <fstream>
#include <cstdlib>
// for setw
#include <iomanip>

using namespace std;
// stream parameters must be call_by_reference
void make_neat(ifstream& messy_file, ofstream& neat_file,
                int number_after_dec, int field_width);
int main()
{
    ifstream fin;
    ofstream fout;
    
    fin.open("rawdata.dat");
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    fout.open("neat.dat");
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    make_neat(fin, fout, 5, 12);
    
    fin.close();
    fout.close();
    
    cout << "End of program.\n";
    return 0;
}                

void make_neat(ifstream& messy_file, ofstream& neat_file,
               int number_after_dec, int field_width)
{
    neat_file.setf(ios::fixed);
    neat_file.setf(ios::showpoint);
    neat_file.setf(ios::showpos);
    neat_file.precision(number_after_dec);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(number_after_dec);
    
    double next;
    // messy_file >> next is both putting a number from the stream in_stream
    // and the controlling boolean expression for the while loop
    // ::fixed(not e-notation),::scientific(e-notation),::showpoint(decimal point)
    // ::showpos(plus sign),::right(extra blanks before),::left(extra blanks after)
    while(messy_file >> next)
    {
        cout << setw(field_width) << next << endl;
        neat_file << setw(field_width) << next << endl;
    }
}

// member functiion get and put
cout << "Enter a line of input and I will echo it:\n";
char symbol;
do
{
    cin.get(symbol);
    cout << symbol;
    //'n' and "n" is not the same, 'n' is type char, "n" is a string
}while (symbol != '\n');
cout << "That's all for this demonstration.";

// member function putback 
// after you read the next character and you do not want to process it
// using putback to put it back, putback places a character in an input stream(put=>output)
// eg: read up to but not including the first blank it encounters in an input stream
fin.get(next);
while (next != '\n')
{
    fout.put(next);
    fin.get(next);
}
fin.putback(next);

// 6.7 checking input
#include <iostream>
using namespace std;

void new_line();
void get_int(int& number);

int main()
{
    int n;
    
    get_int(n);
    cout << "Final value read in =" << n << endl
         << "End of demonstration.\n";
    
    return 0;
}

void new_line()
{
    char symbol;
    do
    {
        cin.get(symbol);
    }while (symbol != '\n');
}

void get_int(int& number)
{
    char ans;
    do 
    {
        cout << "Enter input number: ";
        cin >> number;
        cout << "You entered " << number
             << " Is that correct(yes/no)?";
        cin >> ans;
        new_line();
    // why use != 'y' instead == 'n':safer
    // if == 'n', user accidentally hit b, do-while loop will end
    // if != 'y', user accidenally hit b, cause an extra loop iteration only 
    }while ((ans != 'Y') && (ans != 'y'));
}

/* the importance of new_line() function
* without new_line, if user types in No for ans, cin reads only the first letter N for ans
* and then in the next loop, cin reads the rest(which is O) for number and '\n' for ans 
* cause an infinite loop
* new_line will discard the rest of the input line
* so next loop cin can read another number input from the user 
*/

// another new_line function
// when you call the function, new_line(fin) is taking input from an input stream
// new_line(cin) is reading some input from the keyboard
void new_line(istream& in_stream)
{
    char symbol;
    do{
        in_stream.get(symbol);
    }while (symbol != '\n');
}

// default arguments for functions
// if you call this function as new_line(), it takes the default argument cin
// if you call as new_line(fin), it override the default 
void new_line(istream& in_stream =  cin)
{
    char symbol;
    do
    {
        in_stream.get(symbol);
    }while (symbol != 'n');
}

// examples
void default_args(int arg1, int arg2, int arg3 = -3, int arg4 = -4)
{
    cout << arg1 << ' '<< arg2 << ' '<< arg3 << ' ' << arg4 << endl;
}
// will output 5 6 -3 -4
default_args(5,6)
// will output 6 7 8 -4
default_args(6,7,8)

// 6.8 editing a file of text
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;
void add_plus_plus(ifstream& in_stream, ofstream& out_stream);

int main()
{
    ifstream fin;
    ofstream fout;
    cout << "Begin editing the files.\n";
    fin.open("cad.dat");
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    fout.open("cplusad.dat");
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    add_plus_plus(fin,fout);
    fin.close();
    fout.close();
    cout << "End of editing files.\n";
    return 0;
}

void add_plus_plus(ifstream& in_stream, ofstream& out_stream)
{
    char next;
    // get is used here to read the whitespace and '\n',
    // according to textbook, using in_stream>> will skil over all the whitespace and \n
    // but it seems wrong... (?)
    in_stream.get(next);
    // eof() end of file, returns a bool
    while (! in_stream.eof())
    {
        // note that next is a char, so single quote''
        if( next == 'C')
            // C++ is a string so double quote ""
            out_stream<< "C++";
        else
            out_stream << next;
        in_stream.get(next);
    }
}
