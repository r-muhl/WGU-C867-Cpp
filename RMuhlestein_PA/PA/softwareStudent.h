#pragma once
#include "student.h"

class SoftwareStudent : public Student {

public:
	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[3], Degree degreeType);
	~SoftwareStudent();
	Degree GetDegreeProgram();
	void Print();

private:
	Degree degreeType = SOFTWARE;

};