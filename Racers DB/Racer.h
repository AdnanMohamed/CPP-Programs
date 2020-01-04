//This is the interface file for the class Racer
//and class Time
#ifndef RACER_H
#define RACER_H
#include<vector>
#include<fstream>
#include<string>
using std::vector; using std::ostream;
using std::string; using std::istream;

struct Name
{
	string fName_;
	string lName_;
};

class Time {
public:
	Time(int h, int m, int s); //constructor sets time if valid else prompts user and exit
	Time():hours_(0), minutes_(0), seconds_(0) { }
	
	void setHours(int h);    // these functions take an integer to set it to  
	void setMinutes(int m);	 // the hours/minutes/seconds as specified by the function name.
	void setSeconds(int s);  // if the integer was not valid the user will be prompt

	int getHours() const { return hours_; }     
										  
	int getMinutes() const { return minutes_; } 
										  
	int getSeconds() const { return seconds_; } 

	friend istream& operator>>(istream&, Time&); //reads times like (HH:MM:SS)

	//prints time like (HH:MM:SS)
	friend ostream& operator<<(ostream&, const Time&);

	//returns true if both times are equal else false
	friend bool operator==(const Time&, const Time&);

	//subtracts times and returns the difference
	friend Time operator-(const Time&, const Time&);

	//adds times and returns the sum
	friend Time operator+(const Time&, const Time&);
private:
	int hours_;
	int minutes_;
	int seconds_;
	bool isValid(int, char);
};

typedef vector<Time> TimeStamp;
typedef vector<int>VectorInt;
//typedef vector<Racer>Racers;
class Racer {
public:
	Racer(int number,Name);
	//Precondition: number and Name have values
	//Postcondition: number_ is initialized equaled to number and the racer's full name is filled
	Racer(){}
	void setNumber(int number) { number_ = number; }					  //These functions are 
	void setName(Name name) { name_ = name; }							  //used to set the
	void setTimeRecord(Time time) { timeRecord_.push_back(time); }		  //attributes of this class
	void setPosition(const vector<double>,int players);					  //
	void setSplitTimes();									              //
	void start(const Time& stime) { startTime_ = stime; }			      //

	int getNumber() const{ return number_; }				//These functions used 
	Name getName() const{ return name_; }				    //get the attributes of
	TimeStamp getTimeRecord() const{ return timeRecord_; }  //this class
	Time getStartTime() const{ return startTime_; }		    //
	int getPosition() const{ return position_; }            //
	TimeStamp getSplitTimes() const{ return splitTimes_; }  //returns vector of time, which contains the split time in the form (HH MM SS)

	//returns the overall race time 
	Time totalTime()const;

	//returns the overall race pace of the racer
	double pace()const;

	//compares between two racers if finishing time is equal returns true else false
	friend bool operator==(const Racer& lhs, const Racer& rhs);

	//prints out the racer's name, number,splitTime, overall Time, position, overall pace
	friend ostream& operator<<(ostream&, const Racer&);
private:
	int number_;
	Name name_;
	TimeStamp timeRecord_;
	int position_;
	TimeStamp splitTimes_;
	const double distance_ = 13.1;
	Time startTime_;
};

void newline(istream& ins);

//returns the index of the racer in the vector that matches 
//the given number. If not found returns -1
int getIndex(vector<Racer> race, int number);

//returns the index of the element in the vector of Racer
//if the given name matches an element. else returns -1
int getIndex(vector<Racer> race, Name name);


void setRace(istream& ins, vector<Racer>&race);  //This function is used to set up the race.
												//It reads the information about the competitors from the file
												//and set ups the racers number and name.



void blastoff(istream& ins, vector<Racer>&race);  //This function is used to read the information about 
												 //the race from a file which contains the records.
												 //It sets the start time and records for each individual.
												 //Position, pace total time, split times will be set

#endif
