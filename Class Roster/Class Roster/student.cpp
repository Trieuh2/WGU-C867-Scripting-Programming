#include <iostream>
#include "student.h"
using namespace std;

// Constructor: creates a student object with the inputted parameters
student::student(string id, string fn, string ln, string ea, int a, int daysLeft[numClasses], DegreeProgram prg) {
	studentID = id;
	firstName = fn;
	lastName = ln;
	emailAddress = ea;
	age = a;
	this->SetDaysLeftEachCourse(daysLeft);
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
		cout << " \t Degree Program: Security" << endl;
	}

	else if (program == NETWORK) {
		cout << " \t Degree Program: Network" << endl;
	}

	else if (program == SOFTWARE) {
		cout << " \t Degree Program: Software" << endl;
	}
}			

// Accessor methods
string student::GetStudentID() {
	return studentID;
}

string student::GetFirstName() {
	return firstName;
}

string student::GetLastName() {
	return lastName;
}

string student::GetEmailAddress() {
	return emailAddress;
}

int student::GetAge() {
	return age;
}

int* student::GetDaysLeftEachCourse() {
	return daysLeftEachCourse;
}

DegreeProgram student::GetDegreeProgram() {
	return program;
}

// Mutator methods
void student::SetStudentID(string id) {
	studentID = id;
}

void student::SetFirstName(string fn) {
	firstName = fn;
}

void student::SetLastName(string ln) {
	lastName = ln;
}

void student::SetEmailAddress(string ea) {
	emailAddress = ea;
}

void student::SetAge(int a) {
	age = a;
}

void student::SetDaysLeftEachCourse(int daysLeft[3]) {
	for (int i = 0; i < numClasses; ++i) {
		daysLeftEachCourse[i] = daysLeft[i];
	}
}

void student::SetDegreeProgram(DegreeProgram dp) {
	program = dp;
}