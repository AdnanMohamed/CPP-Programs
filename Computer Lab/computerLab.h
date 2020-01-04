#ifndef computerLab_h
#define computerLab_h

typedef int* IntPtr;

class ComputerLab {
public:
	void setLab(); //gives -1 for every station in myLab_[][];
	void menu(int &option); //This outputs a menu with 4 choices and the user enters a choice
	void login(int id, int lab, int station); //sets the value of the station in myLab[][]
											  //to the given id
	
	void logout(int lab,int station);		//sets the value of the given station in the specified lab to -1
	bool match(int id, int id2); //returns true if id matches id2
	void search(int id); //Prints the the result of searching for the given id.
						 // prints "lab(number), station(number)"
	void display();	//diplays the every lab with the stations. It mentions the id in each station
					//or empty if there is no one logged in
	void setLabSize();//lets the user to set number of stations in each lab
	bool isValid(int lab, int station);//returns true if the given lab and station are valid else false
	bool isValid(int id);//returns true if given id is true else false
	bool occupied(int lab,int station);//returns true if the station is occupied
	
private:
	
	int labSize1_; // These 4 variables
	int labSize2_; // holds the size of each 
	int labSize3_; // specified lab
	int labSize4_; //

	IntPtr* myLab_; //This is a multidimensional array wich holds the labs and stations in each lab
	static const int labs_ = 4; //Number of labs
};

#endif
