/*The game of “Jump It” consists of a board with n positive integers in a row,
except for the first column, which always contains 0.
These numbers represent the cost to enter each column.
The object of the game is to move from the first column
to the last column with the lowest total cost.*/
#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>
using std::cout; using std::cin; using std::endl;
using std::vector;

typedef vector<int> VectorInt;

int cost(int a[], int size, int first, bool choose);
//Precondition: a[] contains integers, size is the array size,
//first is the first element to start searching in the array, choose is used to randomize the process
//Postcondition: returns a random integer representing the cost from the random choices

void fillUniq(VectorInt&, int);
//fills the vector with the given integer only if the integer is not in the vector
int main()
{
	srand(time(nullptr));
	bool choose = true;

	int size;
	cout << "Enter the size of the board: ";
	cin >> size;
	int* ptr = new int[size];
	cout << "Enter the cost of each column: ";
	for (int i = 0; i < size; ++i)
		cin >> ptr[i];
	int first = ptr[0];
	int minCost = ptr[0];
	int randomCost;
	VectorInt costs;
	for (int i = 0; i < 10000; ++i)
	{
		randomCost = cost(ptr, size, first, choose);
		fillUniq(costs, randomCost);
	}
	sort(costs.begin(), costs.end());
	minCost = costs[0];
	cout << endl;
	cout << "The minimum cost is: " << minCost << endl;
	delete[] ptr;
}

int cost(int a[], int size, int first, bool choose)
{

	if (first == size - 1)
	{
		return 0;
	}
	else if (first == size - 2)
	{
		return a[size - 1];
	}
	else
	{
		choose = rand() % 2;
		if (choose)
			return a[first + 1] + cost(a, size, first + 1, choose);
		else
			return a[first + 2] + cost(a, size, first + 2, choose);
	}
}

void fillUniq(VectorInt& v, int n)
{
	if (find(v.begin(), v.end(), n) == v.end())
	{
		v.push_back(n);
	}
}