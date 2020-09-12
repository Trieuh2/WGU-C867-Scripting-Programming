#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

int main() {
	// studentData Table intialization
	string studentID[5];
	string firstName[5];
	string lastName[5];
	string email[5];
	int age[5];
	int days[5][3];
	DegreeProgram dp[5];

	// studentData Table declaration
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

	// creating students and adding them to the roster
	roster classRoster;

	for (int i = 0; i < 5; ++i) {
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

	// TODO: remove test case
	classRoster.printAll();
	classRoster.remove("ZZZZ");

	return 0;
}