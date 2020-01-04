#include<iostream>
#include"StringSet.h"
#include<string>
#include<vector>
#include<cmath>
using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;


StringSet operator+(StringSet set, string str)  
{
	set.strings_.push_back(str);
	return set;
}

StringSet operator+(StringSet set1, StringSet set2) 
{
	std::vector<string>::iterator it1,it2,it3;

	set1.edit();
	set2.edit();

	it1 = set1.strings_.begin();
	it2 = set2.strings_.begin();
	
	StringSet temp;
	it3 = temp.strings_.begin();
	for (it1; it1 != set1.strings_.end(); ++it1)
	{
		it3 = find(temp.strings_.begin(), temp.strings_.end(), *it1);
		if (it3 == temp.strings_.end())
			temp.strings_.push_back(*it1);
	}
	for (it2; it2 != set2.strings_.end(); ++it2)
	{
		it1 = find(set1.strings_.begin(), set1.strings_.end(), *it2);
		if (it1 == set1.strings_.end())
			temp.strings_.push_back(*it2);
	}
	return temp;
}

ostream& operator<<(ostream& outs, const StringSet set)  
{
	for (size_t i = 0; i < set.getSize(); ++i)
	{
		outs << set.strings_[i] << " ";
	}
	return outs;
}



StringSet operator*(StringSet set1, StringSet set2) 
{
	std::vector<string>::iterator it1, it2, it3;
	set1.edit();
	set2.edit();
	it1 = set1.strings_.begin();
	it2 = set2.strings_.begin();
	StringSet temp;
	for (it2; it2 != set2.strings_.end(); ++it2)
	{
		it1 = find(set1.strings_.begin(), set1.strings_.end(), *it2);
		it3 = find(temp.strings_.begin(), temp.strings_.end(), *it2);

		if (it1 != set1.strings_.end() && it3 == temp.strings_.end())
			temp.strings_.push_back(*it2);
	}
	return temp;
}


void StringSet::remove(string str)
{
	vector<string>::iterator it;
	it = find(strings_.begin(), strings_.end(), str);
	if (it != strings_.end())
		strings_.erase(it);
}

void StringSet::clear()
{
	strings_.erase(strings_.begin(), strings_.end());
}


void StringSet::edit() {
	int pos;
	for (int i = 0; i < getSize(); ++i)
	{
		pos = strings_[i].find_first_of(",.!;?");
		if(pos!=-1)
		strings_[i].erase(pos);
	}
	for (int i = 0; i < getSize(); ++i)
	{
		for (int j = 0; j < strings_[i].length(); ++j)
		{
			if (isupper(strings_[i][j]))
				strings_[i][j] = tolower(strings_[i][j]);
		}
	}

}

double similarity(StringSet& set1, StringSet& set2)
{
	StringSet unionSet,intersection;
	set1.edit();
	set2.edit();
	unionSet = set1 + set2;
	intersection = set1 * set2;

	return  static_cast<double>(intersection.getSize())/(sqrt(set1.getSize()*set2.getSize()));
}