#include<iostream>
#include"computerLab.h"
using std::cout; using std::cin; using std::endl;


void ComputerLab::menu(int& option)
{
	cout << "Choose an option:-\n"
		<< "1-login\n"
		<< "2-logout\n"
		<< "3-search\n"
		<< "4-exit\n";
	cin >> option;
}
void ComputerLab::login(int id, int lab, int station)
{
	if (isValid(id))
		myLab_[lab - 1][station - 1] = id;
	else
		cout << "invalid ID";
}
void ComputerLab::logout(int lab, int station)
{
	myLab_[lab-1][station-1] = -1;
}
void ComputerLab::search(int id)
{
	bool found=false;
	if (isValid(id))
	{
		for (int i = 0; i < labs_; ++i)
		{
			switch (i)
			{
			case 0:
				for (int j = 0; j < labSize1_; ++j)
				{
					if (match(id, myLab_[i][j]))
					{
						cout << "lab " << i + 1 << ", station " << j + 1;
						found = true;
					}
				}
				break;
			case 1:
				for (int j = 0; j < labSize2_; ++j)
				{
					if (match(id, myLab_[i][j]))
					{
						cout << "lab " << i + 1 << ", station " << j + 1;
						found = true;
					}
				}
				break;
			case 2:
				for (int j = 0; j < labSize3_; ++j)
				{
					if (match(id, myLab_[i][j]))
					{
						cout << "lab " << i + 1 << ", station " << j + 1;
						found = true;
					}
				}
				break;
			case 3:
				for (int j = 0; j < labSize4_; ++j)
				{
					if (match(id, myLab_[i][j]))
					{
						cout << "lab " << i + 1 << ", station " << j + 1;
						found = true;
					}
				}
				break;
			}
		}
		if (!found)
			cout << "None";
	}
	else
		cout << "invalid ID";

}

bool ComputerLab::match(int id, int id2)
{
	return id == id2;
}

void ComputerLab::display()
{
	cout << "Lab Number\t" << "Computer Stations\n\n";
	for (int i = 0; i < labs_; ++i)
	{
		switch (i)
		{
		case 0:
			cout << i + 1 << "\t\t";
			for (int j = 0; j < labSize1_; ++j)
			{
				cout<< j + 1 << ": ";
				if (myLab_[i][j] > 0)
					cout << myLab_[i][j]<<"  ";
				else
					cout << "empty  ";
			}
			cout << "\n";
			break;
		case 1:
			cout << i + 1 << "\t\t";
			for (int j = 0; j < labSize2_; ++j)
			{
				cout << j + 1 << ": ";
				if (myLab_[i][j] > 0)
					cout << myLab_[i][j]<<"  ";
				else
					cout << "empty  ";
			}

			cout << "\n";
			break;
		case 2:
			cout << i + 1 << "\t\t";
			for (int j = 0; j < labSize3_; ++j)
			{
				cout << j + 1 << ": ";
				if (myLab_[i][j] > 0)
					cout << myLab_[i][j]<<"  ";
				else
					cout << "empty  ";
			}
			cout << "\n";
			break;
		case 3:
			cout << i + 1 << "\t\t";
			for (int j = 0; j < labSize4_; ++j)
			{
				cout << j + 1 << ": ";
				if (myLab_[i][j] > 0)
					cout << myLab_[i][j]<<"  ";
				else
					cout << "empty  ";
			}
			cout << "\n";
			break;
		}
	}
}
bool ComputerLab::isValid(int id) {
	return id / pow(10, 4) >= 1
		&& id / pow(10, 4) < 10;
}

void ComputerLab::setLab()
{
	myLab_ = new IntPtr[labs_];
	for (int i = 0; i < labs_; ++i)
	{
		switch (i)
		{
		case 0:
			myLab_[i] = new int[labSize1_];
			for (int j = 0; j < labSize1_; ++j)
			{
				myLab_[i][j] = -1;
			}
			break;
		case 1:
			myLab_[i] = new int[labSize2_];
			for (int j = 0; j < labSize2_; ++j)
			{
				myLab_[i][j] = -1;
			}
			break;
		case 2:
			myLab_[i] = new int[labSize3_];
			for (int j = 0; j < labSize3_; ++j)
			{
				myLab_[i][j] = -1;
			}
			break;
		case 3:
			myLab_[i] = new int[labSize4_];
			for (int j = 0; j < labSize4_; ++j)
			{
				myLab_[i][j] = -1;
			}
			break;
		}
	}
}

void ComputerLab::setLabSize()
{
	cout << "Enter the number of stations in each lab:-\n"
		<< "lab 1: "; cin >> labSize1_;
	cout << "lab 2: "; cin >> labSize2_;
	cout << "lab 3: "; cin >> labSize3_;
	cout << "lab 4: "; cin >> labSize4_;

}

bool ComputerLab::isValid(int lab, int station)
{
	switch (lab)
	{
	case 1:
		return station <= labSize1_
			&& station > 0;
		break;
	case 2:
		return station <= labSize2_
			&& station > 0;
		break;
	case 3:
		return station <= labSize3_
			&& station > 0;
		break;
	case 4:
		return station <= labSize4_
			&& station > 0;
		break;
	default:
		return false;
	}
}

bool ComputerLab::occupied(int lab,int station)
{
	if (isValid(lab, station))
		return myLab_[lab - 1][station - 1] != -1;
	else
		return false;
}