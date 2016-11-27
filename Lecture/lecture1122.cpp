//.begin()starts from index 0,.end() pass the last one
//<algorithm>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
    srand(time(0));
    vector<int> numberList;
    numberList.push_back(20);
    numberList.push_back(30);
    numberList.push_back(40);
    numberList.push_back(10);


    vector<int>::iterator itr;
    itr = numberList.begin();

    for(itr = numberList.begin();itr!= numberList.end(); itr++)
    {
        cout <<"ping" << endl;
        // go to that item, dereferencing
        cout << *itr << endl;
        // *itr = 35 you can change it directly;
    }

    random_shuffle(numberList.begin(),numberList.end());
    for(itr = numberList.begin();itr!= numberList.end(); itr++)
    {
        cout << *itr << endl;
    }
    // from C to C++: C-string => class string, array=>vector, pointer=>iterator

    return 0;
}

#include <iostream>

using namespace std;

class Date
{
    //method declarations

public:
    // getters
    int getMonth();
    int getDay();
    int getYear();

   // setters
   // properties
   void setMonth(int m);
   void setDay(int d);
   void setYear(int y);

private:
    int month;
    int day;
    int year;
};

int main()
{
    Date d;
    d.setYear(2001);
    d.setMonth(2);
    d.setDay(6);
    cout << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << endl;

    return 0;
}
// to be part of class, have access to private data
void Date::setYear(int y)
{
    year=y;
}

void Date::setMonth(int m)
{
    month=m;
}

void Date::setDay(int d)
{
    day=d;
}

int Date::getYear()
{
     return year;
}


int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}


