// 10.1 a structure definition
#include <iostream>
using namespace std;
struct CDAccount
{
    double balance;
    double interest_rate;
    int term;
};

void get_data(CDAccount &the_account)

int main()
{
    CDAccount account;
    get_data(account);
    
    double rate_fraction, interest;
    rate_fraction = account.interest_rate;
    interest = account.balance * rate_fraction *(account.term / 12.0);
    account.balance = account.balance + interest;
    
    cout.setf(ios::fixed);
    cout.setf(ios:showpoint);
    cout.precision(2);
    cout << "When your CD matures in " << account.term << " months,\n"
         << "it will have a balance of $" << account.blance << endl;
         
    return 0;
}

void get_data(CDAccount &the_account)
{
    cout << "Enter account balance: $";
    cin >> the_account.balance;
    cout << "Enter account interest rate: ";
    cin >> the_account.interest_rate;
    cout << "Enter the number of months until maturity\n"
         << "(must be 12 or fewer months): ";
    cin >> the_account.term;
}

//initializing structures
struct Date
{
    int month;
    int day;
    int year;
};
Date due_date={12, 31, 2004};
// if initializer > struct members, error; if < initialized to 0

// 10.3 class with a member function
#include <iostream>
using namespace std;
class DayOfYear
{
public: 
    void output();
    int month;
    int day;  
};

int main()
{
    DayOfYear today, birthday;
    cout << "Enter today's date:\n";
    cout << "Enter month as a number:";
    cin >> today.month;
    cout << "Enter the day of the month: ";
    cin >> today.day;
    cout << "Enter your birthday:\n";
    cout << "Enter month as a number: ";
    cin >> birthday.month;
    cout << "Enter the day of the month: ";
    cin >> birthday.day;
    
    cout << "Today's date is ";
    today.output();
    cout << "Your birthday is ";
    birthday.output();
    if (today.month == birthday.month && today.day == birthday.day)
        cout << "Happy Birthday!\n";
    else
        cout << "Happy Unbirthday!\n";
    return 0;
}
//::is scope resolution operator, is used with class names, . is used with objects
// DayOfYear is a type qualifier
void DayOfYear::output()
{
    cout << "month = " << month
         << ", day = " << day << endl;
}

// 10.4 class with private members
#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear
{
public:
    void input();
    void output();

    void set(int new_month, int new_day);
    int get_month();
    int get_day();
private:
    void check_date();
    int month;
    int day;
};

int main()
{
    DayOfYear today, b_birthday;
    cout << "Enter today's date:\n";
    today.input();
    cout << "Today's date is ";
    today.output();

    b_birthday.set(7,25);
    cout << "Bryna Zhao's birthday is ";
    b_birthday.output();

    if(today.get_month() == b_birthday.get_month() &&
        today.get_day() == b_birthday.get_day())
        cout << "Happy Birthday Bryna!\n";
    else
        cout << "Happy Unbirthday Bryna!\n";
    return 0;
}

void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    check_date();
}

void DayOfYear::output()
{
    cout << "month = " << month
         << ", day = " << day << endl;
}
// setter, or mutator funciton 
void DayOfYear::set(int new_month, int new_day)
{
    month = new_month;
    day = new_day;
    check_date();
}

void DayOfYear::check_date()
{
    if ( (month < 1) || (month > 12) || (day < 1) || (day >31))
    {
        cout << "Illegal date, Aborting program.\n";
        exit(1);
    }
}
// getter, or accessor function
int DayOfYear::get_month()
{
    return month;
}

int DayOfYear::get_day()
{
    return day;
}


// 10.5 class
#include <iostream>
#include <cstdlib>
using namespace std;

class BankAccount
{
public:
    void set(int dollars, int cents, double rate);
    void set(int dollars, double rate);
    void update();
    double get_balance();
    double get_rate();
    void output(ostream &outs);

private:
    double balance;
    double interest_rate;
    // note that fraction() is private
    // it will only be called to help build other functions outside main()
    double fraction(double percent);
};

int main()
{
    BankAccount account1, account2;
    cout << "Start of Test:\n";
    account1.set(123,99,3.0);
    cout << "account1 initial statement:\n";
    account1.output(cout);
    account1.set(100,5.0);
    cout << "account1 with new setup:\n";
    account1.output(cout);

    account2= account1;
    cout << "account2:\n";
    account2.output(cout);
    return 0;
}

