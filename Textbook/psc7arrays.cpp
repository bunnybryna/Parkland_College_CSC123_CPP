// 7.1 program using an array
#include <iostream>

int main()
{
    using namespace std;
    int i,score[5], max;
    
    cout << "Enter 5 scores:\n";
    cin >> score[0];
    max = score[0];
    for (i=1;i<5;i++)
    {
        cin >> score[i];
        if (score[i]>max)
            max = score[i];
    }
    
    cout << "The highest score is " << max << endl
         << "The score and their \n"
         << "differences from the highest are:\n";
    for (i=0;i<5;i++)
    {
        cout << score[i] << " off by " << (max-score[i]) << endl;
    }
    
    return 0;
}

//7.3 indexed variable as an argument
#include <iostream>
const int numberEmployees=3;

int adjust_days(int old_days);

int main()
{
    using namespace std;
    int vacation[numberEmployees], number;
    cout << "Enter allowed vacation days for employee 1 "
         << "through " << numberEmployees << ":\n";
    // 1st for loop: collect input
    // to avoid confusion, I revised 1st and 3 rd for loop 
    // letting them start from number=0 instead of number=1(as textbook)
    for (number=0;number< numberEmployees;number++)
        cin >> vacation[number];
    // 2nd for loop: connect array index and each value
    for (number=0;number< numberEmployees;number++)
        vacation[number]=adjust_days(vacation[number]);
    // 3rd for loop: print out 
    cout << "The revised number of vacation days are:\n";
    for (number=0;number< numberEmployees;number++)
        cout << "Employee number " << number+1 << " vacation days = " 
             << vacation[number] << endl;
    return 0;         
}

int adjust_days(int old_days)
{
    return (old_days + 5);
}    

// 7.4 function with an array parameter
// array parameter behaves like call-by-reference parameter
// to call this function, just fillup(score, number_of_scores) without brackets
// array has 3 parts: address, type and size, 1 and 2 given by the a[] argument
// it's critical to have an int argument => size
void fillup(int a[], int size)
{
    using namespace std;
    cout << "Enter " << size << " numbers:\n";
    for (int i=0; i< size; i++)
        cin >> a[i];
    size--;
    cout << "The last array indes used is "<< size << endl;
}

// const array parameter
void show_the_world(const int a[],int size )
{
    cout << "The array contains:\n";
    // should be i++ instead of a[i]++
    // since you have const int a[], it will give you error
    // or it will mistakenly increment a[i] and enter an infinite loop
    // note that const is a all-or-nothing proposition
    // function calls within function calls, every unchanged parameter use const
    for (int i=0;i<size;a[i]++)
        cout << a[i] << " ";
    cout << endl;
}

// case study: graph program
#include <iostream>
#include <cmath>

const int numberPlants=4;

void input_data(int a[], int last_plant_number);

void scale(int a[], int size);

void graph(const int asterisk[], int last_plant_number);

void get_total(int &sum);

int roundnew(double number);

void print_asterisk(int n);

int main()
{
    using namespace std;
    int production[numberPlants];

    cout << "This program displays a graph showing\n"
         << "production for each plant in the company.\n";
    input_data(production,numberPlants);
    scale(production,numberPlants);
    graph(production,numberPlants);

    return 0;
}

// when test this function, include tests with all possible production figures
void input_data(int a[], int last_plant_number)
{
    using namespace std;
    for (int plant_number = 1; plant_number <= last_plant_number; plant_number++)
    {
        cout << endl
             << "Enter production data for plant number "
             << plant_number << endl;
        // if function is declared as int get_total() 
        // a[plant_number-1]=get_total();
        get_total(a[plant_number-1]);
    }
}

// sum is call-by-reference, because this number will be used later
// this function can work, because sum will be replaced by a[]
// if it's not a[](like a placeholder), you have to initialize sum and call function
// but what's the point of giving sum a value and after the function, replaced by a new value? 
// then soluction 2 is better: int get_total() and return sum; see page 205

void get_total(int &sum)
{
    using namespace std;
    cout << "Enter number units produced by each department:\n"
         << "Append a negative number to the end of the list.\n";

    sum = 0;
    int next;
    cin >> next;
    while (next >=0)
    {
        sum = sum + next;
        cin >> next;
    }
    cout << "Total = " << sum << endl;
}

