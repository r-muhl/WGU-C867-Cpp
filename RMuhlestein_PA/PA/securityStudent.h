#pragma once
#include "student.h"

class SecurityStudent : public Student {

public:
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[3], Degree degreeType);
	~SecurityStudent();
	Degree GetDegreeProgram();
	void Print();

private:
	Degree degreeType = SECURITY;

};