#include <iostream>
#include "student.h"
using namespace std;

// Overloaded constructor: creates a student object with the inputted parameters
student::student(string id, string fn, string ln, string ea, int a, int daysLeft[numClasses], DegreeProgram prg) {
	studentID = id;
	firstName = fn;
	lastName = ln;
	emailAddress = ea;
	age = a;
	this->setDaysLeftEachCourse(daysLeft);
	program = prg;
}

// Customized print output to display student information
void student::print() {
	cout << studentID << " \t First Name: " <<
		firstName << " \t Last Name: " <<
		lastName << " \t Age: " <<
		age << " daysInCourse: {";


	// prints the number of days left in the nth course separated by commas
	for (int n = 0; n < numClasses; ++n) {
		if (n != numClasses - 1) {
			cout << daysLeftEachCourse[n] << ", ";
		}
		else {
			cout << daysLeftEachCourse[n] << "}";
		}
	}

	// prints out the degree program and ends with new line
	if (program == SECURITY) {
		cout << " \t Degree Program: SECURITY" << endl;
	}

	else if (program == NETWORK) {
		cout << " \t Degree Program: NETWORK" << endl;
	}

	else if (program == SOFTWARE) {
		cout << " \t Degree Program: SOFTWARE" << endl;
	}
}

// Accessor methods
string student::getStudentID() {
	return studentID;
}

string student::getFirstName() {
	return firstName;
}

string student::getLastName() {
	return lastName;
}

string student::getEmailAddress() {
	return emailAddress;
}

int student::getAge() {
	return age;
}

int* student::getDaysLeftEachCourse() {
	return daysLeftEachCourse;
}

DegreeProgram student::getDegreeProgram() {
	return program;
}

// Mutator methods
void student::setStudentID(string id) {
	studentID = id;
}

void student::setFirstName(string fn) {
	firstName = fn;
}

void student::setLastName(string ln) {
	lastName = ln;
}

void student::setEmailAddress(string ea) {
	emailAddress = ea;
}

void student::setAge(int a) {
	age = a;
}

void student::setDaysLeftEachCourse(int daysLeft[3]) {
	for (int i = 0; i < numClasses; ++i) {
		daysLeftEachCourse[i] = daysLeft[i];
	}
}

void student::setDegreeProgram(DegreeProgram dp) {
	program = dp;
}