void scale(int a[], int size)
{
    for (int index=0;index< size; index++)
    {
        a[index] = roundnew(a[index]/1000.0);
    }
}
// just use built-in function round() and include <cmath>
int roundnew(double number)
{
    using namespace std;
    return static_cast<int>(floor(number + 0.5));
}

// make array a constant parameter
void graph(const int asterisk[], int last_plant_number)
{
    using namespace std;
    cout << "\nUnits produced in thousands of units:\n";
    for(int plant_number = 1; plant_number <= last_plant_number; plant_number++)
    {
        cout << "Plant # " << plant_number << " ";
        print_asterisk(asterisk[plant_number-1]);
        cout << endl;
    }
}

void print_asterisk(int n)
{
    using namespace std;
    for (int count=1;count <=n; count++)
        cout << "*";
}

// 7.9 partially filled array
#include <iostream>
const int MAX_NUMBER_SCORES =10;

void fill_array(int a[], int size, int &number_used);

double compute_average(const int a[], int number_used);

void show_difference(const int a[], int number_used);

int main()
{
    using namespace std;
    int score[MAX_NUMBER_SCORES], number_used;
    
    cout << "This program reads golf scores and shows\n"
         << "how much each differs from the average.\n";
         
    cout << "Enter golf scores:\n";
    fill_array(score, MAX_NUMBER_SCORES, number_used);
    show_difference(score, number_used);
    
    return 0;
}

void fill_array(int a[], int size, int &number_used)
{
    using namespace std;
    cout << "Enter up to " << size << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";
        
        
    int next, index = 0;
    cin >> next;
    while(next>=0 && index < size)
    {
        a[index] = next;
        index++;
        cin >> next;
    }
    // note that number_used = index not index+1
    // because index ++ in the above while loop
    number_used = index;
}

double compute_average(const int a[], int number_used)
{
    double total=0;
    for (int index=0; index < number_used; index++)
        total = total + a[index];
    if number_used > 0;    
    {   
        return (total/number_used);
    }
    else
    {
        using namespace std;
        cout << "ERROR: number of elements is 0 in compute_average.\n"
             << "compute_average returns 0\n";
        return 0;
    }
}

void show_difference(const int a[], int number_used)
{
    using namespace std;
    double average = compute_average(a, number_used);
    cout << "Average of the " << number_used << " scores = " << average << endl
         << "The scores are :\n";
    for (int index = 0; index < number_used; index ++)
    cout << a[index] << " differs from average by "<< (a[index]-average) << endl;
}

// 7.10 searching an array
#include <iostream>

const int DECLARED_SIZE = 20;

void fill_array(int a[], int size, int &number_used);

int search(const int a[], int number_used, int target);

int main()
{
    using namespace std;
    int arr[DECLARED_SIZE], list_size, target;
    
    fill_array(arr, DECLARED_SIZE, list_size);
    
    char ans;
    int result;
    
    do{
        cout << "Enter a number to search for:";
        cin >> target;
        result = search(arr, list_size, target);
        if (result == -1)
        {
            cout << target << " is not on the list.\n";
        }
        else
        {
            cout << target << " is stored in array position " << result << endl
                 << "(remember the first position is 0.)\n";
        }
        cout << "Search again?(y/n followed by Return:)";
        cin >> ans;
    } while ((ans!= 'n') && (ans!= 'N'));
    
    cout << "End of program.\n";
}

void fill_array(int a[], int size, int &number_used)
{
    using namespace std;
    cout << "Enter up to " << size << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";
        
        
    int next, index = 0;
    cin >> next;
    while(next>=0 && index < size)
    {
        a[index] = next;
        index++;
        cin >> next;
    }
    // note that number_used = index not index-1
    // because index ++ in the above while loop
    number_used = index;    
}

int search(const int a[], int number_used, int target)
{
    int index = 0;
    bool found = false;
    while ((!found) && (index< number_used))
        if (target == a[index])
            found = true;
        else
            index ++;

    if(found)
        return index;
    else
        return -1;
}

// 7.12 sorting an array
#include <iostream>

void fill_array(int a[], int size, int& number_used);

void sort(int a[], int number_used);

void swap_values(int &v1, int &v2);

int index_smallest(const int a[], int start_index, int number_used);

