//********************************************************************************
//Programmer: Jadyn Taylor
//Course: Programming II
//Program: 2
//Date: 9/1/2022
//Purpose: Calculates the average number of days a company's employees are absent
//********************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
void numEmployees(int &emp);
void inputAbsences(int &emp, double &avg, int &sum);
void printResults(int emp, int sum, double avg);
//********************************************************************************
int main()
{
int emp;
double avg;
int sum;

numEmployees(emp);
inputAbsences(emp, avg, sum);
printResults(emp, sum, avg);

return 0;
}
//Function Implementation
//**********************************************************************************
void numEmployees(int &emp)
{
cout << "How many employees does the company have?" << endl;
cin >> emp;
    while(emp < 1)
    {
    cout << "Error: number of employees cannot be less than 1." << endl;
    cin >> emp;
    }
}
//**********************************************************************************
void inputAbsences(int &emp, double &avg, int &sum)
{
   sum = 0.0;
   int abs;

    for (int x=1 ; x <= emp; x++)
   {
   cout << "How many absences does employee #" << x << " have?" << endl;
   cin >> abs;
       while(abs < 0)
       {
       cout << "Error: absenses cannot be a negative number." << endl;
       cin >> abs;
       }
   sum = sum + abs;
    }
   avg = (sum/emp);
}
//**********************************************************************************
void printResults(int emp, int sum, double avg)
{
  cout << fixed << showpoint << setprecision(2);
  cout << "The total number of employees is:     " << emp << endl;
  cout << "The total number of absenses is:      " << sum << endl;
  cout << "The average absenses per employee is: " << avg << endl;
}
//**********************************************************************************

