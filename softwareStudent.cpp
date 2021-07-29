#include <iostream>
#include "softwareStudent.h"
using namespace std;

softwareStudent::softwareStudent():student() {
	dtype = SOFTWARE;
}

softwareStudent::softwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], degreeType degreetype)
	:student(studentID, firstName, lastName, emailAddress, age, daysToComplete) {
	dtype = SOFTWARE;
}
 
degreeType softwareStudent::getDegreeType() { //Calling virtual function from student.h
	return SOFTWARE;
}

void softwareStudent::print() { //Calling virtual function from student.h
	this->student::print();
	cout << "SOFTWARE" << endl; //Output the only missing string from the student data
}

softwareStudent::~softwareStudent() {
	student::~student(); //Call the base class destructor
}