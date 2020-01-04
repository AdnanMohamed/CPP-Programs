//This program is used to test functions 
//and to store usefull functions.
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"myFunctions.h"

using std::cout; using std::cin; using std::endl; using std::ios;
using std::ifstream; using std::ofstream; using std::string;

int main()
{
	
	int  myArray[SIZE];
	int arr2[SIZE];
	int numberUsed = 0;
	fillArray(myArray);
	sort(myArray);

	for (int i = 0; i < SIZE; ++i)
	{
		cout << myArray[i] << " ";
	}

	cout << endl;
	fillUniq(myArray, arr2, numberUsed);
	
	for (int i = 0; i < numberUsed; ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
}