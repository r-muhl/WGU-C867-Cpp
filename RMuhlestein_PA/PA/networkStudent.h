#pragma once
#include "student.h"

class NetworkStudent : public Student {

public:
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[3], Degree degreeType);
	~NetworkStudent();
	Degree GetDegreeProgram();
	void Print();

private:
	Degree degreeType = NETWORK;

};