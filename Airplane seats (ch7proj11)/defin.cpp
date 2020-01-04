#include<iostream>
#include"proto.h"
#include<string>
using std::cout; using std::cin; using std::endl;
using std::string;

int toNumber(char c)//checked
{
	switch (c)
	{
	case 'A':
		return 0;

	case 'B':
		return 1;

	case 'C':
		return 2;

	case 'D':
		return 3;

	default:
		return -1;
	}
}


void fillSeats(int rows, int columns, char c[][4])//checked
{
	for (int i = rows - 1; i >= 0; --i)
	{
		int j = columns - 1;
		while (j >= 0)
		{
			c[i][j] = 'D'; --j;
			c[i][j] = 'C'; --j;
			c[i][j] = 'B'; --j;
			c[i][j] = 'A'; --j;
		}
	}
}

void display(int rows, int columns, char c[][4])//checked
{
	for (int i = 0; i < rows; ++i)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < columns; ++j)
		{
			cout << c[i][j] << " ";
		}
		cout << "\n\n";
	}
}

void book(string location, char arr[][4], int r, int c)
{

	arr[r][c] = 'X';
}

bool reserved(char arr[][4], int r, int c)
{
	if (arr[r][c] == 'X')
		return 1;
	else
		return 0;
}
