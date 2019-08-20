#include "securityStudent.h"
#include "student.h"

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int *daysInCourse, Degree degreeType)
	:Student(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse)
{
	this->SetDegreeType(degreeType);
}

SecurityStudent::~SecurityStudent()
{
}
Degree SecurityStudent::GetDegreeProgram() {
	return SECURITY;

}

void SecurityStudent::Print() {
	Student::Print();
	cout << "\tDegree Program: SECURITY\n";
}