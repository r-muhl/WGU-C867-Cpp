#pragma once
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"


class Roster {

public:
	Roster();
	void ParseThenAdd(std::string row);
	void Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program);
	void Remove(std::string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(std::string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(Degree degreeType);
	~Roster();


//private:

	// E.1 create an array of pointers, classRosterArray, to hold the data provided in the studentData table.
	Student* classRosterArray[5] = {nullptr,nullptr,nullptr,nullptr,nullptr};
			int lastIndex;
}; // end of class Roster


