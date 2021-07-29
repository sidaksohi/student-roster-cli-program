#include <iostream>
#include <string>
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#pragma once
using namespace std;

class roster{
private:
    student** students; //student* students[5] is the same thing, however with ** it is sized dynamically
    int cap;
public:
    roster();
    roster(int cap);
    student* getStudentAt(int index);
    void parse(string row);
    void add(int index, string studentID, string firstName, string lastName, string emailAddress, int age, int day1, int day2, int day3, degreeType dt);
    void printAll();
    void remove(string ID);
    void printAverageDays(string stringID);
    void printInvalidEmails();
    void printByDegreeType(degreeType dt);
    ~roster();
};
