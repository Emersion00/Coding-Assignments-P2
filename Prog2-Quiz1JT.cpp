//*****************************************************************************************
//Programmer: Jadyn Taylor
//Course: Programming II
//Quiz: 1
//Date: 9/27/2022
//Purpose: Calculate and display the distance a car can travel on one tank of gas.
//*****************************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
void getmileInfo(int &size,double &MPGtown,double &MPGhighw);
void calcResults(double &distanceX,double &distanceY, int &size,double &MPGtown,double &MPGhighw);
void printResults(double distanceX,double distanceY,int size,double MPGtown,double MPGhighw);
//*****************************************************************************************
int main()
{
double distanceX, distanceY, MPGtown, MPGhighw;
int size;

getmileInfo(size, MPGtown, MPGhighw);
calcResults(distanceX, distanceY, size, MPGtown, MPGhighw);
printResults(distanceX, distanceY, size, MPGtown, MPGhighw);

return 0;
}
//Function Implementation
//*****************************************************************************************
void getmileInfo(int &size, double &MPGtown, double &MPGhighw)
{
 cout << "What size is the car's gas tank?" << endl;
 cin >> size;
     while(size < 0)
     {
      cout << "Error: Input value must not be negative." << endl;
      cout << "Please try again:" << endl;
      cin >> size;
     }
 cout << "What gas mileage do you get (in town)?" << endl;
 cin >> MPGtown;
     while(MPGtown < 0)
     {
      cout << "Error: Input value must not be negative." << endl;
      cout << "Please try again:" << endl;  
      cin >> MPGtown;
     }
 cout << "What gas mileage do you get (on the highway)?" << endl;
 cin >> MPGhighw;
     while(MPGhighw < 0)
     {
      cout << "Error: Input value must not be neagtive." << endl;
      cout << "Please try again:" << endl;
      cin >> MPGhighw;
     }
}
//*****************************************************************************************
void calcResults(double &distanceX, double &distanceY, int &size, double &MPGtown, double &MPGhighw)
{
 distanceX = size * MPGtown;
 distanceY = size * MPGhighw;
}
//*****************************************************************************************
void printResults(double distanceX, double distanceY, int size, double MPGtown, double MPGhighw)
{
 cout << fixed << showpoint << setprecision(1);
 cout << setw(20) << "TABLE" << endl;
 cout << "<<**************************************>>" << endl;
 cout << "Size of Tank" << setw(10) << "MPG Town" << setw(14) << "MPG Highway" << endl;
 cout << setw(6) << size << setw(14) << distanceX << setw(12) << distanceY << endl;
 cout << "<<**************************************>>" << endl;
}

