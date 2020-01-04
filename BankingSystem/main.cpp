#include<iostream>
#include"bankRecord.h"

using std::string; using std::cout; using std::cin; using std::endl;

int main()
{
	BankRecord myRecord;
	int option;
	int accountNumber;
	cout << "***FUTURE BANK RECORD SYSTEM***\n\n";
	do
	{
		myRecord.menu(option);
		cout << endl;
		switch (option)
		{
		case 1:
			myRecord.addAccount();
			cout << endl;
			break;

		case 2:
			
				cout<<"Account Number: ";
			cin >> accountNumber;
			myRecord.showRecord(accountNumber);
			cout << endl;
			break;

		case 3:
			
			cout << "Enter the record number to be searched:-\n\n"
				<< "Account Number: ";
			cin >> accountNumber;
			myRecord.search(accountNumber);
			cout << endl;
			break;

		case 4:
			cout << "The record contains " << myRecord.getNumberOfAccounts() << " accounts in the file\n";
			cout <<"Enter record number to edit:\n"
				<< "Account Number: ";
			cin >> accountNumber;
			myRecord.updateRecord(accountNumber);
			cout << endl;
			break;

		case 5:
			myRecord.mergeAccounts();
			cout << "Records are merged successfully\n";
			cout << endl;
			break;

		case 6:
			
			cout << "Account Number: ";
			cin >> accountNumber;
			myRecord.deleteRecord(accountNumber);
			cout << "Record is deleted.";
			cout << endl;
			break;

		case 7:
			break;
		}
		
		
	} while (option != 7);
	 
}