#include<iostream>
#include<vector>
#include<fstream>
#include"packageSystem.h"
using std::string; using std::cout; using std::cin;
using std::endl; using std::vector; using std::ifstream;
using std::istream; using std::ofstream; using std::ostream;
void newline()
{
	char next;
	do
	{
		cin.get(next);
	} while (next != '\n');

}

void menu(int& option)
{
	cout << "Select from the options below:-\n";
	cout << "1- Add a package\n"
		<< "2- Remove a package\n"
		<< "3- Edit Record\n"
		<< "4- Search Record\n"
		<< "5- View\n"
		<< "6- Send to File\n"
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

void fillPackages(Packages& packages, OvernightPackages& overnightPackages, TwoDayPackages& twoDayPackages)
{
	Package package;
	OvernightPackage overnightPackage;
	TwoDayPackage twoDayPackage;

	ifstream fin("Packages.txt");
	if (fin.fail())
	{
		cout << "Failed opening \"Packages.txt\"";
		exit(1);
	}


	do
	{
		readPackage(fin, package);
		newline(fin);
		packages.push_back(package);
	} while (!fin.eof());

	fin.close();

	fin.open("Overnight Packages Fees.txt");
	if (fin.fail())
	{
		cout << "Failed opening \"Overnight Packages Fees.txt\"";
		exit(1);
	}
	do
	{
		readFees(fin, packages, overnightPackage);
		newline(fin);
		overnightPackages.push_back(overnightPackage);
	} while (!fin.eof());
	fin.close();

	fin.open("Two Days Packages Fees.txt");
	if (fin.fail())
	{
		cout << "Failed opening \"Two Days Packages Fees.txt\"";
		exit(1);
	}
	do
	{
		readFees(fin, packages, twoDayPackage);
		newline(fin);

		twoDayPackages.push_back(twoDayPackage);
	} while (!fin.eof());

	fin.close();
}

Package::Package(int n, string sender, string receiver, Address senderAdd, Address receiverAdd, double w, double c)
	:trackingNumber_(n), senderName_(sender), receiverName_(receiver), sender_(senderAdd),
	receiver_(receiverAdd), weight_(w), costRate_(c)
{
	//EMPTY BODY
}

Package::Package() :trackingNumber_(0), senderName_("ANONYMOUS"), receiverName_("ANONYMOUS"), weight_(0), costRate_(0)
{
	Address r, s;
	r.city_ = "N/A"; r.state_ = "N/A";
	r.street_ = "N/A"; r.zipcode_ = 0;
	s.city_ = "N/A"; s.state_ = "N/A";
	s.street_ = "N/A"; s.zipcode_ = 0;

	receiver_ = r;
	sender_ = s;
}

bool Package::validWeight(double w)
{
	return w > 0;
}

bool Package::validCostRate(double c)
{
	return c > 0;
}

void Package::setWeight(double w)
{
	if (validWeight(w))
	{
		weight_ = w;
	}
	else
	{
		cout << "INVALID WEIGHT!";
		exit(1);
	}
}

void Package::setCostRate(double r)
{
	if (validWeight(r))
	{
		costRate_ = r;
	}
	else
	{
		cout << "INVALID COST RATE!";
		exit(1);
	}
}

TwoDayPackage::TwoDayPackage(int n, string sender, string receiver,
	Address senderAdd, Address receiverAdd, double w, double c, double flatFee)
	:Package(n, sender, receiver, senderAdd, receiverAdd, w, c)
{
	flatFee_ = flatFee;
}

TwoDayPackage::TwoDayPackage() :Package(), flatFee_(0)
{
	//EMPTY BODY
}

bool TwoDayPackage::validFlatFee(double fee)
{
	return fee >= 0;
}

void TwoDayPackage::setFlatFee(double flateFee)
{
	if (validFlatFee(flateFee))
		flatFee_ = flateFee;
	else
	{
		cout << "INVALID FEE!";
		exit(1);
	}
}

TwoDayPackage TwoDayPackage::operator=(const Package& rhs)
{
	senderName_ = rhs.getSenderName();
	sender_ = rhs.getSenderAddress();
	trackingNumber_ = rhs.getTrackingNumber();
	receiverName_ = rhs.getReceiverName();
	receiver_ = rhs.getReceiverAddress();
	weight_ = rhs.getWeight();
	costRate_ = rhs.getCostRate();

	return *this;
}

OvernightPackage::OvernightPackage(int n, string sender, string receiver,
	Address senderAdd, Address receiverAdd, double w, double c, double additionalFee)
	:Package(n, sender, receiver, senderAdd, receiverAdd, w, c)
{

	additionalFee_ = additionalFee;
}

OvernightPackage::OvernightPackage() :Package(), additionalFee_(0)
{
	//EMPTY BODY
}

double OvernightPackage::calculateCost()const
{
	return (costRate_ + additionalFee_) * weight_;
}

OvernightPackage OvernightPackage::operator=(const Package& rhs)
{
	senderName_ = rhs.getSenderName();
	sender_ = rhs.getSenderAddress();
	trackingNumber_ = rhs.getTrackingNumber();
	receiverName_ = rhs.getReceiverName();
	receiver_ = rhs.getReceiverAddress();
	weight_ = rhs.getWeight();
	costRate_ = rhs.getCostRate();

	return *this;
}

void readPackage(istream& ins, Package& package)
{
	Address sender, receiver;
	string next;
	ins >> next;//ignore "Package"
	int trackingNumber;
	ins >> trackingNumber;
	newline(ins);
	package.setTrackingNumber(trackingNumber);
	getline(ins, next);//ignore "sender:"
	getline(ins, next);
	package.setSenderName(next);
	getline(ins, next);
	sender.street_ = next;
	getline(ins, next, ',');
	sender.city_ = next;
	ins >> next;
	sender.state_ = next;
	int zipcode;
	ins >> zipcode;
	sender.zipcode_ = zipcode;
	package.setSenderAddress(sender);

	getline(ins, next);//ignore first line
	getline(ins, next);//ignore sender:
	getline(ins, next);
	package.setReceiverName(next);
	getline(ins, next);
	receiver.street_ = next;
	getline(ins, next, ',');
	receiver.city_ = next;
	ins >> next;
	receiver.state_ = next;
	ins >> zipcode;
	receiver.zipcode_ = zipcode;
	package.setReceiverAddress(receiver);
	ins >> next;//ignore weight:
	double weight;
	ins >> weight;
	package.setWeight(weight);
	ins >> next;//ignore rate:
	double rate;
	ins >> rate;
	package.setCostRate(rate);
}

ostream& operator<<(ostream& outs, const Package& package)
{
	outs << "Package #" << package.getTrackingNumber() << endl;
	outs << "Sender:-\nName: " << package.getSenderName() << endl;
	outs << "Address:-\n" << package.getSenderAddress().street_ << endl
		<< package.getSenderAddress().city_ << ", " << package.getSenderAddress().state_ << ' '
		<< package.getSenderAddress().zipcode_ << endl;
	outs << endl;
	outs << "Receiver:-\n"
		<< "Name: " << package.getReceiverName() << endl;
	outs << "Address:-\n" << package.getReceiverAddress().street_ << endl
		<< package.getReceiverAddress().city_ << ", " << package.getReceiverAddress().state_ << ' '
		<< package.getReceiverAddress().zipcode_ << endl;
	outs << endl;
	outs << "Weight: " << package.getWeight() << " ounce" << endl;
	outs << "Base Cost: $" << package.calculateCost() << endl;
	outs << "--------------------------" << endl;
	return outs;
}

ostream& operator<<(ostream& outs, const TwoDayPackage& package)
{
	outs << "Package #" << package.getTrackingNumber() << endl;
	outs << "Sender:-\nName: " << package.getSenderName() << endl;
	outs << "Address:-\n" << package.getSenderAddress().street_ << endl
		<< package.getSenderAddress().city_ << ", " << package.getSenderAddress().state_ << ' '
		<< package.getSenderAddress().zipcode_ << endl;
	outs << endl;
	outs << "Receiver:-\n"
		<< "Name: " << package.getReceiverName() << endl;
	outs << "Address:-\n" << package.getReceiverAddress().street_ << endl
		<< package.getReceiverAddress().city_ << ", " << package.getReceiverAddress().state_ << ' '
		<< package.getReceiverAddress().zipcode_ << endl;
	outs << endl;
	outs << "Weight: " << package.getWeight() << " ounce" << endl;
	outs << "Total Cost: $" << package.calculateCost() << endl;
	outs << "--------------------------" << endl;
	return outs;
}

ostream& operator<<(ostream& outs, const OvernightPackage& package)
{
	outs << "Package #" << package.getTrackingNumber() << endl;
	outs << "Sender:-\nName: " << package.getSenderName() << endl;
	outs << "Address:-\n" << package.getSenderAddress().street_ << endl
		<< package.getSenderAddress().city_ << ", " << package.getSenderAddress().state_ << ' '
		<< package.getSenderAddress().zipcode_ << endl;
	outs << endl;
	outs << "Receiver:-\n"
		<< "Name: " << package.getReceiverName() << endl;
	outs << "Address:-\n" << package.getReceiverAddress().street_ << endl
		<< package.getReceiverAddress().city_ << ", " << package.getReceiverAddress().state_ << ' '
		<< package.getReceiverAddress().zipcode_ << endl;
	outs << endl;
	outs << "Weight: " << package.getWeight() << " ounce" << endl;
	outs << "Total Cost: $" << package.calculateCost() << endl;
	outs << "--------------------------" << endl;
	return outs;
}

void readFees(istream& ins, const vector<Package> packages, TwoDayPackage& package)
{
	string next;
	int trackingNumber;
	double additionalCost;
	ins >> next;//ignore "Package"
	ins >> trackingNumber;
	int index;
	index = search(packages, trackingNumber);
	getline(ins, next, ':');
	ins >> additionalCost;
	if (index != -1)
	{
		package = packages[index];
		package.setFlatFee(additionalCost);
	}
}

void readFees(istream& ins, const vector<Package> packages, OvernightPackage& package)
{
	string next;
	int trackingNumber;
	double additionalCost;
	ins >> next;//ignore "Package"
	ins >> trackingNumber;
	int index;
	index = search(packages, trackingNumber);
	getline(ins, next, ':');
	ins >> additionalCost;
	if (index != -1)
	{
		package = packages[index];
		package.setAdditionalFee(additionalCost);
	}
}

void newline(istream& ins)
{
	char next;

	do
	{
		ins.get(next);
		if (ins.peek() != '\n')
			break;
	} while (next == '\n');

}

int search(const vector<Package>& v, string name)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getSenderName() == name || v[i].getReceiverName() == name)
			return i;
	}
	return -1;
}

