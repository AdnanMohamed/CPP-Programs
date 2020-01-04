#ifndef Airplanes_h
#define Airplanes_h

#include<string>
using std::string;

typedef char* CharPtr;

struct Location {
	int rows;
	int columns;
};

void fillSeats(CharPtr*,int rows,int columns);
//This fills the array, columns 1-4 contains A-D respectively.
void display(CharPtr* arr, int rows, int columns);
//show the seats available.
int toNumber(char c);
//This function returns 0-3 for A to D respectively
//anything else will return -1.

void book(Location seat, CharPtr* arr, int rows, int column);
//This function takes the array of seats and the location specified.
//The location will be booked and replaced with an X only if the seat is valid.

bool reserved(CharPtr* arr, Location seat, int rows, int columns);
//This function checks if a given location is reserved or not.
//returns true if reserved.

bool isValid(Location seat, int rows, int columns);
//returns true if the seat is valid

bool operational(CharPtr* arr, int rows, int columns);
//returns true if there is at least one seat not reserved.


#endif
