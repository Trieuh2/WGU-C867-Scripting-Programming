#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

int main() {
	const int rosterSize = 5;

	/*
	// studentData Table intialization	
	string studentID[rosterSize];
	string firstName[rosterSize];
	string lastName[rosterSize];
	string email[rosterSize];
	int age[rosterSize];
	int days[rosterSize][3];
	DegreeProgram dp[rosterSize];

	// creating studentData table
	// studentID declaration 
	studentID[0] = "A1";
	studentID[1] = "A2";
	studentID[2] = "A3";
	studentID[3] = "A4";
	studentID[4] = "A5";
		
	// firstName declaration
	firstName[0] = "John";
	firstName[1] = "Suzan";
	firstName[2] = "Jack";
	firstName[3] = "Erin";
	firstName[4] = "Henry";

	// lastName declaration
	lastName[0] = "Smith";
	lastName[1] = "Erickson";
	lastName[2] = "Napoli";
	lastName[3] = "Black";
	lastName[4] = "Trieu";

	// email declaration
	email[0] = "John1989@gm ail.com";
	email[1] = "Erickson_1990@gmailcom";
	email[2] = "The_lawyer99yahoo.com";
	email[3] = "Erin.black@comcast.net";
	email[4] = "htrieu3@my.wgu.edu";

	// age declaration
	age[0] = 20;
	age[1] = 19;
	age[2] = 19;
	age[3] = 22;
	age[4] = 21;

	// student A1 days declaration
	days[0][0] = 30;
	days[0][1] = 35;
	days[0][2] = 40;

	// student A2 days declaration
	days[1][0] = 50;
	days[1][1] = 30;
	days[1][2] = 40;

	// student A3 days declaration
	days[2][0] = 20;
	days[2][1] = 40;
	days[2][2] = 33;

	// student A4 days declaration
	days[3][0] = 50;
	days[3][1] = 58;
	days[3][2] = 40;

	// student A5 days declaration
	days[4][0] = 10;
	days[4][1] = 20;
	days[4][2] = 30;

	// dp declaration
	dp[0] = SECURITY;
	dp[1] = NETWORK;
	dp[2] = SOFTWARE;
	dp[3] = SECURITY;
	dp[4] = SOFTWARE;
	*/

	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE" }

	// creating students and adding them to the roster
	roster classRoster = new roster();

	/*
	for (int i = 0; i < rosterSize; ++i) {
		classRoster.add(studentID[i],
			firstName[i],
			lastName[i],
			email[i],
			age[i],
			days[i][0],
			days[i][1],
			days[i][2],
			dp[i]);
	}
	*/

	// Prints out general information about the course, project, and author
	cout << "C867-Scripting & Programming: Applications\n";
	cout << "Language: C++\n";
	cout << "Student ID: 001306217\n";
	cout << "Name: Henry Trieu\n" << endl;

	cout << "WIP" << endl;
	// Test 1
	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;

	// Test 2
	cout << "Displaying invalid emails:" << endl;
	classRoster.printInvalidEmails();
	cout << "\n\n" << endl;

	// Test 3
	cout << "======================================================== \n";
	cout << "loop through classRosterArray and print out the average number of days to complete all 3 courses for each student in the classRoster \n";
	cout << "======================================================== \n";
	for (int i = 0; i < rosterSize; ++i) {
		classRoster.printAverageDaysInCourse(studentID[i]);
	}
	cout << "\n\n" << endl;

	// Test 4
	cout << "======================================================== \n";
	cout << "classRoster.printByDegreeProgram(SOFTWARE) returns: \n";
	cout << "======================================================== \n";
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "\n\n" << endl;

	// Test 5
	cout << "======================================================== \n";
	cout << "classRoster.remove(\"A3\")	and classRoster.printAll() returns: \n";
	cout << "======================================================== \n";
	classRoster.remove("A3");
	classRoster.printAll();
	cout << "\n\n" << endl;

	// Test 5
	cout << "======================================================== \n";
	cout << "Executing classRoster.remove(\"A3\") after the student has already been removed returns: \n";
	cout << "========================================================\n";
	cout << "\n\n" << endl;

	return 0;
}