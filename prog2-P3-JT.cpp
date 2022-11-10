//****************************************************************
//Programmer: Jadyn Taylor
//Course: Programming II 2414
//Program: 3
//Date:9/15/2022
//Purpose:Display user's ID number, hours worked, and salary rate 
//****************************************************************
#include <iostream>
#include <iomanip>
using namespace std;


class Employee
{
private:
        int idNumber;
        double hours;
        double rate;
public:
        Employee();
        void setidNumber();
        void sethours();
        void setrate();
        void headings();
        void printSalary();
};
        Employee::Employee() //Default Constructor
       {
        idNumber = 0;
        hours = 0;
        rate = 0;
       }
//-------------------------------------------------------
       void Employee::setidNumber()
      {
       cout << "Enter your ID number: " << endl;
       cin >> idNumber;
      }
//-------------------------------------------------------
       void  Employee::sethours()
      {
       cout << "Enter how many hours you have: " << endl;
       cin >> hours;
      }
//-------------------------------------------------------
       void  Employee::setrate()
      {
       cout << "Enter your hourly rate: " << endl;
       cin >> rate;
      }
//-------------------------------------------------------
       void  Employee::headings()
      {
       cout << endl << endl;
       cout << setw(8) << "ID#" << setw(8) << "Hours" << setw(6) << "Rate" << setw(8) << "Salary" << endl;
       cout << "===================================" << endl << endl;
      }
//---------------------------------------------------------
       void Employee::printSalary()
      {
       double salary = 0;    

       cout << fixed << showpoint << setprecision(2);
       cout << setw(8) << idNumber;
       cout << setw(8) << hours;
       cout << setw(6) << rate;
       salary = hours * rate;
       cout << setw(8) << salary;
      }
//----------------------------------------------------------
int main()
{

  
   Employee empData;
   
   
   empData.setidNumber();
   empData.sethours();
   empData.setrate();
   empData.headings();
   empData.printSalary();
   cout << endl << endl;

return 0;
}
