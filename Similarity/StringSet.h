#ifndef StringSet_h
#define StringSet_h
#include<vector>
#include<string>
using std::vector; using std::string;
using std::ostream; using std::istream;
class StringSet
{
public:
	//initializes the attribute to the given vector of strings
	StringSet(vector<string> vString) :strings_(vString) { }

	StringSet() {}

	//adds a string to the set of strings and returns the new set
	friend StringSet operator+(StringSet, string);

	//returns the union of two sets
	friend StringSet operator+(StringSet, StringSet);

	//returns the intersection of two sets
	friend StringSet operator*(StringSet, StringSet);
	//removes a string from the set
	//The string is case sensative
	void remove(string);

	//clears the entire set
	void clear();

	//returns the size of the set
	size_t getSize() const { return strings_.size(); }

	//outputs all strings in the set
	friend ostream& operator<<(ostream&, const StringSet);

	//edits the set such that all punctuation marks are removed
	//and all letters lower case. New set returned
	void edit();

	//returns the similarity -using binary cosine coefficient-
	friend double similarity(StringSet&,StringSet&);

private:
	vector<string> strings_;
};



#endif //string_h


