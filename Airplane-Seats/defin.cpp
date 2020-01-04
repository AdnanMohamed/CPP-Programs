#include<iostream>
#include"Airplanes.h"
#include<string>
using std::cout; using std::cin; using std::endl;
using std::string;

int toNumber(char c)//checked
{
	c = toupper(c);
	return static_cast<int>(c) - static_cast<int>('A');
}


void fillSeats(CharPtr* arr, int rows, int columns)//checked
{
	for (int i = rows - 1; i >= 0; --i)
	{
		int j = columns - 1;
		while (j >= 0)
		{
			arr[i][j] = 'D'; --j;
			arr[i][j] = 'C'; --j;
			arr[i][j] = 'B'; --j;
			arr[i][j] = 'A'; --j;
		}
	}
}

void display(CharPtr* arr, int rows, int columns)//checked
{
	for (int i = 0; i < rows; ++i)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < columns; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n\n";
	}
}

void book(Location seat, CharPtr* arr, int rows, int column)
{
	if (isValid(seat,rows,column))
	arr[seat.rows][seat.columns] = 'X';
}

bool reserved(CharPtr* arr, Location seat,int rows,int columns)
{
	if (isValid(seat, rows, columns))
	{
		if (arr[seat.rows][seat.columns] == 'X')
			return 1;
		else
			return 0;
	}
}

bool isValid(Location seat, int rows, int columns)
{
	return seat.rows < rows && seat.columns < columns;
}

bool operational(CharPtr* arr,int rows,int columns)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
		{
			if (arr[i][j] != 'X')
				return 1;
		}
	return 0;
}