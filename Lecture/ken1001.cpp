// data class example
#include <iostream>
using namespace std;
class Date{
    friend ostream& operator<<(ostream& o, Date d);
private:
    int month;
    int day;
    int year;
public:
    void print();

    // mutator
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);

    //accessor
    int getYear();
    int getMonth();
    int getDay();

    //constructor
    Date();
    Date(int m, int d, int y);

};

ostream& operator<<(ostream& o, Date d)
{
    o<< d.month<<"/" << d.day << "/" << d.year;
    return o;
}

void Date::print()
{
    cout << month << "/"<< day << "/" << year << endl;
}

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

Date::Date()
{

}

Date::Date(int m, int d, int y)
{
    setMonth(m);
    setDay(d);
    setYear(y);
}

int main()
{
    Date d, christmas(12, 25, 2010), another;
    d.setYear(2010);
    d.setMonth(12);
    d.setDay(1);

    d.print();
    christmas.print();
    another.print();

    cout << "The day before christmas is " << christmas.getDay() -1 << endl;
    cout << christmas << endl;

    return 0;
}
// point class example
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;
class Point
{
  friend ostream& operator<<(ostream& o, Point p);
private:
    double x;
    double y;

public:
    // constructor
    Point();
    Point(double x1, double y1);

    // mutator
    void setX(double d);
    void setY(double d);
    void setXY( double x1, double y1);

    // accessor
    double getX();
    double getY();

    void print();

    double distanceToOrigin();
    double distanceTo(Point p);
    bool read(ifstream &in);
};

// no Point::, because it's not a Point class member function
ostream& operator<<(ostream& o, Point p)
{
    o << "(" << p.x << "," << p.y << ")";
    return o;
}

Point::Point()
{
    setXY(0,0);
}

Point::Point(double x1, double y1)
{
    setXY(x1, y1);
}

void Point::setX(double d)
{
    x = d;
}

void Point::setY(double d)
{
    y = d;
}