int search(const vector<Package>& v, int trackingNumber)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getTrackingNumber() == trackingNumber || v[i].getTrackingNumber() == trackingNumber)
			return i;
	}
	return -1;
}

int search(const OvernightPackages& v, string name)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getSenderName() == name || v[i].getReceiverName() == name)
			return i;
	}
	return -1;
}

int search(const OvernightPackages& v, int trackingNumber)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getTrackingNumber() == trackingNumber || v[i].getTrackingNumber() == trackingNumber)
			return i;
	}
	return -1;
}

int search(const TwoDayPackages& v, string name)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getSenderName() == name || v[i].getReceiverName() == name)
			return i;
	}
	return -1;
}

int search(const TwoDayPackages& v, int trackingNumber)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getTrackingNumber() == trackingNumber || v[i].getTrackingNumber() == trackingNumber)
			return i;
	}
	return -1;
}

void addPackage(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3)
{
	string senderName, receiverName;
	string packageType;
	string streetS, cityS, stateS,streetR, cityR, stateR;
	int zipcodeS,zipcodeR, trackingNumber;
	double w, iCostRate;
	cout << "Package Type (Ordinary/ Two Day/ Overnight)\n";
	do {
		cout << "Enter Type: ";
		getline(cin, packageType);
		editString(packageType);
		if (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight")
			cout << "INVALID TYPE\n";
	} while (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight");
	cout << "Tracking Number: ";
	cin >> trackingNumber;
	newline();
	cout << "Sender Name: ";
	getline(cin, senderName);
	cout << "Sender Address:-\n";
	cout << "Street: ";
	getline(cin, streetS);
	cout << "City: ";
	getline(cin, cityS);
	cout << "State: ";
	getline(cin, stateS);
	cout << "ZIP Code: ";
	cin >> zipcodeS;
	newline();
	cout << "Receiver Name: ";
	getline(cin, receiverName);
	cout << "Receiver Address:-\n";
	cout << "Street: ";
	getline(cin, streetR);
	cout << "City: ";
	getline(cin, cityR);
	cout << "State: ";
	getline(cin, stateR);
	cout << "ZIP Code: ";
	cin >> zipcodeR;
	cout << "Weight (in ounce): ";
	cin >> w;
	cout << "Initial Cost Rate: $";
	cin >> iCostRate;
	newline();
	Address senderAddress, receiverAddress;
	senderAddress.city_ = cityS; senderAddress.state_ = stateS; senderAddress.street_ = streetS;
	senderAddress.zipcode_ = zipcodeS;
	receiverAddress.city_ = cityR; receiverAddress.state_ = stateR; receiverAddress.street_ = streetR;
	receiverAddress.zipcode_ = zipcodeR;
	if (packageType == "overnight")
	{
		double aCostRate;
		cout << "Additional Cost Rate: $";
		cin >> aCostRate;
		Package newPackage(trackingNumber, senderName, receiverName, senderAddress, receiverAddress,
			w, iCostRate);
		OvernightPackage newOvernightPackage;
		newOvernightPackage = newPackage;
		newOvernightPackage.setAdditionalFee(aCostRate);
		dataset1.push_back(newPackage);
		dataset3.push_back(newOvernightPackage);
	}
	else if (packageType == "twoday")
	{
		double fee;
		cout << "Flat Fee: $";
		cin >> fee;
		Package newPackage(trackingNumber, senderName, receiverName, senderAddress, receiverAddress,
			w, iCostRate);
		TwoDayPackage newTwoDayPackage;
		newTwoDayPackage = newPackage;
		newTwoDayPackage.setFlatFee(fee);
		dataset1.push_back(newPackage);
		dataset2.push_back(newTwoDayPackage);
	}
	else
	{
		Package newPackage(trackingNumber, senderName, receiverName, senderAddress, receiverAddress,
			w, iCostRate);
		dataset1.push_back(newPackage);
	}
	cout << "Package is added successfully";
}

void removePackage(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3)
{
	int trackingNumber, index;
	string packageType;
	do {
		cout << "Enter Type: ";
		getline(cin, packageType);
		editString(packageType);
		if (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight")
			cout << "INVALID TYPE\n";
	} while (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight");
	cout << "Tracking Number: ";
	cin >> trackingNumber;
	if (packageType == "overnight")
	{
		index = search(dataset1, trackingNumber);
		if (index != -1)
		{
			vector<Package>::iterator it1;
			it1 = dataset1.begin() + index;
			dataset1.erase(it1);
			index = search(dataset3, trackingNumber);
			if (index != -1)
			{
				vector<OvernightPackage>::iterator it3;
				it3 = dataset3.begin() + index;
				dataset3.erase(it3);
			}
			cout << "Package is removed successfully";
		}
		else
			"PACKAGE NOT FOUND";


	}

	else if (packageType == "twoday")
	{
		index = search(dataset1, trackingNumber);
		if (index != -1)
		{
			vector<Package>::iterator it1;
			it1 = dataset1.begin() + index;
			dataset1.erase(it1);
			index = search(dataset2, trackingNumber);
			if (index != -1)
			{
				vector<TwoDayPackage>::iterator it2;
				it2 = dataset2.begin() + index;
				dataset2.erase(it2);
			}
			cout << "Package is removed successfully";
		}
		else
			"PACKAGE NOT FOUND";

	}
	else if (packageType == "ordinary")
	{
		index = search(dataset1, trackingNumber);
		if (index != -1)
		{
			vector<Package>::iterator it1;
			it1 = dataset1.begin() + index;
			dataset1.erase(it1);
		}
	}
	else
		cout << "INVALID TYPE!";
	
}

void editRecord(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3)
{
	string senderName, receiverName;
	string streetS, cityS, stateS, streetR, cityR, stateR;
	int zipcodeS, zipcodeR;
	double w, iCostRate, aCostRate, flatFee;
	int trackingNumber, index, index2, index3;
	string packageType;
	Address senderAddress, receiverAddress;

	do {
		cout << "Enter Type: ";
		getline(cin, packageType);
		editString(packageType);
		if (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight")
			cout << "INVALID TYPE\n";
	} while (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight");
	cout << "Tracking Number: ";
	cin >> trackingNumber;
	cout << endl;
	char choice;
	cout << "What would you like to edit?\n"
		<< "Choose from the following:-\n"
		<< "A- Sender Name\n"
		<< "B- Receiver Name\n"
		<< "C- Sender Address\n"
		<< "D- Receiver Address\n"
		<< "E- Package Weight\n"
		<< "F- Fees\n"
		<< "G- Tracking Number\n";
	do {
		cout << "Choice: ";
		cin >> choice;
		newline();
		choice = toupper(choice);
		if (choice > 'G' || choice < 'A')
			cout << "INVALID CHOICE!";
	} while (choice > 'G' || choice < 'A');


	index = search(dataset1, trackingNumber);
	if (packageType == "overnight")
		index3 = search(dataset3, trackingNumber);
	else if (packageType == "twoday")
		index2 = search(dataset2, trackingNumber);

	if (index == -1)
		cout << "PACKAGE NOT FOUND";

	if (index != -1)
	{
		switch (choice)
		{
		case 'A':
			cout << "Sender Name: ";
			getline(cin, senderName);
			if (packageType == "overnight")
				dataset3[index3].setSenderName(senderName);
			else if (packageType == "twoday")
				dataset2[index2].setSenderName(senderName);
			dataset1[index].setSenderName(senderName);
			break;
		case 'B':
			cout << "Receiver Name: ";
			getline(cin, receiverName);
			if (packageType == "overnight")
				dataset3[index3].setReceiverName(receiverName);
			else if (packageType == "twoday")
				dataset2[index2].setReceiverName(receiverName);
			dataset1[index].setReceiverName(receiverName);
			break;
		case 'C':
			cout << "Sender Address:-\n";
			cout << "Street: ";
			getline(cin, streetS);
			cout << "City: ";
			cin >> cityS;
			cout << "State: ";
			cin >> stateS;
			cout << "ZIP Code: ";
			cin >> zipcodeS;
			newline();
			senderAddress.city_ = cityS; senderAddress.state_ = stateS; senderAddress.street_ = streetS;
			senderAddress.zipcode_ = zipcodeS;
			if (packageType == "overnight")
				dataset3[index3].setSenderAddress(senderAddress);
			else if (packageType == "twoday")
				dataset2[index2].setSenderAddress(senderAddress);
			dataset1[index].setSenderAddress(senderAddress);
			break;
		case'D':
			cout << "Receiver Address:-\n";
			cout << "Street: ";
			getline(cin, streetR);
			cout << "City: ";
			cin >> cityR;
			cout << "State: ";
			cin >> stateR;
			cout << "ZIP Code: ";
			cin >> zipcodeR;
			newline();

			receiverAddress.city_ = cityR; receiverAddress.state_ = stateR;
			receiverAddress.street_ = streetR; receiverAddress.zipcode_ = zipcodeR;

			if (packageType == "overnight")
				dataset3[index3].setReceiverAddress(receiverAddress);
			else if (packageType == "twoday")
				dataset2[index2].setReceiverAddress(receiverAddress);
			dataset1[index].setReceiverAddress(receiverAddress);
			break;
		case'E':
			cout << "Package Weight (in ounce): ";
			cin >> w;
			newline();
			if (packageType == "overnight")
				dataset3[index3].setWeight(w);
			else if (packageType == "twoday")
				dataset2[index2].setWeight(w);
			dataset1[index].setWeight(w);
			break;
		case'F':
			cout << "Initial Rate($/ounce): $";
			cin >> iCostRate;
			newline();
			dataset1[index].setCostRate(iCostRate);
			if (packageType == "overnight")
			{
				dataset3[index3].setCostRate(iCostRate);
				cout << "Additional Cost Rate: $";
				cin >> aCostRate;
				newline();
				dataset3[index3].setAdditionalFee(aCostRate);
			}
			else if (packageType == "twoday")
			{
				dataset2[index2].setCostRate(iCostRate);
				cout << "Flat Fee: $";
				cin >> flatFee;
				newline();
				dataset2[index2].setFlatFee(flatFee);
			}
			break;
		case 'G':
			cout << "Tracking Number: ";
			cin >> trackingNumber;
			newline();
			if (packageType == "overnight")
				dataset3[index3].setTrackingNumber(trackingNumber);
			else if (packageType == "twoday")
				dataset2[index2].setTrackingNumber(trackingNumber);
			dataset1[index].setTrackingNumber(trackingNumber);

			cout << "Package edited successfully";
		}

	}
}

void searchRecord(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3)
{
	string packageType;
	int trackingNumber;
	cout << "Package Type (Ordinary/ Two Day/ Overnight)\n";
	do {
		cout << "Enter Type: ";
		getline(cin, packageType);
		editString(packageType);
		if (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight")
			cout << "INVALID TYPE\n";
	} while (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight");
	cout << "Tracking Number: ";
	cin >> trackingNumber;
	int index1, index2, index3;
	index1 = search(dataset1, trackingNumber);
	index2 = search(dataset2, trackingNumber);
	index3 = search(dataset3, trackingNumber);
	if (index1 != -1)
	{
		if (packageType == "ordinary")
			cout << dataset1[index1];
		else if (packageType == "twoday")
			cout << dataset2[index2];
		else if (packageType == "overnight")
			cout << dataset3[index3];
	}
	else
		cout << "PACKAGE NOT FOUND";
	
}

void viewRecords(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3)
{
	string packageType;
	cout << "What kind of records would you like to view?(Ordinary/Overnight/Two Day)\n";
	do {
		cout << "Enter Type: ";
		getline(cin, packageType);
		editString(packageType);
		if (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight")
			cout << "INVALID TYPE\n";
	} while (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight");
	
	if (packageType == "ordinary")
	{
		for (auto i : dataset1)
			cout << i << endl;
	}
	else if (packageType == "overnight")
	{
		for (auto i : dataset3)
			cout << i << endl;
	}
	else
	{
		for (auto i : dataset2)
			cout << i << endl;
	}
}

void sendtoFile(Packages& dataset1, TwoDayPackages& dataset2, OvernightPackages& dataset3)
{
	string fileName,packageType;
	cout << "Enter file name like (example.txt): ";
	getline(cin, fileName);
	ofstream fout(fileName);
	while (fout.fail())
	{
		cout << "Failed opening \"" << fileName << "\"";
		cout << "Enter file name: ";
		cin >> fileName;
		fout.open(fileName);
	}
	cout << "What type of packages would you like to send?(Ordinary/Two Day/Overnight)\n";
	do {
		cout << "Enter Type: ";
		getline(cin, packageType);
		editString(packageType);
		if (packageType != "ordinary" && packageType != "twoday" &&
			packageType != "overnight")
			cout << "INVALID TYPE\n";
	} while (packageType != "ordinary" && packageType != "twoday" && packageType != "overnight");
	if (packageType == "ordinary")
	{
		for (auto i : dataset1)
			fout << i << endl;
	}
	else if (packageType == "twoday")
	{
		for (auto i : dataset2)
			fout << i << endl;
	}
	else
		for (auto i : dataset3)
			fout << i << endl;
}

void editString(string& str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = tolower(str[i]);
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if (!(str[i] > 96 && str[i] < 123))
			str.erase(i, 1);
	}

}
