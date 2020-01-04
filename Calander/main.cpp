//This program lets the user enter a certain date
//and give hime the name of that day (sun,mon...)
#include<iostream>
#include"header.h"
using std::cout; using std::cin; using std::endl;

int main()
{
	char reply;
	int month, day, year;
	string name;

	cout << "Enter the date starting with month, day, and then year.\n\n";
		

	do {
		getInput(month, day, year);

		dayName(month, day, year, name);
		if (dateIsValid(month, day, year))
		{
			cout << "It is " << name << "!!\n\n";
			
		}
		else
		{
			cout << "Sorry this date is invalid.\n";
		}
		cout << "Do you want to try again?(yes/no)\n";
		cin >> reply;
		newline();
		cout << "\n\n";
	} 
	while (reply == 'y' || reply=='Y');

	cout << "I hope this was helpful.\n\n"
		<< "Keep smiling! Have a nice day!!\n\n";
}