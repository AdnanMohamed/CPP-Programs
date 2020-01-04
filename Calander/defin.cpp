#include<iostream>
#include<string>

using std::cout; using std::cin; using std::endl; using std::string;

void getInput(int& m, int& d, int& y)
{
	
	

	cout << "Month: ";
	cin >> m;
	cout << endl;

	cout << "Day: ";
	cin >> d;
	cout << endl;
	cout << "Year: ";
	cin >> y;
	cout << endl;
}

bool isLeapYear(int y)
{
	if ((y % 400 == 0) || (y % 4 == 0) && (y % 100 != 0))
	{
		return 1;
	}
	else
		return 0;
}

int getCenturyValue(int y)
{
	int x;
	x = (y / 100) % 4;
	return (3 - x) * 2;
}

int getYearValue(int y)
{
	int z;

	z = y % 100;

	return (z / 4) + z;
}

int getMonthValue(int m, int y)
{
	switch (isLeapYear(y))
	{
	case 0:
		if (m == 1 || m == 10)
			return 0;
		else if (m == 2 || m == 3 || m == 11)
			return 3;
		else if (m == 4 || m == 7)
			return 6;
		else if (m == 5)
			return 1;
		else if (m == 6)
			return 4;
		else if (m == 8)
			return 2;
		else
			return 5;
		break;

	case 1:
		if ( m == 10)
			return 0;
		else if (m == 3 || m == 11)
			return 3;
		else if (m == 4 || m == 7 || m == 1)
			return 6;
		else if (m == 5)
			return 1;
		else if (m == 6)
			return 4;
		else if (m == 8 || m == 2)
			return 2;
		else
			return 5;
		break;
	}
}

int numberOfDay(int m, int d,int y)
{
	int sum;

	sum = d + getCenturyValue(y) + getYearValue(y) + getMonthValue(m, y);

	return sum % 7;
}

void dayName(int m, int d, int y,string& name)
{
	
		switch (numberOfDay(m, d, y))
		{
		case 0:
			name = "Sunday";
			break;
		case 1:
			name = "Monday";
			break;
		case 2:
			name = "Tuesday";
			break;
		case 3:
			name = "Wednesday";
			break;
		case 4:
			name = "Thursday";
			break;
		case 5:
			name = "Friday";
			break;
		case 6:
			name = "Saturday";
			break;

		}
	
	
}

bool dateIsValid(int m, int d, int y)
{
	int section31[] = { 1,3,5,7,8,10,12 };
	int section30[] = { 4,6,9,11 };

	if (y < 0 || m <= 0 || m>12)
	{
		return 0;
	}



	for (int i = 0; i < 7; ++i)
	{
		if (section31[i] == m)
		{
			if (d > 31 || d <= 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (section30[i] == m)
		{
			if (d > 30 || d <= 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}

	if (m == 2 && isLeapYear(y))
	{
		if (d > 29 || d <= 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (m == 2 && !isLeapYear(y))
	{
		if (d > 28 || d <= 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}


void newline()
{
	char white;
	do {
		cin.get(white);
	}
	while (white != '\n');
}
	

	

