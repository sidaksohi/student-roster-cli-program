#include <iostream>
#include <string>
#include "student.h"
#pragma once
using namespace std;

class networkStudent:public student {
public:
	networkStudent();
	networkStudent(
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

	~networkStudent();
};

