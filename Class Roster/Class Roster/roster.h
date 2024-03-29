#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <iostream>
using namespace std;

class roster {


	public:
		roster(); // constructor
		~roster(); // destructor

		void add(string studentID,	// adds a student to the roster using the parameters
				string firstName,
				string lastName,
				string emailAddress,
				int age,
				int daysInCourse1,
				int daysInCourse2,
				int daysInCourse3,
				DegreeProgram degreeProgram);
		void remove(string studentID);	// removes user from the class roster with the specified studentID
		void parse(const string studentData[]);	// parses an inputted array of students and adds the students to the roster
		void printAll();// prints all of the students in the roster
		void printAverageDaysInCourse(string studentID);// takes the average number of days left to complete the 3 courses
		void printInvalidEmails();	// verifies and prints the email addresses that contain invalid characters "@", ".", and " "
		void printByDegreeProgram(DegreeProgram degreeProgram);	// prints out student info for a degree program specified by degreePogram
		void setNumStudentsAdded(int num);	// sets the numStudentsAdded internal data member to the inputted integer

		student* getStudentAtIndex(int index);	// returns the student object at the inputted index within the classRosterArray
		int	findStudentWithID(string id);	// returns the index of the student with the inputted studentID
		int getRosterSize();	// returns the maximum number of students that can be in the classRosterArray
		bool isNull(int index);		// checks whether there is a student at the given index
		int getNumStudentsAdded();	// returns the number of students added into the classRosterArray

			
	// private internal data members
	private:
		student** classRosterArray; // array of pointers to hold the data provided in the studentData table
		int numStudentsAdded;	// current number of students added to the roster
		int ROSTER_SIZE;	// maximum number of students that can be added to the roster
};

#endif