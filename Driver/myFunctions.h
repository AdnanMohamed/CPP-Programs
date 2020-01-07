#ifndef myFunctions_h
#define myFunctions_h

#include<vector>
#include<string>
int const DIGITS = 10,SIZE=15;

using std::string; using std::vector;

void smallestIndex(int a[], int size, int& min, int& index);
//Postcondition: a[] has integers, size is the array size, min is
//any element in the array, index is 0.
//Postcondition: min will contain the smallest value
//index will hold the index of the smallest

void editString(string& str);
//Preconditon: str holds a string
//Postcondition: any non letter character in the 
//string will be removed and every letter will be lower case.

int countRepetition(int a[], int element);
//This function counts how many given element 
//have repeated in the array a[]

bool isPresent(int a[], int number);
//This function checks for the presence of a
//number in an array. True for present.

void search(int a[], int n, bool& found, int& i);
//Precondition: a[] is filled with integers, n is the value to be searched,
//found should be false or not initialized, i is the size of the array.
//Postcondition: found will hold true if the value is in the array, else holds false.
//i will hold the index of the element wich contains the value searched if the value was found.


void search(const int a[], int first, int last, int key, bool& found, int& location);
//Precondition: a[first] through a[last] are sorted in increasing order.
//Postcondition: if key is not one of the values a[first] through a[last],
//then found == false; otherwise, a[location] == key and found == true.

void fillUniq(int a[], int b[], int& numberUsed);
//This funtion fills b[] with the elements from a[]
//but without repeating any repeated element and gives a 
//value for numberUsed wich corresponds to the elements in b[]

void sort(int a[]);
//This sorts a given array from largest to smallest

void sort2(int a[], int b[], int size);
//sorts array a[] in ascending order in b[]
//postcondition: a[] will contain the the original array.
//b[] will contain the sorted numbers

void fillUp(double arr[], int size);
//Precondition:arr[] is an empty array
//and the second par 'size' is its size
//Postcondition: the array will be filled by the user

void swap(int& a, int& b);
//This function swaps the two arguments.


string lookupName(string targetName, string names[], string phoneNumbers[], int size);
//Precondition: targetName will have the name given by the user,names[] has a list of names,
//phoneNumbers[] has the phoneNumbers corresponding to each name in names[],size is the size of both arrays
//Postcondition:This function returns the phone number for a given name.

void seperateVar(char cvar[], char name[], char age[], char title[]);
//Precondition: cvar[] contains string written as the following format name/age/title.
//the three other arrays are empty.
//Post-condition: The function will seperate the variables to the three arrays

void newline();
//This function takes any unwanted characters after
//the user's input, so the extra input don't go 
//to the next input.

void addName(vector<string>& names);
//This function let the user add names to a vector of names

void addPhone(vector<string>& phoneNumbers);
//This function let the user add phone numbers to a vector of phone numbers

int collatz(int n);
//This function takes a positive integer and returns
//the number of steps it would take to return to number 1
//by applying recursive concept "calling the function".

template<class T>
void swap(T& var1, T& var2)
{
    T temp = var1;
    var1 = var2;
    var2 = temp;
}
// This function swaps any values of the types that can be assigned
// like int, double, string, char and others.

template<class T>
void sort(T a[], int size)
{
    T min;
    int index;
    for (int i = 0; i < size; ++i)
    {
        min = a[i];
        index = i;
        for (int j = i; j < size; ++j)
        {
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        }
        swap(a[i], a[index]);
    }
}

// This sort function takes an array of the size given as 2nd argument.
// The type of elements should be comparable <
// Some elegible types are int, double, char, string.
// The array will be ordered ascendently

#endif
