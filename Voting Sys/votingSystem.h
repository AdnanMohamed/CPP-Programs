#ifndef votingSystem_h
#define votingSystem_h
#include<string>
#include<vector>
using std::string; using std::vector;
using std::istream;

class Voter
{
public:
	Voter(int id,string vote):id_(id),vote_(vote){} //constructor
	Voter(){} //default constructor

	//sets the id of the voter
	void setId(int id) { id_ = id; }

	//sets the vote of the voter
	void setVote(string vote) { vote_ = vote; }

	//gets the id of the voter
	int getId()const { return id_; }

	//gets the vote of the voter
	string getVote()const { return vote_; }

	//inputs the attributes of this class
	friend istream& operator>>(istream& ins, Voter& voter);

	//returns the number of choices available
	int getChoices() { return choices_; }
private:
	int id_;
	string vote_;
	static const int choices_ = 9;
};
typedef vector<Voter>Voters;

//displays a table of the election results
void showElection(Voters);

void showPercentages(Voters voters);

vector<int> count(Voters voters, int size);

#endif
