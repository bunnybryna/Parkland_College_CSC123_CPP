// 7.13 two-dimensional array
#include <iostream>
#include <iomanip>
#include <cmath>
const int NUMBER_STUDENTS =4, NUMBER_QUIZZES = 3;

void fill_array(int a[][3],int row, int column);

void compute_st_ave(const int grade[][NUMBER_QUIZZES], double st_ave[]);

void compute_qz_ave(const int grade[][NUMBER_QUIZZES], double qz_ave[]);

void display(const int grade[][NUMBER_QUIZZES]);

int main()
{
    using namespace std;
    int grade[NUMBER_STUDENTS][NUMBER_QUIZZES];
    double st_ave[NUMBER_STUDENTS];
    double qz_ave[NUMBER_QUIZZES];


    fill_array(grade,NUMBER_STUDENTS,NUMBER_QUIZZES);
    compute_st_ave(grade, st_ave);
    compute_qz_ave(grade, qz_ave);
    display(grade);

    return 0;
}
void fill_array(int a[][3],int row, int column)
{
    using namespace std;

    for (int i=0; i<row; i++)
    {
        cout << "Enter quiz scores for student " << i+1 << endl
              << "Mark the end with a negative number.\n";
        for (int j=0; j<column; j++)
        {
            int next=0;
            cin >> next;
            if (next>=0)  /// good data
            {
                a[i][j] = next;
            }
            else
            {
                break;
            }
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
