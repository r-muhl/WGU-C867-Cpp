#pragma once
#include "degree.h"
#include <iostream>

using namespace std;


// D.1. create class "Student"
class Student {
public:

	// D.2.a. Accessor ("getter") functions
	std::string GetStudentID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmailAddress();
	int GetStudentAge();
	int* GetDaysInCourse();

	// D.2.b. Mutator ("setter") functions
	void SetStudentID(std::string setStudentID);
	void SetFirstName(std::string setFirstName);
	void SetLastName(std::string setLastName);
	void SetEmailAddress(std::string setEmailAddress);
	void SetStudentAge(int setStudentAge);
	void SetDaysInCourse(int setDaysInCourse[]);
	void SetDegreeType(Degree setDegreeType);
	// D.2.c. Constructor using all inout parameters
	Student(string setStudentID, string setFirstName, string setLastName, string setEmailAddress, int setStudentAge, int setDaysInCourse[3]);

	// D.2.d. virtual print 
	virtual void Print() = 0;

	// D.2.e Destructor
	~Student();

	// D.2.f. virtual getDegreeProgram()
	virtual Degree GetDegreeProgram() = 0;

	// D.1 variables for base class
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int studentAge;
	int daysInCourse[3];

};