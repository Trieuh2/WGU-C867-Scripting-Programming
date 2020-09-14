#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

int main() {
	// input parameter provided by Performance Assessment
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Henry,Trieu,htrieu3@my.wgu.edu,21,10,20,30,SOFTWARE"};

	// Parses the array of student parameters into the classRoster
	roster classRoster;
	classRoster.parse(studentData);

	// Prints out general information about the course, project, and author
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001306217" << endl;
	cout << "Name: Henry Trieu" << endl;
	cout << endl;

	cout << "Done." << endl;
	// Test 1
	cout << "========================" << endl;
	cout << "Displaying all students:" << endl;
	cout << "========================" << endl;
	classRoster.printAll();
	cout << "\n" << endl;

	// Test 2
	cout << "==========================" << endl;
	cout << "Displaying invalid emails:" << endl;
	cout << "==========================" << endl;
	classRoster.printInvalidEmails();
	cout << "\n" << endl;

	// Test 3
	cout << "====================================================================================================================================" << endl;
	cout << "loop through classRosterArray and print out the average number of days to complete all 3 courses for each student in the classRoster" << endl;
	cout << "====================================================================================================================================" << endl;
	for (int i = 0; i < classRoster.getRosterSize(); ++i) {
		// gets the student ID of the student at index i from the class roster
		string currentStudentID = classRoster.getStudentAtIndex(i)->getStudentID();

		// prints out the average number of days in the course for the student with the inputted student ID taken from above
		classRoster.printAverageDaysInCourse(currentStudentID);
	}
	cout << "\n" << endl;

	// Test 4
	cout << "===================================================" << endl;
	cout << "classRoster.printByDegreeProgram(SOFTWARE) returns:" << endl;
	cout << "===================================================" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "\n" << endl;

	// Test 5
	cout << "============================================================" << endl;
	cout << "classRoster.remove(\"A3\") and classRoster.printAll() returns:" << endl;
	cout << "============================================================" << endl;
	classRoster.remove("A3");
	classRoster.printAll();
	cout << "\n" << endl;

	// Test 5
	cout << "========================================================================================" << endl;
	cout << "Executing classRoster.remove(\"A3\") after the student has already been removed returns:" << endl;
	cout << "========================================================================================" << endl;
	classRoster.remove("A3");
	cout << "\n" << endl;

	cout << "DONE." << endl;

	return 0;
}