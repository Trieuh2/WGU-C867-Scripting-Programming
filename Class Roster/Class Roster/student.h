#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <iostream>
using namespace std;



class student {
	static const int numClasses = 3;

	public:
		// Accessor methods
		string GetStudentID();
		string GetFirstName();
		string GetLastName();
		string GetEmailAddress();
		int GetAge();
		int* GetDaysLeftEachCourse();
		DegreeProgram GetDegreeProgram();

		// Mutator methods
		void SetStudentID(string id);
		void SetFirstName(string fn);
		void SetLastName(string ln);
		void SetEmailAddress(string ea);
		void SetAge(int a);
		void SetDaysLeftEachCourse(int daysLeft[3]);
		void SetDegreeProgram(DegreeProgram dp);

		// Constructor
		student(string id,
			string fn,
			string ln,
			string ea,
			int age,
			int daysLeft[3],
			DegreeProgram dp);

		// Customized print output
		void print();

	// internal data members for student class
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysLeftEachCourse[3];
		DegreeProgram program;
};

#endif