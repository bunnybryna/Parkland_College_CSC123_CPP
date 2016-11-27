int count, number_of_dragons;
double distance;

cout << "You have won"<< endl;

cin >> number >> size;

if (boolean_expression)
{
    yes_statement1;
    yes_statement2;
    ...
}    
else if (boolean_expression)
    statement_n;
else
    no_statement;

while (boolalpha)
{
    statement1;
    statement2;
    ...
}

do
{
    statement1;
    statement2;
    ...
} while(boolean_expression);

switch(controlling_expression)
{
    case constant1:
        statement1;
        break;
    case constant2:
        statement2;
        break;    
    ...
    default:
        default_statement;
}

for (initialization_action; boolean_expression; update_action)
{
    statement1;
    statement2;
    ...
}

// void function declaraiton
void funciton_name(parameter_list);
// void function definition

void function_name(parameter_list)
{
    declaration1;
    declaraiton2;
    ...
    executable_statement1;
    executable_statement2;
    ...
    
}

//call a member function
calling_object.member_function_name(argument_list);
//examples
in_stream.open("infile.dat");
out_stream.precision(2);


// funciton get and put
inputs_stream.get(char_variable);
out_stream.put(char_expression);
// examples
char next_symbol;
cin.get(next_symbol);
in_stream.get(next_symbol);
cout.put(next_symbol);
out_stream.put('Z');

// array
type_name array_name[declared_size];

// function with an array parameter
type_returned function_name(..., type array_name[],int size_name)

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

// class string or C++ strings
// initialized to the empty string
string phase;
// initialized to a string value equivalent to the C-string "ants"
string noun("ants");

// pointers
type_name *variable_name1, *variable_name2,...;
// the following sets the value of p so that p points to the variable v 
p = &v;

// type definitions
typedef known_type_definition new_type_name;
typedef int* IntPtr;

// dynamic array
typedef double* DoubleArrayPtr;
DoubleArrayPtr a;
// size variable can be given using an int variable or int expressions
a = new double[array_size];
// call delete[] with empty [] 
delete [] a;