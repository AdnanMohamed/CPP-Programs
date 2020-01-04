#include<iostream>
#include"myFunctions.h"
#include <string>
#include<vector>
#include<cmath>

using std::string; using std::cin; using std::cout;
using std::endl;

void smallestIndex(int a[], int size,int& min,int& index)
{
	if (size > 0)
	{
		if (a[size - 1] < min)
		{
			min = a[size - 1];
			index = size - 1;
		}
		smallestIndex(a, size - 1, min,index);
	}
}//endOfFunc

void editString(string& str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = tolower(str[i]);
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if (!(str[i] > 96 && str[i] < 123))
			str.erase(i,1);
	}
	
}//endOfFunc

void fillUniq(int a[], int b[], int& numberUsed)
{
	int j = 0;
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (!isPresent(b, a[i]))
		{
			b[j] = a[i];
			++j;
			++numberUsed;
		}
	}
}//end

bool isPresent(int a[], int number)
{
	for (int i = 0; i < SIZE; ++i)
	{
		if (number == a[i])
			return 1;
	}
	return 0;
}//end

int countRepetition(int a[],int element)
{
	int count = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		if (element == a[i])
			++count;
	}

	return count;
}//end


void sort(int a[])
{
	

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (a[j] < a[i])
			{
				swap(a[j], a[i]);
				
			}
			
		}
		
	}
}//end

void sort2(int a[], int b[], int size)
{
	b[0] = a[0];
	for (int i = 1; i < size; ++i)
	{
		b[i] = a[i];
		for (int j = i - 1, k = i; j >= 0; --j)
		{

			if (a[i] < b[j])
			{

				swap(b[k], b[j]);
				--k;
			}

		}
	}
}

void fillUp(double arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
}//end

string lookupName(string targetName, string names[], string phoneNumbers[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (targetName == names[i])
		{
			return phoneNumbers[i];
		}
	}
	return "Name not in list\n";
}//endOfFunc

void search(int a[], int n, bool& found, int& i)
{
	if (i >= 0)
	{
		if (a[i] == n && found == false)
		{
			found = true;
		}
		else
		{
			found = false;
			search(a, n, found, --i);
		}
	}
}//endOfFunc

void search(const int a[], int first, int last, int key, bool& found, int& location)
{
	int mid;
	if(first>last)
	found = false;
	else
	{
		
		mid = (first + last) / 2;
		if (a[mid] == key)
		{
			found = true;
			location = mid;
		}
		else if (a[mid] > key )
		{
			search(a, first, mid-1, key, found, location);
		}
		else if (a[mid] < key)
		{

			search(a, mid+1, last, key, found, location);
		}
	}	
}//endOfFunc

void seperateVar(char cvar[], char name[], char age[], char title[])
{

	int i = 0;
	do
	{

		name[i] = cvar[i];
		++i;
	} while (!isdigit(cvar[i]));
	name[i] = '\0';
	int j = 0;
	do
	{

		age[j] = cvar[i];
		++i;
		++j;
	} while (isdigit(cvar[i]));
	age[j] = '\0';
	int k = 0;
	do
	{

		title[k] = cvar[i];
		++i;
		++k;
	} while (cvar[i] != '\0');
	title[k] = '\0';

}//endOfFunc

void newline()
{
	char next;
	do
	{
		cin.get(next);
	} while (next != '\n');

}//endOfFunc

void addName(vector<string>& names)
{
	string name;
	cout << "Add Name: "; getline(cin, name);

	names.push_back(name);

}//endOfFunc

void addPhone(vector<string>& phoneNumbers)
{
	string phone;
	cout << "Add Phone Number: "; getline(cin, phone);
	phoneNumbers.push_back(phone);

}//endOfFunc

int collatz(int n)
{

	if (n == 1)
		return 0;
	else if (n % 2 == 0)
	{
		n = n / 2;
		return collatz(n) + 1;

	}
	else
	{
		n = 3 * n + 1;
		return collatz(n) + 1;
	}

}//endOfFunc

	void swap(int& a, int& b)
	{
		int tmp;

		tmp = a;
		a = b;
		b = tmp;

	}//endOfFunc

	