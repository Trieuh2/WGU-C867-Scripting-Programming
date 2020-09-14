#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <iostream>
using namespace std;

class student {
	static const int numClasses = 3;

	public:	
		// Parameterized constructor
		student(string id,
			string fn,
			string ln,
			string ea,
			int age,
			int daysLeft[3],
			DegreeProgram dp);

		// Customized print output
		void print();

		// Accessor methods
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int* getDaysLeftEachCourse();
		DegreeProgram getDegreeProgram();

		// Mutator methods
		void setStudentID(string id);
		void setFirstName(string fn);
		void setLastName(string ln);
		void setEmailAddress(string ea);
		void setAge(int a);
		void setDaysLeftEachCourse(int daysLeft[3]);
		void setDegreeProgram(DegreeProgram dp);

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