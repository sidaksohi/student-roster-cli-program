#include <iostream>
#include <string>
#include "student.h"
#pragma once
using namespace std;

class securityStudent:public student{
public:
	securityStudent();
	securityStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysToComplete[],
		degreeType degreetype
	);
	
	//Virtual functions from student.h
	degreeType getDegreeType();
	void print();

	~securityStudent();
};

