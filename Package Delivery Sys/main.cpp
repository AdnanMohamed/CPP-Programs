#include<iostream>
#include"packageSystem.h"

using std::cout; using std::cin; using std::endl;

int main()
{
	cout << "*Note: Ordinary packages includes all kinds of packages : normal, overnight, two day packages.\n"
		<< "However, if you choose to view ordinary packages you will not see the total cost if there are\n"
		<< "additional fees. To see the total cost, specify the type of the package.\n\n";
	int option;
	Packages dhlPackages;
	OvernightPackages dhlOvernightPackages;
	TwoDayPackages dhlTwoDayPackages;
	fillPackages(dhlPackages, dhlOvernightPackages, dhlTwoDayPackages);

	do
	{
		menu(option);
		cout << endl;
		switch (option)
		{
		case 1:
			addPackage(dhlPackages, dhlTwoDayPackages, dhlOvernightPackages);
			cout << endl;
			break;

		case 2:
			removePackage(dhlPackages, dhlTwoDayPackages, dhlOvernightPackages);
			cout << endl;
			break;

		case 3:
			editRecord(dhlPackages, dhlTwoDayPackages, dhlOvernightPackages);
			cout << endl;
			break;

		case 4:
			searchRecord(dhlPackages, dhlTwoDayPackages, dhlOvernightPackages);
			cout << endl;
			break;

		case 5:
			viewRecords(dhlPackages, dhlTwoDayPackages, dhlOvernightPackages);
			cout << endl;
			break;

		case 6:
			sendtoFile(dhlPackages, dhlTwoDayPackages, dhlOvernightPackages);
			cout << endl;
			break;

		case 7:
			break;
		}
		cout << endl;

	} while (option != 7);
}