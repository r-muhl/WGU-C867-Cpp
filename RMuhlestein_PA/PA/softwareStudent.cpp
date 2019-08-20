#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int *daysInCourse, Degree degreeType)
	:Student(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse)
{
	this->SetDegreeType(degreeType);
}

SoftwareStudent::~SoftwareStudent()
{
}

Degree SoftwareStudent::GetDegreeProgram() {
	return SOFTWARE;
}

void SoftwareStudent::Print() {
	Student::Print();
	cout << "\tDegree Program: SOFTWARE\n";
}