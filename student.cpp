#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

student::student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int x = 0; x < numOfDays; x++)daysToComplete[x] = 0;
}

student::student(string ID, string first, string last, string email, int a, int days[]){
	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->age = a;
	for (int x = 0; x < numOfDays; x++)daysToComplete[x] = days[x];
}

//Get values via return function
string student::getID(){
	return studentID;
}

string student::getFirst() {
	return firstName;
}

string student::getLast(){
	return lastName;
}

string student::getEmailAddress() {
	return emailAddress;
}

int student::getAge(){
	return age;
}

int * student::getDays(){
	return daysToComplete;
}

//Set values using this->
void student::setID(string ID){
	this->studentID = ID;
}

void student::setFirst(string first){
	this->firstName = first;
}

void student::setLast(string last){
	this->lastName = last;
}

void student::setEmailAddress(string email) {
	this->emailAddress = email;
}

void student::setAge(int a){
	this->age = a;
}

void student::setDays(int days[]){
	for (int x = 0; x < numOfDays; x++) {
		daysToComplete[x] = days[x];
	}
}

void student::print() { //Using getters to return values
	cout << left << setw(5) << getID();
	cout << left << setw(10) << getFirst();
	cout << left << setw(10) << getLast();
	cout << left << setw(35) << getEmailAddress();
	cout << left << setw(8) << getAge();
	cout << left << setw(1) << getDays()[0] << "," << getDays()[1] << "," << getDays()[2] << "     ";
}

int student::returnID() {
	return stoi(studentID.substr(1, 1));
}

student::~student() {
	//empty destructor
}
