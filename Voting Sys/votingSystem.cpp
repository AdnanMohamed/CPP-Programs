#include<iostream>
#include<fstream>
#include"votingSystem.h"
using std::cin; using std::cout; using std::endl;
using std::ifstream;
istream& operator>>(istream& ins, Voter& voter)
{
	ins >> voter.id_;
	ins >> voter.vote_;
	return ins;
}

void showElection(Voters voters) {
	cout << "\tID\tVotes" << "\n\n";
	for (auto i : voters)
	{
		cout <<"\t"<< i.getId() << "\t" << i.getVote();
		cout << "\n\n";
	}
}

void showPercentages(Voters voters)
{
	vector<vector<int>>subject; //vector of vectors which holds each subject of voting and the number of votes for each subject
	vector<double>percentages;
	int size=voters[0].getChoices();
	
	subject.push_back(count(voters, size));
	
	double totalVoters = static_cast<double>(voters.size());
	for (int i = 0; i < subject.size(); ++i)
	{
		for (int j = 0; j < subject[i].size(); ++j)
			percentages.push_back(subject[i][j] / totalVoters);
	}
	cout.setf(std::ios::showpoint);
	cout.setf(std::ios::fixed);
	cout.precision(2);
	char c = 'A';
	for (int i = 0; i < percentages.size(); ++i,++c)
	{
		if (i == 0)
			cout << "VOTE FOR MAYOR:\n";
		else if (i == 3)
			cout << "PROPORTION 17:\n";
		else if (i == 5)
			cout << "MEASURE 1:\n";
		else if (i == 7)
			cout << "MEASURE 2:\n";
		cout << c << ": " << percentages[i]*100<<"%" << endl;
	}
	
}

vector<int> count(Voters voters,int size)
{
	int sum = 0;
	int target;
	vector<int>results;
	char vote = 'A';
	for (int i = 0; i < size; ++i)
	{
		for (auto i : voters)
		{
			target = i.getVote().find_first_of(vote);
			if (target != string::npos)
			{
				++sum;
			}
		}
		results.push_back(sum);
		sum = 0;
		++vote;
	}
	return results;
}
	



