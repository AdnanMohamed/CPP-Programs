#ifndef proto_h
#define proto_h

using std::string;

const int MONTHS = 12;

void newline();
//This function takes any unwanted characters after
//the user's input, so the extra input don't go 
//to the next input.

void fillUpModify(double arr[], int size, int currentMonth);
//The user enters the values of months from a certain month.
//The user not nessarliy enters starting from jan.
//the function fills the array and modify the elements.
//such that the elements will be sorted from jan to dec.

void fillUp(double arr[], int size);
//this function fills the array

string month(int a);
//gives the name of the month given a number;
//counting from jan=0 to dec=11

void showTable(double actual[], double avg[]);
//precondition: actual[] contains the data for actual rainfall figures
//for the previous 12 months given by the user.The avg[] contains
//the average rainfall for each month in the year.
//Post: this prints a table about the figures.

double compare(double actual, double avg);
//outputs the difference between the actual number
//and the avg.(showing if pos(+) or neg.(-))

void spaceAfter(double actual);
//This prints space to make the table look fancy

void numberOfHash(double number);
//the number given will be rounded to nearest whole number.
//prints out the hashes depending on the number given
//hash for each unit(1)

void graph(double actual[], double avg[]);
//outputs a graph that shows the actual and average figure for each month

void myround(double& number);
//rounds to nearest whole number.




#endif
