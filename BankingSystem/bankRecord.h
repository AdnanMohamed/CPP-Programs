#ifndef bankRecord_
#define bankRecord_
#include<string>
using std::string;
class Date
{
public:
	Date() { month_ = 11; day_ = 10; year_ = 2019; } //default constructor that sets date to today's date
	Date(int m, int d, int y) :month_(m), day_(d), year_(y) { }
	int month_;
	int day_;
	int year_;
};

class Profile {
public:
	Profile(string, string, Date, char);
	Profile() { }
	void setFirst(string firstN) { firstName_ = firstN; }	//This function sets the first Name to the given argument
	void setLast(string lastN) { lastName_ = lastN; }		//This function sets the Last Name to the given argument

	void setDate(Date date);				//date should have values for month,day,year. 
											//The function sets the date of birth equals the argument gives a value to age_
	void setGender(char g) { gender_ = g; }

	string getFirst() const{ return firstName_; }      //
	string  getLast() const{ return lastName_; }        //These are accessors that return the
	Date  getDate() const{ return dateOfBirth_; }		// value of the specified attributes
	char  getGender() const{ return gender_; }			//
	int  getAge() const { return age_; }					//

private:
	string firstName_;
	string lastName_;
	Date dateOfBirth_;
	int age_;
	char gender_;

};

class BankAccount :public Profile {
public:
	BankAccount(int accountNumber,double balance)			//constructor sets the private members
		:accountNumber_(accountNumber),balance_(balance){}
	BankAccount(){}  

	void setAccountNumber(int accountNumber) { accountNumber_ = accountNumber; }
	void setBalance(double balance) { balance_ = balance; }

	int getAccountNumber(){ return accountNumber_; }
	double getBalance() { return balance_; }

	friend BankAccount operator+(const BankAccount acc1,const BankAccount acc2);
	//acc1 and acc2 have values. 
	//Postcondition: returns an object of type bank account which have the sum
	//of the balance in acc1 and acc2. and holds acc1's account number.
private:
	int accountNumber_;
	double balance_; //amount in $
};

class BankRecord:public BankAccount{
public:
	BankRecord();
	void menu(int& option);
	//displays a menu with option.
	//saves user's input in option
	void addAccount();//This function adds an account to *bankAccounts and increment n
	void showRecord(int accNumber);//
									//accNumber contains the value of the account number.
								   //The info of this account will be displayed
	void search(int accNumber);		//

	void updateRecord(int accNumber);//accNumber contains the value of the account number.
									 //the account will be edited by the user
	void mergeAccounts();
	//Asks the user of number of accounts to merge.
	//The user enters account numbers. The accounts will be merged to the first account entered.
	//The other accounts will be deleted.
	void deleteRecord(int accNumber);
	//accNumber contains the value of the account number.
	//The account holding this number will be deleted from the record
	int getNumberOfAccounts() { return n; }//returns number of accounts in record
private:
	int n;//number of accounts in the record
	BankAccount* bankAccounts_;
	int match(int accNumber);
	//returns the index of the matching record
	//otherwise -1
};

void newline();

const Date DATE_; //Today's date

#endif
