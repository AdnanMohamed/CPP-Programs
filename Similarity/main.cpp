//This program has two text files containing some text. The user should imput
//string of words ended by 'end' as the query. The similarity would be displayed.
//The similarity gives you sence of how much did the query set occured in both texts

#include<iostream>
#include"StringSet.h"
#include<string>
#include<vector>
#include<fstream>
using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;
using std::ifstream;

int main()
{
	cout << "Enter you query (end your query set with the word \"end\"):\n";
	vector<string>query;
	string keyword;
	cin >> keyword;
	while (keyword != "end")
	{
		query.push_back(keyword);
		cin >> keyword;
	}
	StringSet querySet(query);
	vector<string>text1, text2;

	ifstream fin1("Document1.txt"), fin2("Document2.txt");
	if (fin1.fail())
	{
		cout << "Failed opening \"Document1.txt\"";
		exit(1);
	}
	if (fin2.fail())
	{
		cout << "Failed opening \"Document2.txt\"";
		exit(1);
	}
	string str;
	fin1 >> str;
	while (!fin1.eof())
	{
		text1.push_back(str);
		fin1 >> str;
	}

	fin2 >> str;

	while (!fin2.eof())
	{
		text2.push_back(str);
		fin2 >> str;
	}
	
	fin1.close();
	fin2.close();
	double sim1, sim2;
	StringSet doc1(text1), doc2(text2);
	querySet.edit();
	doc1.edit();
	doc2.edit();
	sim1= similarity(querySet, doc1);
	sim2 = similarity(querySet, doc2);
	cout.setf(std::ios::showpoint);
	cout.setf(std::ios::fixed);
	cout.precision(2);
	cout << "Similarity with Document1.txt: " << sim1 << endl;
	cout << "Similarity with Document2.txt: " << sim2 << endl;
}