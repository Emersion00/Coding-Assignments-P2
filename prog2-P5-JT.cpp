//***************************************************************************
//Programmer: Jadyn Taylor
//Program: 5
//Date: 10/20/22
//This program creates an employee class
//**************************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class Employee
{

public:

Employee();
void headings();
void processdata();
void printResults();

private:

int empNum;
int dept;
int month;
int day;
int year;
int yrsService;

};

//--------------------------------------------------------------------------------
Employee :: Employee()
{
empNum = 0;
dept = 0;
month = 0;
day = 0;
year = 0;
yrsService = 0;
};
//-------------------------------------------------------------------------------
void Employee :: headings()
{
cout << "     Employee Service Report                 " << endl;
cout << endl << endl;
cout << "Employee                                 Years of " << endl;
cout << "Number      Dept#      Hire Date:        Service: ";
cout << endl << endl;
}
//---------------------------------------------------------------------------------
void Employee :: processdata()
{
ifstream inputFile;
inputFile.open("emp.dat");
if (inputFile.fail())
 {
  cout << "ERROR: Can't open file emp.dat" << endl;
  exit(0);
 }

inputFile >> empNum >> dept >> month >> day >> year;

while(!inputFile.eof())
{
yrsService = 2022 - year;
printResults();
inputFile >> empNum >> dept >> month >> day >> year;
}
inputFile.close();

}
//------------------------------------------------------------------------------------
void Employee :: printResults()
{
cout << setw(6) << empNum << setw(10) << dept << right << setw(8) << month << "/" << setw(2) << day << "/" << setw(2) << year << setw(13) << yrsService << endl;
}
//------------------------------------------------------------------------------------

int main()
{

Employee emp;

emp.headings();
emp.processdata();


return 0;
}