void BankAccount::set(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    balance = dollars + 0.01*cents;
    interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rae.\n";
        exit(1);
    }
    balance = dollars;
    interest_rate = rate;
}

void BankAccount::update()
{
    balance = balance + fraction(interest_rate)*balance;
}

double BankAccount::fraction(double percent_value)
{
    return (percent_value/100.0);
}

double BankAccount::get_balance()
{
    return balance;
}

double BankAccount::get_rate()
{
    return interest_rate;
}

// stream parameter can be replaced by cout or ofstream
void BankAccount::output(ostream &outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
    outs << "Interest rate " << interest_rate << "%" << endl;
}


// 10.6 class with constructors
// constructor vs set
// a call to constructor always creates a new object
// a call to set() only changes the value of existing object
#include <iostream>
#include <cstdlib>
using namespace std;

class BankAccount
{
 public:
    BankAccount(int dollars, int cents, double rate);
    BankAccount(int dollars, double rate);
    BankAccount();
    
    void set(int dollars, int cents, double rate);
    void set(int dollars, double rate);
    void update();
    double get_balance();
    double get_rate();
    void output(ostream &outs);
    
private:
    double balance;
    double interest_rate;
    double fraction(double percent);
};

int main()
{
    // for default (no-argument) constructors, do not include ()!!!
    BankAccount account1(100,2.3), account2;
    // account1.BankAccount(100,2.3) is VERY Illegal
    cout << "accoutn1 initialized as follows:\n";
    account1.output(cout);
    cout << "account2 initialized as follows:\n";
    account2.output(cout);
    // with constructors, for this program no need to call set(), get, or update()
    // an explicit call to the constructor
    account1 = BankAccount(999,99,5.5);
    cout << "account1 reset to the following:\n";
    account1.output(cout);
    return 0;
}
// constructors have the same name of the class, and no return value
// need to public
BankAccount::BankAccount(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    balance = dollars + 0.01*cents;
    interest_rate = rate;    
}
// it will be equivalent to following
// BankAccount::BankAccount(int dollars, double rate): balance(dollars), interest_rate(rate)
// { if... }
BankAccount::BankAccount(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rae.\n";
        exit(1);
    }
    balance = dollars;
    interest_rate = rate;    
}

// constructor initialization section
// it does nothing,just make the complier happier
BankAccount::BankAccount():balance(0), interest_rate(0.0)
{
    //body intentionally empty
}

void BankAccount::set(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    balance = dollars + 0.01*cents;
    interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rae.\n";
        exit(1);
    }
    balance = dollars;
    interest_rate = rate;
}

double BankAccount::get_balance()
{
    return balance;
}

double BankAccount::get_rate()
{
    return interest_rate;

void BankAccount::output(ostream &outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
    outs << "Interest rate " << interest_rate << "%" << endl;
}

// 10.7 alternative BankAccount class implementation(with ADT)
// Abstract data type is to separate the interface and the implementation
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class BankAccount
{
    // no change in public section
public:
    BankAccount(int dollars, int cents, double rate);
    BankAccount(int dollars, double rate);
    BankAccount();
    void set(int dollars, int cents, double rate);
    void set(int dollars, double rate);
    void update();
    double get_balance();
    double get_rate();
    void output(ostream &outs);

private:
    int dollars_part;
    int cents_part;
    double interest_rate;

    double fraction(double percent_value);
    double percent(double fraction_value);
};

int main()
{
    BankAccount account1(100,2.3), account2;
    cout << "accoutn1 initialized as follows:\n";
    account1.output(cout);
    cout << "account2 initialized as follows:\n";
    account2.output(cout);
    account1 = BankAccount(999,99,5.5);
    cout << "account1 reset to the following:\n";
    account1.output(cout);
    return 0;
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    dollars_part = dollars;
    cents_part = cents;
    // private member function used in constructor
    interest_rate = fraction(rate);
}

BankAccount::BankAccount(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rae.\n";
        exit(1);
    }
    dollars_part = dollars;
    cents_part = 0;
    // private member function used in constructor
    interest_rate = fraction(rate);
}

