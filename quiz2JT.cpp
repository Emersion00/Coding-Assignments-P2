//Quiz 2 - Patient Hospital Report
// Jadyn Taylor
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class Patient
{
private:
   int patientNum;
   string lname, fname;
   char typeStay;
   string insCompany;
   double insDeduct;
   double currentChgs;
   double remainDeduct;
   
public:
   Patient();     //default constructor
   void headings();
   void processData();
   void printResults();
   
};

//*******************************************************************************

Patient :: Patient()            //Constructor
{
	patientNum = 0;
	lname = "";
	fname = "";
	typeStay = ' ';
	insCompany = "";
	insDeduct = 0;
	currentChgs = 0;
	remainDeduct = 0;
}



//*******************************************************************************

void Patient::headings()
{
 cout << endl << endl << endl;
 cout << setw(52) << "Patient Hospital Report" << endl << endl;
 cout << setw(35) << "Type" << setw(17) << "Insurance" << setw(15) << "Insurance"
      << setw(11) << "Current" << setw(12) << "Remaining" << endl;
 cout << setw(7) << "Patient" << setw(10) << "Name" << setw(18)
      << "Stay" << setw(16) << "Company" << setw(16) << "Deductable" << setw(11)
      << "Charges" << setw(13) << "Deductable" << endl << endl;
}
//*******************************************************************************

void Patient :: processData()
{
	ifstream inputFile;
	inputFile.open("patient.dat");
	if (inputFile.fail())
	{
		cout << "ERROR: Can't open patient.dat file" << endl;
		exit(0);
	}
	cout << endl << endl;
	inputFile >> patientNum >> lname >> fname >> typeStay >> insCompany >> insDeduct >>currentChgs;
	while (!inputFile.eof())
	{
		remainDeduct = insDeduct - currentChgs;
		
		printResults();
		
		inputFile >> patientNum >> lname >> fname >> typeStay >> insCompany >> insDeduct >>currentChgs;
	}
	inputFile.close();
}
//*************************************************************************************

void Patient :: printResults()
{
	string stay;
	if (typeStay == 'O')
	stay = "Outpatient";
	else 
	stay = "Over night";
	
	if (remainDeduct < 0)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << patientNum << "  " << "*" << left << setw(10) << lname << setw(10) << fname << setw(15) << stay << setw(15) << insCompany << setw(12) << insDeduct << setw(10) << currentChgs << setw(8) << right << remainDeduct << endl;
	}
	else
	{
		cout << fixed << showpoint << setprecision(2);
		cout <<  patientNum << "   " << left << setw(10) << lname << setw(10) << fname << setw(15) << stay << setw(15) << insCompany << setw(12) << insDeduct << setw(10) << currentChgs << setw(8) << right << remainDeduct << endl;
	}
}
//******************************************************************************************

int main()
{
	Patient report;
	
	report.headings();
	report.processData();
	
	cout << endl << endl;
	cout << "*-Person has met their deductible" << endl;	

	return 0;
}
