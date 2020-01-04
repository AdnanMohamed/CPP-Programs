//This program assigns passenger seats in an airplane
#include<iostream>
#include"proto.h"
#include<string>
using std::cout; using std::cin; using std::endl;
using std::string;

using std::cout; using std::cin; using std::endl;

int main()
{
	const int rows = 7, columns = 4;
	char myArray[rows][columns];
	string location;
	int c;
	int r;

	cout << "Note*: If you wanted to exit the program type \"exit\" when asked to enter a seat.\n\n";
	fillSeats(rows, columns, myArray);
	for (int i = 0; i < columns * rows; ++i)
	{
		display(rows, columns, myArray);
		cout << "\n\n";
		do {
			cout << "Which seat would you like?\n";
			cin >> location;
			c = toNumber(location[1]);
			r = location[0] - 49;

			if (location == "exit")
			{
				exit(0);
			}
			if ((c > 3 || c < 0) || (r < 0 || r>6))
			{
				cout << "seat does not exist.\n";
			}
			if (reserved(myArray, r, c))
			{
				cout << "This seat is reserved, please pick another one.\n";
			}
			
			book(location, myArray, r, c);
			cout << "\n\n";
		} while ((c > 3 || c < 0) && (r < 0 || r>6) && reserved(myArray, r, c));
		
		
		
	}
	
}

	