BankAccount::BankAccount() : dollars_part(0), cents_part(0), interest_rate(0.0)
{
}

double BankAccount::fraction(double percent_value)
{
    return (percent_value/100.0);
}

void BankAccount::update()
{
    double balance = get_balance();
    balance = balance + interest_rate * balance;
    dollars_part = static_cast<int>(floor(balance));
    cents_part = static_cast<int>(floor((balance-dollars_part)*100));
}

double BankAccount::get_balance()
{
    return (dollars_part + 0.01 * cents_part);
}

double BankAccount::percent(double fraction_value)
{
    return (fraction_value * 100);
}

double BankAccount::get_rate()
{
    return percent(interest_rate);
}

void BankAccount::output(ostream &outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << get_balance() << endl;
    outs << "Interest rate " << get_rate() << "%" << endl;
}
void BankAccount::set(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    dollars_part = dollars;
    cents_part = cents;
    interest_rate = fraction(rate);
}

void BankAccount::set(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    dollars_part = dollars;
    interest_rate = fraction(rate);
}

// 10.9 a SavingsAccount Derived Class
// header of 10.6 goes here
#include <iostream>
#include <cstdlib>
using namespace std;

class BankAccount
{
 public:
    BankAccount(int dollars, int cents, double rate);
    BankAccount(int dollars, double rate);
    BankAccount();

    void set(int dollars, int cents, double rate);
    void set(int dollars, double rate);
    void update();
    double get_balance();
    double get_rate();
    void output(ostream &outs);

private:
    double balance;
    double interest_rate;
    double fraction(double percent);
};

// : means SavingsAccount is derived from BankAccount
// A is a derived class of class B, class A has all features of class B with some added featurs.
class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(int dollars, int cents, double rate);
    // only two new member functions
    void deposit(int dollars, int cents);
    void withdraw(int dollars, int cents);
private:
};

int main()
{
    SavingsAccount account(100,50,5.5);
    account.output(cout);
    cout << endl;
    cout << "Depositing $10.25." << endl;
    account.deposit(10,25);
    account.output(cout);
    cout << endl;
    cout << "Withdrawing $11.80. " << endl;
    account.withdraw(11,80);
    account.output(cout);
    cout << endl;
    return 0;
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    balance = dollars + 0.01*cents;
    interest_rate = rate;
}

BankAccount::BankAccount(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rae.\n";
        exit(1);
    }
    balance = dollars;
    interest_rate = rate;
}

BankAccount::BankAccount():balance(0), interest_rate(0.0)
{
    //body intentionally empty
}

void BankAccount::set(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    balance = dollars + 0.01*cents;
    interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rae.\n";
        exit(1);
    }
    balance = dollars;
    interest_rate = rate;
}

double BankAccount::get_balance()
{
    return balance;
}

double BankAccount::get_rate()
{
    return interest_rate;
}

void BankAccount::output(ostream &outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
    outs << "Interest rate " << interest_rate << "%" << endl;
}
// SavingsAccount constructor invokes BankAccount constructor
SavingsAccount::SavingsAccount(int dollars, int cents, double rate):
    BankAccount(dollars, cents, rate)
{

}

void SavingsAccount::deposit(int dollars, int cents)
{
    double balance = get_balance();
    balance += dollars;
    balance += static_cast<double>((cents)/100);
    int new_dollars = static_cast<int>(balance);
    int new_cents = static_cast<int>((balance-new_dollars) * 100);
    set(new_dollars, new_cents, get_rate());
}

void SavingsAccount::withdraw(int dollars, int cents)
{
    double balance = get_balance();
    balance -= dollars;
    balance -= static_cast<double>((cents)/100);
    int new_dollars = static_cast<int>(balance);
    int new_cents = static_cast<int>((balance-new_dollars)*100);
    set(new_dollars, new_cents, get_rate());
}


// another example
// creating a new CD (certificate of deposit) with &1000, 6%interest, 180 days to maturity\n
CDAccount newCD(1000,0,6.0,180);
// invoking a function in SavingsAccount
newCD.deposit(100,50);
// invoking a funciton in CDAccount
days_to_maturity = newCD.get_days_to_maturity();
// invoking a function in BankAccount
balance = newCD.get_balance();

  