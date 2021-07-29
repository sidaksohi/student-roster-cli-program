#include <iostream>
#include "securityStudent.h"
using namespace std;

securityStudent::securityStudent():student(){
	dtype = SECURITY; 
}

securityStudent::securityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], degreeType degreetype)
	:student(studentID, firstName, lastName, emailAddress, age, daysToComplete){
	dtype = SECURITY;
}

degreeType securityStudent::getDegreeType(){ //Calling virtual function from student.h
	return SECURITY; 
}

void securityStudent::print() { //Calling virtual function from student.h
	this->student::print();
	cout << "SECURITY" << endl; //Output the only missing string from the student data
}

securityStudent::~securityStudent() {
	student::~student(); //Call the base class destructor
}