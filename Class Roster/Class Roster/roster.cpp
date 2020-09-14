#include <iostream>
#include "roster.h"
#include <sstream>
#include "student.h"
#include <string>
#include <vector>
using namespace std;

// Default Constructor, will contain maximum size of 5 students
roster::roster() {
	this->classRosterArray = new student * [5];
	this->numStudentsAdded = 0;
	this->ROSTER_SIZE = 5;
}

// Destructor:
// releases the memory that was allocated dynamically in roster
roster::~roster() {
	delete this->classRosterArray;
}

// Parse method partially developed from https://www.geeksforgeeks.org/program-to-parse-a-comma-separated-string-in-c/
// Parses the array of strings delimited by commas into their individual variables as input parameters for the student class, create a student, and add to roster.
void roster::parse(const string studentData[]) {
	// Each index within studentData[] contains a string that has 9 commas, allowing us to identify each variable needed for creating a student
	
	// Parse the parameters into their own individual variables and then add to the roster
	for (int i = 0; i < ROSTER_SIZE; ++i) {
		string input = studentData[i]; // takes the current string within studentData[] to parse from

		vector<string> v; // each index within the vector will hold a string version of the parameter we need to use for creating a student
		stringstream ss(input);

		// Parse the parameters into the vector
		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}

		// Use the vectors to set the string variables
		string studentID = v[0];
		string firstName = v[1];
		string lastName = v[2];
		string emailAddress = v[3];

		// Use stringstream to set the int variables from the parsed strings in the vector
		stringstream ageStream(v[4]);
		int age;
		ageStream >> age;

		stringstream daysStream1(v[5]);
		int daysInCourse1;
		daysStream1 >> daysInCourse1;

		stringstream daysStream2(v[6]);
		int daysInCourse2;
		daysStream2 >> daysInCourse2;

		stringstream daysStream3(v[7]);
		int daysInCourse3;
		daysStream3 >> daysInCourse3;

		// Use the vector and perform string comparisons to set the DegreeProgram variable
		DegreeProgram degreeProgram;
		if (v[8] == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (v[8] == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (v[8] == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}

		// Use the parsed parameters to add students to the roster
		this->add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	}
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
	int numStudents = this->getNumStudentsAdded();

	// append the newly created student object to the roster and increase the count of students added
	this->classRosterArray[numStudents] = new student(studentID, firstName, lastName, emailAddress, age, daysLeft, degreeProgram);
	++numStudents;
	this->setNumStudentsAdded(numStudents);
}

// Identifies a student within the roster with the inputted studentID and removes it
//		if no student with such studentID exists, print none found
void roster::remove(string studentID) {
	// find the index of the student with the inputted studentID from remove()
	int index = this->findStudentWithID(studentID);

	// if the index returned is -1, this means that there were no students found with the provided studentID.
	if (index == -1) {
		cout << "Student with ID " << studentID << " does not exist." << endl;
	}
	else {
		classRosterArray[index] = NULL; // there was a student found, nullify the pointer
	}
}

// Prints all students within the classRosterArray line by line
void roster::printAll() {
	// loops through and prints out the student information if the pointer to the student is not null
	for (int i = 0; i < this->getRosterSize(); ++i) {
		if (this->isNull(i) == false) {
			this->classRosterArray[i]->print();
		}
	}
}

// Identifies the student by the parameter studentID, and returns the average of days to complete the 3 classes
void roster::printAverageDaysInCourse(string id) {
	int index = this->findStudentWithID(id);
	student s = *this->getStudentAtIndex(index);
	int* days = s.getDaysLeftEachCourse();

	int avg = (days[0] + days[1] + days[2]) / 3;
	cout << "Average number of days left for " << s.getFirstName() << " " << s.getLastName() << ": " << avg << endl;
}

// Verifies and prints all email addresses that contain an extra period/commas/spaces
void roster::printInvalidEmails() {
	for (int i = 0; i < this->getRosterSize(); ++i) {
		bool hasSpaces = false;
		bool hasPeriod = false;
		bool hasAtSymbol = false;

		// gets the email address of the student in the current index
		string emailAddress = this->classRosterArray[i]->getEmailAddress();
		 
		// sorts through the emailAddress string and checks if it has '.' and '@' and does not have spaces ' '
		for (int j = 0; j < emailAddress.size(); ++j) {
			char characterN = emailAddress[j];

			if (characterN == ' ') {
				hasSpaces = true;
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
		DegreeProgram dp = s.getDegreeProgram();

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
		if (this->isNull(i) == false) {
			string currentIndexStudentID = this->classRosterArray[i]->getStudentID();

			if (currentIndexStudentID == id) {
				index = i;
			}
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

// returns the number of students added to the roster
int roster::getNumStudentsAdded() {
	return numStudentsAdded;
}

// sets the number of students that have been added to the roster
void roster::setNumStudentsAdded(int num) {
	numStudentsAdded = num;
}