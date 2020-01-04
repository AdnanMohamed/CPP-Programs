#include<iostream>
#include"bankRecord.h"

using std::string; using std::cout; using std::cin; using std::endl;

void Profile::setDate(Date date)
{
	dateOfBirth_ = date;
	if ((dateOfBirth_.month_ < DATE_.month_) ||
		(dateOfBirth_.month_ == DATE_.month_ && dateOfBirth_.day_ <= DATE_.day_))
		age_ = DATE_.year_ - dateOfBirth_.year_;
	else
		age_ = DATE_.year_ - (dateOfBirth_.year_ + 1);
}

Profile::Profile(string fn, string ln, Date date, char g)
{
	firstName_ = fn;
	lastName_ = ln;
	setDate(date);
	gender_ = g;
}

BankAccount operator+(const BankAccount acc1,const BankAccount acc2)
{
	BankAccount temp;
	temp.setFirst(acc1.getFirst());
	temp.setLast(acc1.getLast());
	temp.accountNumber_ = acc1.accountNumber_;
	temp.balance_ = acc1.balance_ + acc2.balance_;
	return temp;
}

BankRecord::BankRecord()
{
	n = 0;
	bankAccounts_ = new BankAccount[n];
}

void BankRecord::menu(int& option)
{
	cout << "Select from the options below:-\n";
	cout << "1- Add a record to file\n"
		<< "2- Show record from file\n"
		<< "3- Search record from file\n"
		<< "4- Update record\n"
		<< "5- Merge records\n"
		<< "6- Delete record\n"
		<< "7- Quit\n"
		<< "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
	do {
		cout << "Option: ";
		cin >> option;
		newline();
		if (option > 7 || option < 1)
			cout << "invalid option!\n";
	} while (option > 7 || option < 1);
}

int BankRecord::match(int accNumber)
{
	for (int i = 0; i < n; ++i)
	{
		if (accNumber == bankAccounts_[i].getAccountNumber())
			return i;
	}
	return -1;
}


void BankRecord::addAccount()
{
	string first, last;
	int accNumber;
	double balance;
	
	++n;
	BankAccount* newRecord = new BankAccount[n];
	for (int i = 0; i < n-1; ++i)
	{
		newRecord[i] = bankAccounts_[i];
	}
	cout << "Please provide us with the following information:-\n";
	cout << "First Name: "; cin >> first;
	newRecord[n-1].setFirst(first);
	cout << "Last Name: "; cin >> last;
	newRecord[n-1].setLast(last);
	cout << "Account Number: "; cin >> accNumber;
	newRecord[n-1].setAccountNumber(accNumber);
	cout << "Balance: $"; cin >> balance;
	newRecord[n - 1].setBalance(balance);
	
	delete[]bankAccounts_;
	bankAccounts_ = newRecord;
	cout << "New record is added.";
	cout << endl;
}
void BankRecord::showRecord(int accNumber)
{
	
	int index = match(accNumber);
	if (index != -1)
	{
		cout << "--------------------------\n"
			<< "--------------------------\n";
		cout << "Account Number: " << bankAccounts_[index].getAccountNumber() << endl;
		cout << "First Name: " << bankAccounts_[index].getFirst() << endl;
		cout << "Last Name: " << bankAccounts_[index].getLast() << endl;
		cout << "Balance: $" << bankAccounts_[index].getBalance() << endl;
		cout << "--------------------------\n"
			<< "--------------------------\n";
	}
	else
		cout << "Account does not exist in this record!";
	cout << endl;
}
void BankRecord::search(int accNumber)
{
	showRecord(accNumber);
}
void BankRecord::updateRecord(int accNumber)
{
	
	int index = match(accNumber);
	string first, last;
	double balance;
	if (index != -1)
	{
		showRecord(accNumber);
		cout << endl;
		cout << "Modify Record:\n";
		cout << "First Name: "; cin >> first;
		bankAccounts_[index].setFirst(first);
		cout << "Last Name: "; cin >> last;
		bankAccounts_[index].setLast(last);
		cout << "Account Number: " << accNumber << endl;
		cout << "Balance: $"; cin >> balance;
		bankAccounts_[index].setBalance(balance);
		cout << endl;
		cout << "Record is updated.";
	}
	else
		cout << "Account does not exist in this record!";
	cout << endl;
}
void BankRecord::mergeAccounts()
{
	int numberOfRecords;
	cout << "How many records you would like to merge?\n";
	cin >> numberOfRecords;
	int* records = new int[numberOfRecords];
	int* indices = new int[numberOfRecords];
	int temp;
	int index;
	for (int i = 0; i < numberOfRecords; ++i)
	{
		do
		{
			cout << "Record Number: ";
			cin >> temp;
			index = match(temp);
			if (index == -1)
				cout << "invalid record\n";
		} while (index == -1);
		records[i] = temp;
		indices[i] = index;
	}
	
	for (int i = 1; i < numberOfRecords; ++i)
	{
		bankAccounts_[indices[0]] = bankAccounts_[indices[0]] + bankAccounts_[indices[i]];
		
	}
	for (int i = 1; i < numberOfRecords; ++i)
	deleteRecord(records[i]);
	
}
void BankRecord::deleteRecord(int accNumber)
{
	
	int index;
	
		index = match(accNumber);
		if (index != -1)
		{
			BankAccount* newRecord = new BankAccount[n - 1];
			for (int i = 0, j = 0; i < n; ++i)
			{
				if (i != index)
				{
					newRecord[j] = bankAccounts_[i];
					++j;
				}
			}
			delete[]bankAccounts_;
			--n;
			bankAccounts_ = newRecord;
		}
		else
			cout << "invalid record\n";
	cout << endl;
}

void newline()
{
	char next;
	do
	{
		cin.get(next);
	} while (next != '\n');

}
