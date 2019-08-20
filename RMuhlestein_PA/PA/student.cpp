#include "student.h"
#include <string>

// D.1 create base class Student in student.h and student.cpp
string Student::GetStudentID() {
	return studentID;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

int Student::GetStudentAge() {
	return studentAge;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

void Student::SetStudentID(string newStudentID) {
	studentID = newStudentID;
}

void Student::SetFirstName(string setFirstName) {
	firstName = setFirstName;
}

void Student::SetLastName(string setLastName) {
	lastName = setLastName;
}

void Student::SetEmailAddress(string setEmailAddress) {
	emailAddress = setEmailAddress;
}

void Student::SetStudentAge(int setStudentAge) {
	studentAge = setStudentAge;
}

void Student::SetDaysInCourse(int setDaysInCourse[]) {
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = setDaysInCourse[i];
	} // end for loop
}

void Student::SetDegreeType(Degree setDegreeType) {
	Degree degreeType = setDegreeType;
}

void Student::Print() {
	cout << GetStudentID() << "\tFirst Name: " << GetFirstName()
		<< "\tLast Name: " << GetLastName() << "\tAge: " << GetStudentAge()
		<< "\tDays In Course: { " << daysInCourse[0] << ", " << daysInCourse[1]
		<< ", " << daysInCourse[2] << " }";
}

Student::Student(string setStudentID, string setFirstName, string setLastName, string setEmailAddress, int setStudentAge, int setDaysInCourse[3]) {
	SetStudentID(setStudentID);
	SetFirstName(setFirstName);
	SetLastName(setLastName);
	SetEmailAddress(setEmailAddress);
	SetStudentAge(setStudentAge);
	SetDaysInCourse(setDaysInCourse);
}
Student::~Student() {
}