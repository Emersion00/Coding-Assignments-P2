//*************************************************************************************************
//Programmer: Jadyn Taylor
//Course: Programming 2
//Program: 6
//Date: 10/26/2022
//Description: This program generates a standings report for the Premiere League as of Sept. 2021
//*additional file needed to find league data
//*************************************************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class Soccer
{

private:

 int wins[20];
 int draws[20];
 int points[20];
 string club[20];
 int i;

public:
 
 Soccer();
 void readFiles();
 void computePoints();
 void printStandings();
 void sort();
 void swap();
 void swapstr();

};
//------------------------------------------------------
//Function Implementation

Soccer::Soccer()
{
 for (int i = 0; i < 20; i++)
 {
   club[i] = "empty";
 }

 for (int i = 0; i < 20; i++)
 {
  wins[i] = 0;
 }
 
 for (int i = 0; i < 20; i++)
 {
  draws[i] = 0;
 }
 
 for (int i = 0; i < 20; i++)
 {
  points[i] = 0;
 }
}
//------------------------------------------------------

void Soccer::readFiles()
{
//8888888888Clubs88888888888888888888888888888888888888888
 ifstream inputFile;

 inputFile.open("club.dat");

 if(inputFile.fail())
   {
    cout << "ERROR: Unable to open filename club.dat" <<endl;
    exit(0);
   }

 for (int i = 0; i < 20; i++)
 {
  inputFile >> club[i];
 }
 
 inputFile.close();
//888888888888Wins888888888888888888888888888888888888
 
 inputFile.open("wins.dat");

 if (inputFile.fail())
 {
  cout << "ERROR: Unable to open filename wins.dat" << endl;
  exit(0);
 }

 for (int i = 0; i < 20; i++)
   {
     inputFile >> wins[i];
   }
 inputFile.close();
//8888888888Draws88888888888888888888888888

 inputFile.open("draws.dat");
 
 if (inputFile.fail())
    { 
     cout << "ERROR: Unable to open filename draws.dat" << endl;
     exit(0);
    }
 
  for (int i = 0; i < 20; i++)
   {
    inputFile >> draws[i];
   }

   inputFile.close();

}
//-------------------------------------------------------------
void Soccer::computePoints()
{
   for (int i = 0; i < 20; i++)
     {
       points[i] = (wins[i] * 3) + draws[i];
     }
}
//--------------------------------------------------------------
void Soccer::printStandings()
{
 
 cout << "Premier League          September 2022" << endl;
 cout << "   Club                Pts  Wins  Draws" << endl;
 cout << "----------------------------------------------" << endl;
 
 for (int i = 0; i < 20; i++)
  { 
   cout << setw(2) << i+1 << " " << left << setw(17) << club[i] <<" " << right << setw(5) << points[i] << " " << setw(5) << wins[i] <<" " << setw(5) << draws[i] << " "  << endl;
  }
cout << endl;
}
//----------------------------------------------------------------------------------------------------

void Soccer::sort()
{
 int size = 20;

 for (int last = size - 1; last > 0; last--)
  {
   for ( i = 0; i < last; i++)
    {
     if (points[i] < points[i+1])
      { 
        swap();
        swapstr();
      }
    }
  }
}
//------------------------------------------------------------------------------------------------------

void Soccer::swap()
{
int temp = points[i];
points[i] = points[i+1]; 
points[i+1] = temp;

int temp2 = wins[i];
wins[i] = wins[i+1];
wins[i+1] = temp2;

int temp3 = draws[i];
draws[i] = draws[i+1];
draws [i+1] = temp3;

}
//------------------------------------------------------------------------------------------------------

void Soccer::swapstr()
{
string temp4 = club[i];
club[i] = club[i+1];
club[i+1] = temp4;
}
//------------------------------------------------------------------------------------------------------

int main()
{
  Soccer league;

  league.readFiles();
  league.computePoints();
  league.sort();
  league.printStandings();

  

  return 0;
}