void Point::setXY(double x1, double y1)
{
    x = x1;
    y = y1;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

void Point::print()
{
    cout << "(" << x << "," << y << ")";
}

double Point::distanceToOrigin()
{
    return sqrt(x*x + y*y);
}

double Point::distanceTo(Point p)
{
    return sqrt(pow(x-p.x, 2)+pow(y-p.y, 2));
}

bool Point::read(ifstream &in)
{
    in >> x >> y;
    if (in.eof())
        return false;
    return true;
}

int main()
{
    Point p, q, r(-10,-10.5),l;
    p.print();
    cout << endl;
    p.setX(37);
    p.setY(64);
    p.print();
    cout << endl;
    cout << q.getX() << q.getY();
    q.setXY(0,0);
    q.print();
    cout << endl;
    cout << "Point p is " << p << endl;
    cout << "Distance to origin of p is " << p.distanceToOrigin() << endl;
    cout << "Distance to origin of r is " << r.distanceToOrigin() << endl;
    p.setXY(0,0);
    l.setXY(3,3);
    cout << "Distance from p to l is " << p.distanceTo(l) << endl;

    Point origin(0,0);
    ifstream dataFile("data.txt");
    if (dataFile.fail())
        {

            cout << "Can't open file."<< endl;
            exit(1);
        }


    do{

        cout << "Distance is " << p.distanceToOrigin()<< endl;
    }while(p.read(dataFile));

    return 0;
}


//rectangle class
// Point header
#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;

class Point
{
    public:
        Point(){myX=0;myY=0;}
        Point(double x, double y)
               {myX=x;myY=y;}
        // mutator
        void setX(double data) {myX = data;}
        void setY(double data) {myY = data;}

        // accessor
        double getX() {return myX;}
        double getY() {return myY;}

        void print();
        double distanceTo(Point p);
        bool read(ifstream &in);

    protected:
    private:
        double myX;
        double myY;
};

void Point::print()
{
    cout << "("
         << myX
         << ","
         << myY
         << ")";
}

double Point::distanceTo(Point p)
{
    // sqrt(  (x1-x2)^2 + (y1-y2)^2)

   return sqrt( pow(myX - p.myX, 2.0)
               + pow(myY - p.myY, 2.0));
}

bool Point::read(ifstream &in)
{
    in >> myX >> myY;

    if (in.eof() || in.fail() )
        return false;

    return true;
}

// Rectangle header
class Rectangle
{
    public:
        Rectangle();

        // mutator
        void setCorner1(Point data) {myCorner1=data;}
        void setCorner2(Point data) {myCorner2=data;}

        // accessor
        Point getCorner1() {return myCorner1;}
        Point getCorner2() {return myCorner2;}

        void print();
        double perimeter();
        double area();

    protected:
    private:
        Point adjCorner1();

        Point myCorner1;
        Point myCorner2;
};

Rectangle::Rectangle()
{
    //ctor
    Point origin(0,0);
    myCorner1 = origin;
    myCorner2 = origin;
}

void Rectangle::print()
{
    cout << "Rectangle from ";
    myCorner1.print();
    cout << " to ";
    myCorner2.print();
    cout << " ";
}

double Rectangle::perimeter()
{
     // double the distance from
     // (d1) corner1 to adjcorner1 plus
     // (d2) adjcorner1 to corner2
     double d1, d2;
     Point adj = adjCorner1();
     d1 = myCorner1.distanceTo(adj);
     d2 = myCorner2.distanceTo(adj);
     return (d1 + d2) * 2.0;
}

double Rectangle::area()
{
     double d1, d2;
     Point adj = adjCorner1();
     d1 = myCorner1.distanceTo(adj);
     d2 = myCorner2.distanceTo(adj);
     return (d1 * d2);
}

Point Rectangle::adjCorner1()
{

    Point p( myCorner1.getX(), myCorner2.getY() );

    return p;
}

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream dataFile("data.txt");
    Point p1, p2;

    Rectangle r;

    if (dataFile.fail())
    {
        cout << "Can't open file 'data.txt'" << endl;
        exit(1);
    }

    p1.read(dataFile);
    p2.read(dataFile);
    r.setCorner1(p1);
    r.setCorner2(p2);
    r.print();

    cout << "Perimeter is " << r.perimeter() << endl;
    cout << "Area is " << r.area() << endl;

    return 0;
}

// vectors and objects
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
class Point
{
 public:
    Point(){
        the_x = 0;
        the_y = 0;
    }
    Point(int x, int y) {
        the_x = x;
        the_y = y;
    }
    void input();
    void print();
    double distanceToOrigin(){
        return sqrt(the_x * the_x + the_y * the_y);
    }
private:
    int the_x;
    int the_y;
};

bool myPointCompareFunction(Point p1, Point p2)
{
    return p1.distanceToOrigin() < p2.distanceToOrigin();
}

int main()
{
    vector<Point> doodle;
    for (int i=0;i<10;i++)
    {
        Point p;
        cout << "Enter point number " << i << " ";
        p.input();
        doodle.push_back(p);
    }

    for (int i=0;i<doodle.size();i++)
    {
        doodle[i].print();

    }
    cout << endl <<endl;

    vector<Point>::iterator iter;
    for (iter=doodle.begin();iter!=doodle.end();iter++)
    {
        iter->print();
    }
    cout << endl << endl;

    random_shuffle(doodle.begin(), doodle.end());
    for (int i=0;i<doodle.size();i++)
    {
        doodle[i].print();
    }
    cout << endl << endl;

    sort(doodle.begin(),doodle.end(), myPointCompareFunction);

    for(int i=0;i<doodle.size();i++)
    {
        doodle[i].print();
    }
    cout << endl << endl;

    return 0;
}

void Point::input()
{
    cout << "x:";
    cin >> the_x;
    cout << "y:";
    cin >> the_y;
}

// send a point to the screen
void Point::print()
{
    cout << "(" << the_x << ", " << the_y << ")";
}


