//This is the implementation file for the class Racer
//and class Time
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Racer.h"
#include<algorithm>
using std::cout; using std::cin; using std::endl;
using std::string;


	int digitToInt(char c)
	{
		if (isdigit(c))
			return static_cast<int>(c) - static_cast<int>('0');
		else
		{
			cout << "INVALID TIME!";
			exit(1);
		}
	}
	



bool Time::isValid(int num, char c)
{
	c = tolower(c);

	if (c == 'h')
	{
		if (num >= 0 && num < 24)
			return 1;
		else
		{
			return 0;
		}
	}
	else if (c =='s' || c =='m')
	{
		if (num >= 0 && num < 60)
			return 1;
		else
		{
			return 0;
		}

	}
	else
	{
		cout << "INVALID CHARACTER!";
		exit(1);
	}
		
}

Time::Time(int h, int m, int s)
{
	setHours(h);
	setMinutes(m);
	setSeconds(s);
}

void Time::setHours(int h)
{
	if (isValid(h, 'h'))
		hours_ = h;
	else
	{
		cout << "INVALID HOURS!";
		exit(1);
	}
}

void Time::setMinutes(int m)
{
	if (isValid(m, 'm'))
		minutes_ = m;
	else
	{
		cout << "INVALID MINUTES!";
		exit(1);
	}
}

void Time::setSeconds(int s)
{
	if (isValid(s, 's'))
		seconds_ = s;
	else
	{
		cout << "INVALID SECONDS!";
		exit(1);
	}
}

istream& operator>>(istream& ins, Time& time)
{
	char next;
	int h = 0, m = 0, s = 0;
	ins.get(next);
	h = digitToInt(next) * 10;
	ins.get(next);
	h += digitToInt(next);
	time.setHours(h);
	ins.get(next);//ignoring the :
	
	ins.get(next);
	m = digitToInt(next) * 10;
	ins.get(next);
	m += digitToInt(next);
	time.setMinutes(m);
	ins.get(next);//ignoring the :

	ins.get(next);
	s = digitToInt(next) * 10;
	ins.get(next);
	s += digitToInt(next);
	time.setSeconds(s);
	newline(ins);
	return ins;
}

Time operator-(const Time& time1, const Time& time2)
{
	
	int h = 0, min = 0, sec = 0;
	int totalSeconds;
	totalSeconds = (time1.getHours() - time2.getHours())*3600;
	totalSeconds+= (time1.getMinutes() - time2.getMinutes())*60;
	totalSeconds+= (time1.getSeconds() - time2.getSeconds());
	if (totalSeconds < 0)
	{
		cout << "TOTAL TIME BECOMES NEGATIVE!\n";
		exit(1);
	}
	h = totalSeconds /3600;
	totalSeconds -= h * 3600;
	min = totalSeconds / 60;
	totalSeconds -= min * 60;
	sec = totalSeconds;
	Time temp(h, min, sec);
	return temp;
}

Time operator+(const Time& time1, const Time& time2)
{
	int h = 0, min = 0, sec = 0;
	int totalSeconds;
	totalSeconds = (time1.getHours() + time2.getHours()) * 3600;
	totalSeconds += (time1.getMinutes() + time2.getMinutes()) * 60;
	totalSeconds += (time1.getSeconds() + time2.getSeconds());

	h = totalSeconds / 3600;
	totalSeconds -= h * 3600;
	min = totalSeconds / 60;
	totalSeconds -= min * 60;
	sec = totalSeconds;
	Time temp(h, min, sec);
	return temp;
}

bool operator==(const Time& lhs, const Time& rhs) //This code is not checked
{
	return lhs.hours_ == rhs.hours_ && lhs.minutes_ == rhs.minutes_
		&& lhs.seconds_ == rhs.seconds_;
}

 ostream& operator<<(ostream& outs, const Time& time)
{
	 int h, min, sec;
	 h = time.getHours(); min = time.getMinutes(); sec = time.getSeconds();

	 if (h < 10)
		 outs << "0";
	 outs << h << ":";
	 if (min < 10)
		 outs << "0";
	 outs << min << ":";
	 if (sec < 10)
		 outs << "0";
	 outs << sec;

	 return outs;

}


