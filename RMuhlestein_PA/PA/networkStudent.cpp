#include "networkStudent.h"

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int *daysInCourse, Degree degreeType)
	:Student(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse)
{
	this->SetDegreeType(degreeType);
}

NetworkStudent::~NetworkStudent()
{
}

Degree NetworkStudent::GetDegreeProgram() {
	return NETWORK;
}

void NetworkStudent::Print() {
	Student::Print();
	cout << "\tDegree Program: NETWORK\n";
	}