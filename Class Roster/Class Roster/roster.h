#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <iostream>
using namespace std;

class roster {
	public:
		void add(string studentID,									// Adds a student to the roster using the parameters
				string firstName,
				string lastName,
				string emailAddress,
				int age,
				int daysInCourse1,
				int daysInCourse2,
				int daysInCourse3,
				DegreeProgram degreeProgram);
		void remove(string studentID);								// removes user from the class roster with the specified studentID
		void printAll();											// prints all of the students in the roster
		void printAverageDaysInCourse(string studentID);			// takes the average number of days left to complete the 3 courses
		void printInvalidEmails();									// verifies and prints the email addresses that contain invalid characters "@", ".", and " "
		void printByDegreeProgram(DegreeProgram degreeProgram);		// prints out student info for a degree program specified by degreePogram

	// private internal data members
	private:
		student* classRosterArray[5]; // array of pointers to hold the data provided in the studentData table
		int numStudentsAdded = 0;
};

#endif