Racer::Racer(int number, Name name)
{
	name_.fName_ = name.fName_;
	name_.lName_ = name.lName_;
	number_ = number;
}

Time Racer::totalTime()const
{
	Time temp;
	temp = timeRecord_.back() - startTime_ ;
	return temp;
}

double Racer::pace()const
{
	
	double time;
	time = totalTime().getHours();
	time += totalTime().getMinutes() / 60.;
	time += totalTime().getSeconds()/3600.;
	return (distance_ / time);
}

//Till this point in code everything is checked

bool operator==(const Racer& lhs, const Racer& rhs)
{
	return lhs.position_ == rhs.position_;
}

void Racer::setPosition(const vector<double> speeds,int players)
{
	int index;
	for (int i = 0; i < speeds.size(); ++i)
	{
		if (this->pace() == speeds[i])
		{
			index = i;
			break;
		}
	}
	if (index < 0)
	{
		cout << "error setting position!";
		exit(1);
	}
	position_ = speeds.size() - index;
}

void newline(istream& ins)
{
	char next;
	
		do
		{
			ins.get(next);
		} while (next != '\n'&& !ins.eof());
	
	
}


int getIndex(vector<Racer> race, int number)
{
	for (int i = 0; i < race.size(); ++i)
	{
		if (race[i].getNumber() == number)
			return i;
	}
	return -1;
}


int getIndex(vector<Racer> race, Name name)
{
	for (int i = 0; i < race.size(); ++i)
	{
		if (name.fName_ == race[i].getName().fName_
			&& name.lName_ == race[i].getName().lName_)
			return i;
	}
	return -1;
}

void setRace(istream& ins, vector<Racer>&race)
{
	int i = 0;
	int number;
	Name name;
	char c;
	Racer racer;
	do
	{
		
		ins >> number;
		ins.get(c);
		ins >> name.fName_;
		ins >> name.lName_;
		race.push_back(racer);
		race[i].setName(name);
		race[i].setNumber(number);
		++i;
	} while (!ins.eof());
	
}


void blastoff(istream& ins,vector<Racer>&race)
{
	Time stime;
	ins >> stime;
	for (int i = 0; i < race.size(); ++i)
	{
		race[i].start(stime);
	}
	int index;
	Time time;
	int number;
	char c;
	do
	{
		ins >> number;
		ins >> c;
		ins >> number;
		index = getIndex(race, number);
		ins >> c;
		ins >> time;
		race[index].setTimeRecord(time);

	} while (!ins.eof());

	vector<double>speeds;
	
	int size = race.size();
	for (auto i : race)
	{
		if (find(speeds.begin(), speeds.end(), i.pace()) == speeds.end())
		speeds.push_back(i.pace());
	}
	sort(speeds.begin(), speeds.end());
	
	for (int i = 0; i < race.size(); ++i)
	{
		race[i].setSplitTimes();
		race[i].setPosition(speeds,size);
	}
}

void Racer::setSplitTimes()
{
	for (int i = 0; i < timeRecord_.size()-1; ++i)
	{
		splitTimes_.push_back( timeRecord_[i]- startTime_ );
		splitTimes_.push_back(timeRecord_[i + 1] - timeRecord_[i]);
	}
}

ostream& operator<<(ostream& outs, const Racer& racer)
{
	outs << "Name: " << racer.getName().fName_ << " " << racer.getName().lName_ << endl;
	outs << "Number: " << racer.getNumber() << endl;
	outs << "Position: " << racer.getPosition() << endl;
	outs << "Split Times:\n";
	for (auto i : racer.splitTimes_)
	{
		outs << i << endl;
	}
	outs << "Total Time: " << racer.totalTime() << endl;
	outs << "Average Pace: " << racer.pace() << " mi/h";
	return outs;
}


//edit splitTime function
//set splitTimes, positions, and other needs in blastoff func.
