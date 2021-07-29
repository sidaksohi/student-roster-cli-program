#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
using namespace std;

//Sets values to 'default'
roster::roster() {
    this->cap = -1; //Since 0 is a valid value for an array, we use -1, which is equivalent to empty
    this->students = nullptr;
}


//Set capacity
roster::roster(int cap) {
    this->cap = cap;
    this->students = new student*[cap];
}

student* roster::getStudentAt(int index) {
    return students[index];
}

void roster::parse(string row) {
    
    //Parse and store degreeTypes
    degreeType dt;
    if (row.rfind("SECURITY") < 100) {
        dt = SECURITY;
    }else if (row.rfind("SOFTWARE") < 100) {
        dt = SOFTWARE;
    }else if (row.rfind("NETWORK") < 100) {
        dt = NETWORK;
    }
    else { //Simple debug statement: if degree type is not SECURITY, SOFTWARE, or NETWORK
        cerr << "ERROR: INVALID DEGREE TYPE!\nClosing now..." << endl;
        exit(-1);
    }

    //Parse the index using ID number, by simply setting it to the character that follows 'A', and then subtracting 1 due to it being an array!
    int index = stoi(row.substr(row.find('A') + 1, 1)) - 1;

    //Parse studentID
    int rhs = row.find(',');
    string studentID = row.substr(0, rhs);

    //Parse firstName
    int lhs = rhs + 1;
    rhs = row.find(',', lhs);
    string firstName = row.substr(lhs, rhs - lhs);

    //Parse lastName
    lhs = rhs + 1;
    rhs = row.find(',', lhs);
    string lastName = row.substr(lhs, rhs - lhs);

    //Parse emailAddress
    lhs = rhs + 1;
    rhs = row.find(',', lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);

    //Parse age (string to integer)
    lhs = rhs + 1;
    rhs = row.find(',', lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));
    //Parse day1 (string to integer)
    lhs = rhs + 1;
    rhs = row.find(',', lhs);
    int day1 = stoi(row.substr(lhs, rhs - lhs));

    //Parse day2 (string to integer)
    lhs = rhs + 1;
    rhs = row.find(',', lhs);
    int day2 = stoi(row.substr(lhs, rhs - lhs));

    //Parse day3 (string to integer)
    lhs = rhs + 1;
    rhs = row.find(',', lhs);
    int day3 = stoi(row.substr(lhs, rhs - lhs));

    //Parse degreeType1
    lhs = rhs + 1;
    rhs = row.find(',', lhs);
    string degreeType1 = row.substr(lhs, rhs - lhs);

    add(index, studentID, firstName, lastName, emailAddress, age, day1, day2, day3, dt);

}

void roster::add(int index, string studentID, string firstName, string lastName, string emailAddress, int age, int day1, int day2, int day3, degreeType dt) {
    //Make the invididual days integers into an array
    int daysToComplete[student::numOfDays] = { day1, day2, day3 };
    
    //Using if & else if statements, we put the students into an array, sorted by degree type
    if (dt == degreeType::SOFTWARE) {
        students[index] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, dt);
    }
    else if (dt == degreeType::SECURITY) {
        students[index] = new securityStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, dt);
    }
    else if (dt == degreeType::NETWORK) students[index] = new networkStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, dt);
}

void roster::printAll() {//Prints all elements in the roster
    
   //Lines 111 through 121 here are just to make it pretty when you call this function by adding labels and a divider
   std::cout << left << setw(5) << "ID#";
   std::cout << left << setw(10) << "First";
   std::cout << left << setw(10) << "Last";
   std::cout << left << setw(35) << "Email Address";
   std::cout << left << setw(8) << "Age";
   std::cout << left << setw(13) << "Days to";
   std::cout << left << setw(8) << "Degree" << endl;
   std::cout << left << setw(15) << "     Name";
   std::cout << left << setw(10) << "Name";
   std::cout << right << setw(51) << "Complete" << endl;
   std::cout << "_________________________________________________________________________________________\n" << endl;
    for (int x = 0; x < cap; x++){
        (this->students)[x]->print();
    }
}

