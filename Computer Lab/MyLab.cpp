//The program could be used to track, by lab,
//which user is logged onto which computer.
#include<iostream>
#include"computerLab.h"
using std::cout; using std::cin; using std::endl;


int main()
{
	ComputerLab myLab;
	cout << "*Note: ID NUMBERS ARE 5 DIGITS LONG\n\n";
	myLab.setLabSize();
	myLab.setLab();
	int option,id,lab,station;
	do {
		myLab.menu(option);
	cout << endl;
		switch (option)
		{
		case 1:
			do {
				cout << "ID number: ";
				cin >> id;
			} while (!myLab.isValid(id));
			do {
				cout << "Lab: ";
				cin >> lab;
				cout << "Station: ";
				cin >> station;
				if (myLab.occupied(lab, station))
				{
					cout << "This station is occupied.\n";
					
				}
			} while (!myLab.isValid(lab, station)||myLab.occupied(lab,station));
			myLab.login(id, lab, station);
			myLab.display();
			cout << endl;
			break;

		case 2:
			do {
				cout << "Lab: ";
				cin >> lab;
				cout << "Station: ";
				cin >> station;
			} while (!myLab.isValid(lab, station));
			myLab.logout(lab, station);
			myLab.display();
			cout << endl;
			break;
		case 3:
			cout << "ID NUMBER: ";
			cin >> id;
			cout << "Search result: "; myLab.search(id);
			cout << "\n\n";
			break;
		case 4:
			break;
		default:
			cout << "invalid option!\n";
			break;
		}

		
	} while (option!=4);
	
}