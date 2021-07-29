#include <iostream>
#include "networkStudent.h"
using namespace std;

networkStudent::networkStudent() :student() {
	dtype = NETWORK;
}

networkStudent::networkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], degreeType degreetype)
	: student(studentID, firstName, lastName, emailAddress, age, daysToComplete) {
	dtype = NETWORK;
}

degreeType networkStudent::getDegreeType() { //Calling virtual function from student.h
	return NETWORK;
}

void networkStudent::print() { //Calling virtual function from student.h
	this->student::print();
	cout << "NETWORK" << endl; //Output the only missing string from the student data
}

networkStudent::~networkStudent() {
	student::~student(); //Call the base class destructor
}