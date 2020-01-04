//This program assigns passenger seats in an airplane
#include<iostream>
#include"Airplanes.h"
#include<string>
using std::cout; using std::cin; using std::endl;
using std::string;

using std::cout; using std::cin; using std::endl;



int main()
{
	int rows;
	const int  columns = 4;
	
	

	cout << "How many rows are in the plane?\n";
	cin >> rows;

	CharPtr *myArray = new CharPtr[rows];

	for (int i = 0; i < rows; ++i)
	{
		myArray[i] = new char[columns];
	}

	cout << "Note*: If you wanted to exit the program enter 0 in column and row.\n\n";
	fillSeats(myArray,rows,columns);
	Location seat;
	int r;
	char c;
		do {

			display(myArray, rows, columns);
			cout << "\n\n";
			cout << "Which seat would you like?\n";
			cout << "row: "; cin >> r;
			cout << "column: "; cin >> c;
			seat.rows = r - 1;
			seat.columns = toNumber(c);
			

			if (r==0||c=='0')
			{
				exit(0);
			}
			if (!isValid(seat,rows,columns))
			{
				cout << "seat does not exist.\n";
			}
			if (reserved(myArray, seat,rows,columns))
			{
				cout << "This seat is reserved, please pick another one.\n";
			}

			book(seat, myArray, rows, columns);
			cout << "\n\n";
		} while (operational(myArray,rows,columns));

		display(myArray, rows, columns);
		if(!operational(myArray,rows,columns))
			cout << "All seats are reserved.\n";
}

