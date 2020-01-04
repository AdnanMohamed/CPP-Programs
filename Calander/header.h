#ifndef header_h
#define header_h

#include<string>
using std::string;

void getInput(int& m, int& d, int& y);
//This function takes the input for
//the month day and year

bool isLeapYear(int y);
//This function returns 1 if the year is a leep year
//else it returns 0

int getCenturyValue(int y);

int getYearValue(int y);

int getMonthValue(int m, int y);

bool dateIsValid(int m, int d, int y);
//This function checks the validity of the date.
//If the date is valid it returns 1, else it returns 0

int numberOfDay(int m, int d, int y);
//This returns the number of the corresponding day
//start 0 on Sun. until 6 on Sat.

void dayName(int m, int d, int y, string& name);
//This function gives the name of the day
//corresponding to the date given by the user

void newline();
//takes the unwanted input from the user

#endif