int main()
{
    using namespace std;
    cout << "This program sorts numbers from lowest to highest.\n";
    
    int sample_array[10], number_used;
    fill_array(sample_array, 10, number_used);
    sort(sample_array, number_used);
    
    cout << "In sorted order the numbers are:\n";
    for (int index=0; index <number_used; index ++)
    cout << sample_array[index] << " ";
    cout << endl;
    
    return 0;
}

void fill_array(int a[], int size, int &number_used)
{
    using namespace std;
    cout << "Enter up to " << size << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";
        
        
    int next, index = 0;
    cin >> next;
    while(next>=0 && index < size)
    {
        a[index] = next;
        index++;
        cin >> next;
    }
    // note that number_used = index not index-1
    // because index ++ in the above while loop
    number_used = index;     
}

void sort(int a[], int number_used)
{
    int index_next_small ;
    for (int index = 0; index < number_used -1; index ++)
    {
        index_next_small= index_smallest(a, index, number_used);
        swap_values(a[index], a[index_next_small]);
    }   
}

void swap_values(int& v1, int& v2)
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int index_smallest(const int a[], int start_index, int number_used)
{
    int min = a[start_index], index_min = start_index;
    for (int index= start_index + 1; index < number_used; index ++)
        if (a[index] < min)
        {
            min = a[index];
            index_min = index;
        }
    return index_min;
}

// 7.13 two-dimensional array
#include <iostream>
#include <iomanip>
#include <cmath>
const int NUMBER_STUDENTS =4, NUMBER_QUIZZES = 3;

void fill_array(int a[][3],int row, int column);

void compute_st_ave(const int grade[][NUMBER_QUIZZES], double st_ave[]);

void compute_qz_ave(const int grade[][NUMBER_QUIZZES], double qz_ave[]);

void display(const int grade[][NUMBER_QUIZZES], const double st_ave[], const double qz_ave[]);

int main()
{
    using namespace std;
    int grade[NUMBER_STUDENTS][NUMBER_QUIZZES];
    double st_ave[NUMBER_STUDENTS];
    double qz_ave[NUMBER_QUIZZES];


    fill_array(grade,NUMBER_STUDENTS,NUMBER_QUIZZES);
    compute_st_ave(grade, st_ave);
    compute_qz_ave(grade, qz_ave);
    display(grade, st_ave, qz_ave);

    return 0;
}
void fill_array(int a[][3],int row, int column)
{
    using namespace std;
    for (int i=0; i<row; i++)
    {
        cout << "Enter quiz scores for student " << i+1 << endl;
        for (int j=0; j<column; j++)
        {
            cin >> a[i][j];
        }
    }
}

void compute_st_ave(const int grade[][NUMBER_QUIZZES], double st_ave[])
{
    for (int st_num = 1; st_num <= NUMBER_STUDENTS; st_num++)
    {
        double sum = 0;
        for (int qz_num = 1; qz_num <= NUMBER_QUIZZES; qz_num++)
            sum = sum + grade[st_num - 1][qz_num - 1];
        st_ave[st_num - 1] = sum / NUMBER_QUIZZES;
    }
}
// note that qz_ave is an array, qz_ave[0], [1], [2]
void compute_qz_ave(const int grade[][NUMBER_QUIZZES], double qz_ave[])
{
    for (int qz_num = 1; qz_num <= NUMBER_QUIZZES; qz_num ++ )
    {
        double sum = 0;
        for (int st_num = 1; st_num <= NUMBER_STUDENTS; st_num++)
        {
            sum = sum + grade[st_num - 1][qz_num - 1];
        }
        qz_ave[qz_num - 1] = sum / NUMBER_STUDENTS;
    }
}

void display(const int grade[][NUMBER_QUIZZES], const double st_ave[], const double qz_ave[])
{
    using namespace std;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << setw(10) << "Student"
         << setw(5) << "Ave"
         << setw(15) << "Quizzes\n";
    for (int st_num = 1; st_num <= NUMBER_STUDENTS; st_num ++)
    {
        cout << setw(10) << st_num
             << setw(5) << st_ave[st_num -1] << " ";
        for (int qz_num = 1; qz_num <= NUMBER_QUIZZES; qz_num ++)
            cout << setw(5) << grade[st_num-1][qz_num-1];
        cout << endl;
    }

    cout << "Quiz averages = ";
    for (int qz_num = 1; qz_num <= NUMBER_QUIZZES; qz_num ++)
        cout << setw(5) << qz_ave[qz_num - 1];
    cout << endl;
}
