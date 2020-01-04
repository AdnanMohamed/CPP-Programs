//This program let the user see advice in programing from past users.
//Then it asks him to enter his advice.
#include<iostream>
#include<fstream>
#include<string>

using std::cout; using std::cin; using std::endl; using std::ios;
using std::ifstream; using std::ofstream; using std::string;

int main()
{
	ofstream fout("programingAdvice.txt", ios::app), fout2;
	ifstream fin("firstAdvice.txt");

	if (fout.fail())
	{
		cout << "Failed to open programingAdvice.txt\n";
	}

	if (fin.fail())
	{
		cout << "Failed to open firstAdvice.txt\n";
	}

	do  //show user my advice
	{
		char next;
		fin.get(next);
		if(!fin.eof())
		cout << next;
	} 
	while (!fin.eof());
	fin.close();

	fout2.open("firstAdvice.txt");
	if (fout2.fail())
	{
		cout << "Failed to open firstAdvice.txt\n";
	}
	cout << "\n\n";
	cout << "Share with us your advice.(end it with two returns)\n";
	
	int count=0;
	char userAdvice;
	bool stop=true;
	do //This takes the user's advice and send it to the file but i need to check when he enters two \n.
	{
		
		cin.get(userAdvice);
		fout << userAdvice;
		fout2 << userAdvice;
		if (userAdvice == '\n')
			if (cin.peek() == '\n')
			{
				fout << '\n';
				fout2 << '\n';
				stop = false;
			}
	} 
	while (stop);

	fout.close();
	fout2.close();


}