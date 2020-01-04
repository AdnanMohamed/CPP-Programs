#include<iostream>
#include<fstream>
#include"votingSystem.h"
using std::cin; using std::cout; using std::endl;
using std::ifstream;

int main()
{
	ifstream fin;

	fin.open("Elections.txt");
	if (fin.fail())
	{
		cout << "Failed opening \"Elections.txt\"";
		exit(1);
	}
	Voters kent;
	Voter voter;
	fin >> voter;
	while (!fin.eof())
	{
		kent.push_back(voter);
		fin >> voter;
	}
	showElection(kent);
	cout << endl;
	showPercentages(kent);
	
}