void roster::remove(string stringID) {
   std::cout << "\nRemoving Student '" << stringID << "'..." << endl; //Says the string you are removing, and then you will be notified if it is successful or failed!

    //Parse the index using ID number, by simply setting it to the character that follows 'A', and then subtracting 1 due to it being an array!
    int index = stoi(stringID.substr(stringID.find('A') + 1, 1)) - 1;

    //Now that we have the index number, add 1 to find the value which would be in the second character of the element
    int indexplus1 = index + 1;

    //If those two match, then it will remove the student!
    if (indexplus1 == students[index]->returnID()) {
       std::cout << "\nSTUDENT REMOVED!\n" << endl;
        delete this->students[index];
        for (int x = 1; x < cap; x++) { //This for loop uses the index to set element above it equal to itself, and then the one above that equal to one above it, and so on
            while ( (this->students[index + 1]->returnID()) < cap) { //This loop only runs until the end of the array, no matter how large, because of the while loop
                this->students[index] = this->students[index + x];
                this->students[index + x] = this->students[index + x + 1];
            }
         }
        cap--; //Decrease the capacity by 1, since an element was removed
    }
    else {//If the number in the studentID does not match int indexplus1 then it will return an error showing you what you entered
       std::cout << "\nError: Student '" << stringID << "' not found." << endl; 
    }
}

void roster::printAverageDays(string stringID) {

//Parse the index using ID number, by simply setting it to the character that follows 'A', and then subtracting 1 due to it being an array!
int index = stoi(stringID.substr(stringID.find('A') + 1, 1)) - 1;

//Now that we have the index number, add 1 to find the value which would be in the second character of the element
int indexplus1 = index + 1;

if (indexplus1 < cap + 1) {   //This whole thing will only work if the string is valid
    //If those two match, then it will return the average of the three days
    if (indexplus1 == students[index]->returnID()) {
        int* d = this->students[index]->getDays();
        std::cout << "Average days for " << stringID << " to complete " << student::numOfDays << " courses, is " << (d[0] + d[1] + d[2]) / 3 << ".\n";
    }
    else {//If the number in the studentID does not match int indexplus1 then it will return an error showing you what you entered
        std::cout << "\nError: Student '" << stringID << "' not found. Cannot display average days to complete." << endl;
    }
}
else cout << "Error: Cannot print average days for Student '" << stringID << "' // ID does not exist.\n";
}

void roster::printInvalidEmails() {
    for (int x = 0; x < cap; x++) {
        string y = this->students[x]->getEmailAddress();
        if (y.find('@') > 100 || y.find('.') > 100 || y.find(" ") < 100) {
            cout << y << endl;
        }
    }
}

void roster::printByDegreeType(degreeType dt) {
    for (int x = 0; x < cap; x++) {
        degreeType y = this->students[x]->getDegreeType();
        if (y == dt) this->students[x]->print();
    }
}

roster::~roster() { //Releases memory
    for (int x=0; x < cap; x++) {
        delete this->students[x];
    }
    delete students;
}








int main()
{
    //Data we are given, and we will pass through each 'string' or 'row' into class roster using a for loop
    string studentData[] = {
    "A1,Jon,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Susan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jacque,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Aaron,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Sidak,Sohi,redacted@gmail.com,21,15,21,30,SOFTWARE" 
    };    
    
    //Create int cap = to the number of strings in the array using sizeof, so we can pass it through later
    //By defining the capacity with sizeof, it will scale much better
    int cap = sizeof(studentData) / sizeof(studentData[0]);

    //My info
    std::cout << "Course Title: C*** | Programming Language Used: C++ | Name: Sidak Sohi | Student ID: #*********\n" << endl;
    std::cout << "Parsing data and adding to roster..." << endl;
    
    //Send the array, by row, into the Student class using a pointer object
    roster* input = new roster(cap);
    for (int x = 0; x < cap; x++) {
        input->parse(studentData[x]);
    }

    //Display Data
    cout << "DONE! Now displaying data...\n" << endl;
    input->printAll();

    //Print invalid eamils
    cout << "\nPrinting invalid emails...\n" << endl;
    input->printInvalidEmails();

    //Print average days to complete
    cout << "\nPrinting average days to complete courses. Invalid entries will return error message...\n" << endl;
    input->printAverageDays("A1");
    input->printAverageDays("A2");
    input->printAverageDays("A3");
    input->printAverageDays("A4");
    input->printAverageDays("A5");
    input->printAverageDays("A6");

    //Print by degree program: SOFTWARE
    cout << "\nPrinting by Degree Program: SOFTWARE\n\n";
    input->printByDegreeType(SOFTWARE);

    //Remove student and printall, attempt to remove student again
    input->remove("A3");
    input->printAll();
    input->remove("A3");

    //Explicit call to the destructor
    input->~roster();

    //End
	return 0;
}
