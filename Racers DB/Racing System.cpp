//This program allows the user to enquire information
//about a racer by typing his/her name. The program will 
//output overall finish position, time between sensors,
//overall racetime, overall pace.
//
//Adnan Mohamed
//11-24-2019
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Racer.h"

using std::cout; using std::cin; using std::endl;
using std::ios; using std::ifstream;
int main()
{
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(3);

	ifstream fin1("Racers Info.txt"), fin2("Race Record.txt");
	if (fin1.fail())
	{
		cout << "Failed opening \"Racers Info.txt\"";
		exit(1);
	}

	if (fin2.fail())
	{
		cout << "Failed opening \"Race Record.txt\"";
		exit(1);
	}

	
	vector<Racer>race;
	
	setRace(fin1, race);
	blastoff(fin2, race);
	string choice;
	int number;
	Name name;
	char reply;
	int index;
	do {
		cout << "Do you want to search by number of name?\n";
		do {
			cout << "type either (number / name) : ";
			cin >> choice;
			newline(cin);
		} while (choice != "number" && choice != "name");
		if (choice == "name")
		{
			cout << "Enter Name: ";
			cin >> name.fName_ >> name.lName_;
			cout << endl;
			cout << "Search Result:-\n";
			index = getIndex(race, name);
			if (index > 0)
				cout << race[index];
			else
				cout << "NOT FOUND";
		}
		else if (choice == "number")
		{
			cout << "Enter Number: ";
			cin >> number;
			cout << endl;
			cout << "Search Result:-\n";
			index = getIndex(race, number);
			if (index > 0)
				cout << race[index];
			else
				cout << "NOT FOUND";
		}
		cout << endl;
		cout << "do you want to search again? (yes/no): ";
		cin >> reply;
		newline(cin);
	} while (reply == 'y' || reply == 'Y');
	cout << endl;
	
}