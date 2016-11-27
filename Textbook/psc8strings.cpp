// declare C-strings, 1 for the null character'\0'
char array_name[maximum_size+1];
// examples
char my_csting[11];
// initializing C-strings while declaration
char short_string[]="abc";
// is equivalent to below, because c++ will make the size 1 more than the length of the quoted string
char short_string[4]="abc";
// don't do this, it will be a normal array wihout '\0'
chart short_string[]={'a','b','c'};
// can be partially filled, 10-11 is empty 0
char your_string[11]="Do Be Do";
// "=" assigning is illegal for C-strings
char a_string[10];
// a_string="Hello" won't work
strcpy(a_string, "Hello");

// strcmp (c_string1, c_string2) returns true if they don't match, false (0) when they're same
// if c_string1 greater, positive; if c_string2 greater, negetive

// >> and getline
// >> will skip all whitespace(blanks, tabs, link breaks)
// getline will read an entire line, second argument tells the max number of array elements
char a[80];
cin.getline(a,80); 

// 8.2 C strings to integers
#include <iostream>
#include <cstdlib>
// cctype is for atoi
#include <cctype>

void read_and_clean(int &n);
void new_line();
int main()
{
    using namespace std;
    int n;
    char ans;
    do{
        cout << "Enter an integer and press Return:";
        // now n is just a place holder
        read_and_clean(n);
        // now n is an real integer
        cout << "That string converse to the integer:" << n << endl;
        cout << "Again?(y/n):";
        cin >> ans;
        new_line();
    } while ((ans!='n')&&(ans !='N'));
    return 0;
}

// the other way to do this is to return n=read_and_clean();
void read_and_clean(int &n)
{
    using namespace std;
    const int ARRAY_SIZE=6;
    char digit_string[ARRAY_SIZE];

    char next;
    cin.get(next);
    int index=0;
    while (next != '\n')
    {
        if ((isdigit(next))&&(index < ARRAY_SIZE-1))
        {
            digit_string[index] = next;
            index++;
        }
        cin.get(next);
    }
    digit_string[index] = '\0';

    // atoi, atol and atof can be used to convert a C-string of digits to the corresponding numeric value
    n = atoi(digit_string);
}

void new_line()
{
    using namespace std;
    char symbol;
    do
    {
        cin.get(symbol);
    }while (symbol != '\n');
}

//8.5 program using the class string
#include <iostream>
#include <string>

void new_line();
int main()
{
    using namespace std;
    string first_name, last_name, record_name;
    string motto="Your recrods are our records.";
    
    cout << "Enter your first and last name:\n";
    cin >> first_name>> last_name;
    new_line();
    
    record_name = last_name + ", " + first_name;
    cout << "Your name in our records is: ";
    cout << record_name << endl;
    
    cout << "Our motto is\n" << motto << endl;
    cout << "Please suggest a better (one-line) mottot:\n";
    getline(cin,motto);
    cout << "Our new motto will be:\n";
    cout << motto << endl;
    
    return 0;
}

void new_line()
{
    using namespace std;
    char symbol;
    do
    {
        cin.get(symbol);
    }while (symbol != '\n');
}


getline(istream &ins, string &strVarialbe, char delimiter);
// getline will stop when the question mark encountered
getline(cin, line, '?'); 
// getline will read a line of text into s1 and a string of nonwhitespace into s2 
string s1,s2;
getline(cin, s1) >> s2;
// mixing cin >> and getline will always leave sth on the line for getline to read
// can use cin.ingnore(), it will read and discard the entire rest line upt to and including the \n

// str.length() will return the length of a string
// str.at(i) sometimes is better than str[i], because it will check if the index is illegal
str.at(2)='x';

// 8.8 palindrome testing progrm
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void swap(char &v1, char &v2);
string reverse(const string &s);
string remove_punct(const string &s, const string &punct);
string make_lower(const string &s);
bool is_pal(const string &s);
// you can remove all the consts and & in the function header
// because s is not changed within each function, can be a call-by-value parameter
// at the beginning of each function ,we always make a copy of s and make changes on that copy

int main()
{
    char ans;
    do{
    string str;
    cout << "Enter a candidate for palindrome test\n"
         << "followed by pressing Return.\n";
    getline(cin,str);
    if(is_pal(str))
        cout << "\"" << str +"\" is a palindrome.";
    else
        cout << "\"" << str +"\" is not a palindrome.";
    cout << endl;
    cout << "Test again?(y/n)";
    cin >> ans;
    cin.ignore();
    } while (ans == 'y');
    return 0;
}

bool is_pal(const string &s)
{
    string punct(",;:.?'\" ");
    // make a copy of s named str
    string str(s);
    // 1. make str lower casse
    str = make_lower(str);
    // 2. remove all the punctuations
    string lower_str = remove_punct(str, punct);
    return (lower_str == reverse(lower_str));
}

string make_lower(const string &s)
{
    string temp(s);
    for (int i=0;i<s.length();i++)
        temp[i] = tolower(s[i]);

    return temp;
}

string reverse(const string &s)
{
    int start = 0;
    int end = s.length();
    // make a copy of s named temp
    string temp(s);

    while (start < end)
    {
        end--;
        swap(temp[start],temp[end]);
        start++;
    }
    return temp;
}

void swap(char &v1, char &v2)
{
    char temp = v1;
    v1 = v2;
    v2 = temp;
}

string remove_punct(const string &s, const string &punct)
{
    string no_punct;
    int s_length=s.length();
    int punct_length = punct.length();
    for (int i=0;i<s_length;i++)
    {
        string a_char = s.substr(i,1);
        int location = punct.find(a_char, 0);

        if (location <0 || location >= punct_length)
            no_punct = no_punct + a_char;
    }
    return no_punct;
}

// 8.9 using a vector
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // <bast_type> is a template class
    vector<int> v;
    cout << "Enter a list of positive numbers.\n"
         << "Place a negative number at the end.\n";
         
    int next;
    cin >> next;
    while(next > 0)
    {
        v.push_back(next);
        cout << next << " added. ";
        cout << "v.size() = " << v.size() << endl;
        
        cin >> next;
    }
    cout << "You entered:\n";
    // unsigned int are nonnetative integers
    for (unsigned int i=0;i< v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    
    return 0;
    
}
