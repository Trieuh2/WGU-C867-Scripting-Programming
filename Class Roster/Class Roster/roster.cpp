#include <iostream>
#include "roster.h"
#include "student.h"
#include <string>
using namespace std;

// constructor
roster::roster() {
	numStudentsAdded = 0;
}

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
	int numStudents = this->getNumStudentsAdded();

	this->classRosterArray[numStudents] = new student(studentID, firstName, lastName, emailAddress, age, daysLeft, degreeProgram);
	++numStudents;
	this->setNumStudentsAdded(numStudents);
}

// Identifies a student within classRosterArray with the studentID and removes it
//		if no student with such studentID exists, print none found
void roster::remove(string studentID) {
	int index = this->findStudentWithID(studentID);

	if (index == -1) {
		cout << "Student with ID " << studentID << " does not exist." << endl;
	}
	else {
		this->classRosterArray[index] = NULL;
	}
}

// Prints all students within the classRosterArray line by line
void roster::printAll() {
	for (int i = 0; i < this->getRosterSize(); ++i) {
		if (this->isNull(i) == false) {
			this->classRosterArray[i]->print();
		}
	}
}

// Identifies the student by the parameter studentID, and returns the average of days to complete the 3 classes
void roster::printAverageDaysInCourse(string id) {
	// Find the index of the student with the given studentID
	int index = this->findStudentWithID(id);
	student s = *this->getStudentAtIndex(index);
	int* days = s.GetDaysLeftEachCourse();

	int avg = (days[0] + days[1] + days[2]) / 3;
	cout << "Average number of days left for " << s.GetFirstName() << " " << s.GetLastName() << ": " << avg << endl;
}

// Verifies and prints all email addresses that contain an extra period/commas/spaces
void roster::printInvalidEmails() {
	for (int i = 0; i < this->getRosterSize(); ++i) {
		bool hasSpaces = true;
		bool hasPeriod = false;
		bool hasAtSymbol = false;

		// gets the email address of the student in the current index
		string emailAddress = this->classRosterArray[i]->GetEmailAddress();
		 
		// sorts through the emailAddress string and checks if it has '.' and '@' and does not have spaces ' '
		for (int j = 0; j < emailAddress.size(); ++j) {
			char characterN = emailAddress[j];

			if (characterN == ' ') {
				hasSpaces = false;
			}
			if (characterN == '.') {
				hasPeriod = true;
			}
			if (characterN == '@') {
				hasAtSymbol = true;
			}
		}

		// if the email address is missing '.' or '@', then the email address is not valid and the program prints out the invalid email addresses
		if (hasSpaces == true) {
			cout << emailAddress << " - no spaces allowed." << endl;
		}

		else if (hasPeriod == false) {
			cout << emailAddress << " - missing period." << endl;
		}

		else if (hasAtSymbol == false) {
			cout << emailAddress << " - missing @ symbol." << endl;
		}
	}
}

// Prints out students that match the inputted degreeProgram
void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; ++i) {
		student s = *this->getStudentAtIndex(i);
		DegreeProgram dp = s.GetDegreeProgram();

		if (dp == degreeProgram) {
			s.print();
		}
	}
}

// returns the student object at the inputted index within the classRosterArray
student* roster::getStudentAtIndex(int index) {
	return classRosterArray[index];
}

//returns the index of the student with the inputted studentID
int roster::findStudentWithID(string id) {
	int index = -1;

	for (int i = 0; i < this->getRosterSize(); ++i) {
		string currentIndexStudentID = this->classRosterArray[i]->GetStudentID();

		if (currentIndexStudentID == id) {
			index = i;
		}
	}

	return index;
}

// returns the maximum number of students that can be in the classRosterArray
int roster::getRosterSize() {
	return this->ROSTER_SIZE;
}

// checks whether there is a student at the given index
bool roster::isNull(int index) {
	bool noStudent = false;

	if (this->classRosterArray[index] == NULL) {
		noStudent = true;
	}

	return noStudent;
}

int roster::getNumStudentsAdded() {
	return this->numStudentsAdded;
}

void roster::setNumStudentsAdded(int num) {
	numStudentsAdded = num;
}