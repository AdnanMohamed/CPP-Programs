#include<iostream>
#include<string>
#include<cmath>
#include"proto.h"

using std::cout; using std::cin; using std::endl;
using std::string;

void newline()
{
	char next;
	do
	{
		cin.get(next);
	} while (next != '\n');

}

void fillUpModify(double arr[], int size, int currentMonth)
{
	int j = currentMonth;
	int i = 0;
	while (i < size)
	{
		cin >> arr[j];
		++i;
		if (j == 11)
		{
			j = -1;
		}
		++j;

	}

}

void fillUp(double arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
}


string month(int a)
{
	if (a < 0)
	{
		a + 12;
	}
	switch (a)
	{
	case 0:
		return "Jan";
		break;

	case 1:
		return "Feb";
		break;

	case 2:
		return "Mar";
		break;

	case 3:
		return "Apr";
		break;

	case 4:
		return "May";
		break;

	case 5:
		return "Jun";
		break;

	case 6:
		return "Jul";
		break;

	case 7:
		return "Aug";
		break;

	case 8:
		return "Sep";
		break;

	case 9:
		return "Oct";
		break;

	case 10:
		return "Nov";
		break;

	case 11:
		return "Dec";
		break;

	}

		
}

void showTable(double actual[], double avg[])
{
	using std::ios;
	cout.setf(ios::right);

	cout << "\t"; cout << "Month"; cout.width(3); cout << "| " << "Actual Rainfall | " << "Compared to Avg.";
	cout << endl;
	cout << "\t"; cout << "______|_________________|___________________";
	cout << endl;

	

	for (int i = 0; i < MONTHS; ++i)
	{
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << "\t" << month(i); cout.width(5); cout << "| "; cout.width(3); cout.unsetf(ios::showpos);
		cout << actual[i]; spaceAfter(actual[i]); cout << "| ";; cout.width(3);
		cout << compare(actual[i], avg[i]);
		cout << endl;
	}

}

double compare(double actual, double avg)
{
	using std::ios;
	if (actual > avg)
	{

		cout.setf(ios::showpos);

		return actual - avg;
	}
	else
	{
		return actual - avg;
	}
}

void spaceAfter(double actual)
{
	using std::ios;
	using std::cout;
	cout.setf(ios::right);

	if (actual >= 10)
	{
		cout.width(13);
	}

	else if (actual > 99)
	{
		cout.width(12);
	}
	else
		cout.width(14);
}

void graph(double actual[], double avg[])
{
	using std::ios;
	using std::cout;
	cout.setf(ios::right);

	for (int i = 0; i < MONTHS; ++i)
	{
		cout << "\t" << month(i); cout << "     actual  "; numberOfHash(actual[i]); cout << endl;
		cout << "\t\t"; cout << "avg     "; numberOfHash(avg[i]); cout << "\n\n";
	}
	
}

void numberOfHash(double number)
{
	myround(number);
	using std::cout;

	for (int i = number; i > 0; --i)
	{
		cout << "#";
	}
}

void myround(double& number)
{
	number = floor(number + 0.5);
}