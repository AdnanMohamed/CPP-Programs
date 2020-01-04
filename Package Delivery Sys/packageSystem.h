#ifndef PACKAGESYSTEM_H
#define PACKAGESYSTEM_H
#include<fstream>
#include<string>
#include<vector>


using std::string; using std::istream; using std::ostream;
using std::vector;

struct Address {
	string street_;
	string city_;
	string state_;
	int zipcode_;
};

class Package {
public:
	Package(int n, string sender, string receiver, Address senderAdd, Address receiverAdd, double w, double c);
	Package();
	//The default constructor initiallizes the names to "ANONYMOUS"; trackingNumber_, weight_ and costRate_ to 0,
	//and the street,state,city to "N/A", and zipcode to 0 of both sender_ and receiver_

	void setTrackingNumber(int n) { trackingNumber_ = n; }
	void setSenderName(string name) { senderName_ = name; }
	void setReceiverName(string name) { receiverName_ = name; }
	void setSenderAddress(Address address) { sender_ = address; }
	void setReceiverAddress(Address address) { receiver_ = address; }
	void setWeight(double w);
	void setCostRate(double r);

	int getTrackingNumber()const { return trackingNumber_; }
	string getSenderName()const { return senderName_; }
	string getReceiverName()const { return receiverName_; }
	Address getSenderAddress()const { return sender_; }
	Address getReceiverAddress()const { return receiver_; }
	double getWeight()const { return weight_; }
	double getCostRate()const { return costRate_; }

	double calculateCost()const { return weight_ * costRate_; }
	friend ostream& operator<<(ostream&, const Package&);

protected:
	int trackingNumber_;
	string senderName_;
	string receiverName_;
	Address sender_;
	Address receiver_;
	double weight_; //in ounce
	double costRate_;//cost per ounce
	bool validWeight(double w);
	bool validCostRate(double c);
};

class TwoDayPackage :public Package {
public:
	TwoDayPackage(int n, string sender, string receiver,
		Address senderAdd, Address receiverAdd, double w, double c, double flatFee);
	TwoDayPackage();
	//The default constructor calls the default constructor of class Package
	//and initiallizes flatFee_ to 0

	void setFlatFee(double flateFee);
	double getFlatFee()const { return flatFee_; }

	double calculateCost()const { return Package::calculateCost() + flatFee_; }

	friend ostream& operator<<(ostream&, const TwoDayPackage&);
	TwoDayPackage operator=(const Package&);
	//assigns the object state of the rhs to the calling object which will be on the lhs
private:
	double flatFee_;
	bool validFlatFee(double fee);
};

class OvernightPackage :public Package {
public:
	OvernightPackage(int n, string sender, string receiver,
		Address senderAdd, Address receiverAdd, double w, double c, double additionalFee);
	OvernightPackage();
	//The default constructor calls the default constructor of class Package
	//and initiallizes additionalFee_ to 0

	void setAdditionalFee(double additionalFee) { additionalFee_ = additionalFee; }
	double getAdditionalFee()const { return additionalFee_; }
	double calculateCost()const;

	friend ostream& operator<<(ostream&, const OvernightPackage&);
	OvernightPackage operator=(const Package&);
	//assigns the object state of the rhs to the calling object which will be on the lhs
private:
	double additionalFee_; //this fee is per ounce
};

typedef vector<Package> Packages;
typedef vector<OvernightPackage> OvernightPackages;
typedef vector<TwoDayPackage> TwoDayPackages;

void readPackage(istream& ins, Package& package);
//Precondition: ins is connected to a file for reading
//and package has its default object state
//Postcondition: information will be read from the file to the object package

void readFees(istream& ins, const vector<Package>, TwoDayPackage&);
//Precondition: ins is connected to a file for reading
//and vector<Package> conatains the packages
//Postcondition: information about the package's flatfee will be read from the 
//file and written to the object package.

void readFees(istream& ins, const vector<Package> packages, OvernightPackage& package);
//Precondition: ins is connected to a file for reading
//and vector<Package> conatains the packages
//Postcondition: information about the package's additional rate will be read from the 
//file and written to the object package.
void newline(istream& ins);
//keeps reading the line breaks

int search(const vector<Package>&, string name);
//Precondition: the vector contains packages, name has a value.
//Postcondition: if found returns the index of the package else returns -1

int search(const vector<Package>& v, int trackingNumber);
//Precondition: the vector contains packages, trackingNumber has a value of int.
//Postcondition: if found returns the index of the package else returns -1


int search(const OvernightPackages&, string name);
//Precondition: the vector contains packages, name has a value.
//Postcondition: if found returns the index of the package else returns -1

int search(const OvernightPackages&, int trackingNumber);
//Precondition: the vector contains packages, trackingNumber has a value of int.
//Postcondition: if found returns the index of the package else returns -1

int search(const TwoDayPackages&, string name);
//Precondition: the vector contains packages, name has a value.
//Postcondition: if found returns the index of the package else returns -1

int search(const TwoDayPackages&, int trackingNumber);
//Precondition: the vector contains packages, trackingNumber has a value of int.
//Postcondition: if found returns the index of the package else returns -1

void newline();

void menu(int& option);

void fillPackages(Packages&, OvernightPackages&, TwoDayPackages&);
//This function reads all the information provided in files
//and fills the given vectors with corresponding information

void addPackage(Packages&, TwoDayPackages&, OvernightPackages&);
//Prompts the user to enter the information about the package
//adds the package to the specified type by the user.

void editString(string& str);
//Preconditon: str holds a string
//Postcondition: any non letter character in the 
//string will be removed and every letter will be lower case.

void removePackage(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3);
//asks user for the package type and tracking number and removes the package from
//the appropriate dataset of packages

void editRecord(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3);
//asks user for what does he/she wants to edit in a package
//package is edited after the user's entries

void searchRecord(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3);
//asks user for info about the package. If the package is in the datasets it will be printed to the 
//screen, else the user will be prompted that it wasn't found

void viewRecords(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3);
//asks user for what type of packages he/she wants to display
//then displays all packages of that type

void sendtoFile(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3);
//asks user for what type of packages he/she wants to send to the file
//and what is the file name. 
//The file will be opened and and will contained all packages specified by the user

#endif
