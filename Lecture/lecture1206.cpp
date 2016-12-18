//null pointer, a pointer isn't set to anything
// only somethins works
int* ptr = 0;
int* iptr = null;
int *iptr = NULL;
int *iptr = nullptr;
// always works
int* ptr = static_cast<int*>(0);
// check before dereferencing
string *namePtr;
namePtr = static_cast<string*>(0);
if (namePtr)
{
    cout << *namePtr << endl;
}

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
string *namePtr;
namePtr = static_cast<string*>(0);
int *iPtr;
// check if it's a null pointer
if (namePtr)
{
    cout << *namePtr << endl;
}
iPtr = (int*) malloc(10 * sizeof(int));
iPtr[0] = 10;
cout << iPtr[0];
return 0;
}

temPropertyPtr = new Property();
(*temPropertyPtr).setFromCSV(inputBuffer);
m_properties.push_back(temPropertyPtr);
// 
m_properties.push_back = new Property(inputBuffer);
