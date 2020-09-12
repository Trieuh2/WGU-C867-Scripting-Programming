#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

// Adds a student to the classRosterArray with the provided parameters
void roster::add(string studentID,
				string firstName,
				string lastName,
				string emailAddress,
				int age,
				int daysInCourse1,
				int daysInCourse2,
				int daysInCourse3,
				DegreeProgram degreeProgram) {
	// create an integer array to create the daysLeftEachCourse for the student object
	int daysLeft[3];
	daysLeft[0] = daysInCourse1;
	daysLeft[1] = daysInCourse2;
	daysLeft[2] = daysInCourse3;

	// create the student object to add to the roster
	// and append the newly created student object to the next empty sloty of the classRoster array representing the studentData table
	classRosterArray[numStudentsAdded] = new student(studentID, firstName, lastName, emailAddress, age, daysLeft, degreeProgram);
	++numStudentsAdded;
}

// TODO:
// Identifies a student within classRosterArray with the studentID and removes it
//		if no student with such studentID exists, print none found
void roster::remove(string studentID) {
	bool removed = false;

	cout << this->classRosterArray[0]->GetStudentID() << endl;
	cout << studentID << endl;
	cout << endl;

	for (int i = 0; i < numStudentsAdded; ++i) {
		if ((this->classRosterArray[i]->GetStudentID() == studentID) == 0) {
			this->classRosterArray[i] = NULL;
			removed = true;
			cout << i << endl;
		}
	}
	if (removed == false) {
		cout << "The student with the provided ID: \"" << studentID << "\" was not found" << endl;
	}
	cout << removed << endl;
}

// Prints all students within the classRosterArray line by line
void roster::printAll() {
	for (int i = 0; i < numStudentsAdded; ++i) {
		this->classRosterArray[i]->print();
	}
}

// TODO:
// Identifies the student by the parameter studentID, and returns the average of days to complete the 3 classes
void roster::printAverageDaysInCourse(string studentID) {

}

// TODO:
// Verifies and prints all email addresses that contain an extra period/commas/spaces
void roster::printInvalidEmails() {

}


// TODO:
// Prints out students that match the inputted degreeProgram
void roster::printByDegreeProgram(DegreeProgram degreeProgram) {

}