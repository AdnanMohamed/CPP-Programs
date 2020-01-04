#ifndef proto_h
#define proto_h
#include<string>
using std::string;
void fillSeats(int rows, int columns, char c[][4]);
//This fills the array, columns 1-4 contains A-D respectively.
void display(int rows, int columns, char c[][4]);
//show the seats available.
int toNumber(char c);
//This function returns 0-3 for A to D respectively
//anything else will return -1.

void book(string location, char arr[][4], int r, int c);
//This function takes the array of seats and the location specified.
//The location will be booked and replaced with an X.

bool reserved(char arr[][4], int r, int c);
//This function checks if a given location is reserved or not.
//returns true if reserved.

#endif
