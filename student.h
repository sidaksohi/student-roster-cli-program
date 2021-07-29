#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"
#pragma once
using namespace std;

class student
{
public:
	const static int numOfDays = 3;
protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[numOfDays];
	degreeType dtype;
public:
	student();
	student(string ID, string first, string last, string email, int a, int days[]);


	//Get values
	string getID();
	string getFirst();
	string getLast();
	string getEmailAddress();
	int getAge();
	int* getDays(); //Using pointer here because arrays are pointers
	virtual degreeType getDegreeType() = 0; //Virtual Class

	//Set values
	void setID(string ID);
	void setFirst(string first);
	void setLast(string last);
	void setEmailAddress(string email);
	void setAge(int a);
	void setDays(int days[]);

	virtual void print() = 0;
	virtual int returnID(); //Returns the index of the ID

	//Empty destructor
	~student();
};

