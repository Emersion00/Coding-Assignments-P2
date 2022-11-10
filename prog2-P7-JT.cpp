//***********************************************************
//Programmer: Jadyn Taylor
//Course: Programming II
//Date: 11/7/2022
//Purpose: Creates a Sales class for a sales report
//***********************************************************
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Sales
{
	private:
		
		int salesNum;
		int month;
		int day;
		int year;
		double salesAmt;
		char vehicle;
		double commission;
		double salesTotal[4];
		double comTotal[4];
		double vehicleTotal[3];
		string description[3];
		
	public:
		Sales();
		void headings();
		void processdata();
		void calcCommission();
		void printResults();
		void calcTotals();
		void printTotals();
	
};
//********************************************************************
//Function Implementation

Sales::Sales()            //Constructor
{
	salesNum = 0;
	month = 0;
	day = 0;
	year = 0;
	salesAmt = 0;
	commission = 0;
	description[0] = "Cars";
	description[1] = "Trucks";
	description[2] = "Used";
	
	for (int y = 0; y < 4; y++)
	{
		salesTotal[y] = 0;
	}
	
	for (int y = 0; y < 4; y++)
	{
		comTotal[y] = 0;
	}
	
	for (int y = 0; y < 3; y++)
	{
		vehicleTotal[y] = 0;
	}
}
//*************************************************************************

void Sales :: headings()
{
	cout << "                Sales Commission Report" << endl;
	cout << endl << endl;
	cout << setw(12) << "C - Cars" << setw(12) << "T - Trucks" << setw(12) << "U - Used" << endl;
	cout << endl << endl;
	cout << "Sales" << setw(21) << "Sales" << setw(12) << "Sales" << setw(11) << "Vehicle" << endl;
	cout << setw(2) << "ID" << setw(13) << "Date" << setw(12) << "Amount" << setw(13) << "Commission" << setw(8) << "Type" << endl;
	cout << endl << endl;
}
//**************************************************************************

void Sales :: processdata()
{
	ifstream inputFile;
	inputFile.open("sales.dat");
	if (inputFile.fail())
	{
		cout << "ERROR: Can't open file sales.dat" << endl;
		exit(0);
	}
	cout << endl << endl;
	inputFile >> salesNum >> month >> day >> year >> salesAmt >> vehicle;
	while (!inputFile.eof())
	{	
		calcTotals();
		calcCommission();
		printResults();

		inputFile >> salesNum >> month >> day >> year >> salesAmt >> vehicle;
	}
	inputFile.close();
}
//****************************************************************************************
void Sales :: calcCommission()
{	
	if(salesNum == 10)
	{
	if (salesAmt > 0 && salesAmt <= 12000)
	{
	commission = salesAmt * 0.02;
	}
	else if (salesAmt >= 12001 && salesAmt <= 17000)
	{
	commission = salesAmt * 0.04;
	}
	else if (salesAmt >= 17001 && salesAmt <= 25000)
	{
	commission = salesAmt * 0.05;
	}
	else if (salesAmt >= 25001 && salesAmt <= 40000)
	{
	commission = salesAmt * 0.06;
	}
	else
	{
	commission = salesAmt * 0.07;
	}
	comTotal[0] = comTotal[0] + commission;
	}
	
	else if(salesNum == 11)
	{
	if (salesAmt > 0 && salesAmt <= 12000)
	{
	commission = salesAmt * 0.02;
	}
	else if (salesAmt >= 12001 && salesAmt <= 17000)
	{
	commission = salesAmt * 0.04;
	}
	else if (salesAmt >= 17001 && salesAmt <= 25000)
	{
	commission = salesAmt * 0.05;
	}
	else if (salesAmt >= 25001 && salesAmt <= 40000)
	{
	commission = salesAmt * 0.06;
	}
	else
	{
	commission = salesAmt * 0.07;
	}
	comTotal[1] = comTotal[1] + commission;
	}
	
	else if(salesNum == 12)
	{
	if (salesAmt > 0 && salesAmt <= 12000)
	{
	commission = salesAmt * 0.02;
	}
	else if (salesAmt >= 12001 && salesAmt <= 17000)
	{
	commission = salesAmt * 0.04;
	}
	else if (salesAmt >= 17001 && salesAmt <= 25000)
	{
	commission = salesAmt * 0.05;
	}
	else if (salesAmt >= 25001 && salesAmt <= 40000)
	{
	commission = salesAmt * 0.06;
	}
	else
	{
	commission = salesAmt * 0.07;
	}
	comTotal[2] = comTotal[2] + commission;
	}

	else
	{
	if (salesAmt > 0 && salesAmt <= 12000)
	{
	commission = salesAmt * 0.02;
	}
	else if (salesAmt >= 12001 && salesAmt <= 17000)
	{
	commission = salesAmt * 0.04;
	}
	else if (salesAmt >= 17001 && salesAmt <= 25000)
	{
	commission = salesAmt * 0.05;
	}
	else if (salesAmt >= 25001 && salesAmt <= 40000)
	{
	commission = salesAmt * 0.06;
	}
	else
	{
	commission = salesAmt * 0.07;
	}
	comTotal[3] = comTotal[3] + commission;
	}
}
//******************************************************************************************
void Sales :: printResults()
{

	cout << fixed << showpoint << setprecision(2);
	cout << salesNum << setw(6) << month << "/" << setw(2) << day << "/" << year << setw(12) << salesAmt << setw(10) << commission << setw(8) << vehicle << endl;
}
//******************************************************************************************
void Sales :: calcTotals()
{
	if(salesNum == 10)
	{
		salesTotal[0] = salesTotal[0] + salesAmt;
	}
	
	else if(salesNum == 11)
	{
		salesTotal[1] = salesTotal[1] + salesAmt;
	}
	
	else if(salesNum == 12)
	{
		salesTotal[2] = salesTotal[2] + salesAmt;
	}
	
	else
	{
		salesTotal[3] = salesTotal[3] + salesAmt;
	}
	
	if (vehicle == 'C')
	{
		vehicleTotal[0] = vehicleTotal[0] + salesAmt;
	}
	
	else if(vehicle == 'T')
	{
		vehicleTotal[1] = vehicleTotal[1] + salesAmt;
	}
	
	else
	{
		vehicleTotal[2] = vehicleTotal[2] + salesAmt;
	}
}
//**************************************************************************************

void Sales :: printTotals()
{
	cout << endl << "               Total by Sales ID" << endl << endl;
	
	for (int i = 0; i < 4; i++)
	{
		cout << setw(4) << i+10 << setw(15) << salesTotal[i] << setw(15) << comTotal[i] << endl;
	}
	
	cout << endl << endl;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "      " << left << setw(6) << description[i] << right << setw(17) << vehicleTotal[i] << endl;
	}
	
	cout << endl << endl;
}
//****************************************************************************************
int main()
{
	Sales report;
	
	report.headings();
	report.processdata();
	report.printTotals();
	
	return 0;
}





