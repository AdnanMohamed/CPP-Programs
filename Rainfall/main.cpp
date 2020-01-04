// The program reads in the average monthly rainfall for a city for each month of the year
//and then reads in the actual monthly rainfall for each of the previous 12 months.
//The program prints out a table or a graph about the data given depending on the choice of the user.

#include<iostream>
#include<string>
#include"proto.h"

using std::cout; using std::cin; using std::endl;
using std::string;

int main()
{
	string city;
	int currentMonth;

	cout << "What is the name of the city?\n";
	cin >> city;
	cout << endl;

	cout << "What is the current month?(in numbers)\n";
	cin >> currentMonth;
	newline(); cout << endl;
	currentMonth -= 1;

	double avgMonthlyRainfall[MONTHS];
	cout << "Provide us with the average monthly rainfall\n"
		<< "for each month of the year starting from Jan. up to Dec.\n"
		<< "Enter the averages: "; fillUp(avgMonthlyRainfall, MONTHS);
		
	double monthlyRainfall[MONTHS];
	cout << "Enter the figures for the actual monthly rainfall\n"
		<< "for each month starting from last " << month(currentMonth) 
		<<" up to previous month "<< month(currentMonth-1)<< endl;
	cout << "Enter the figures: ";
	fillUpModify(monthlyRainfall, MONTHS,currentMonth);
	cout << endl;
	
	char answer;
	do
	{
		cout << "enter (t) to see the table, (g) to see the graph or (e) to exit: ";
		cin>>answer; newline();
		cout << "\n";
		if (answer == 't' || answer == 'T')
		{
			showTable(monthlyRainfall, avgMonthlyRainfall);
			cout << "\n";
		}
		else if (answer == 'g' || answer == 'G')
		{
			graph(monthlyRainfall, avgMonthlyRainfall);
			cout << "\n";
		}
		
	} while (answer != 'e' && answer != 'E');
	
}