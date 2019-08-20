#include "roster.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

	Roster::Roster() {
		this->lastIndex = -1;
	}

void Roster::ParseThenAdd(string row) {

	if (lastIndex < 5) {
		lastIndex++;
		Degree degreeType;

		if (row.back() == 'K') {
			degreeType = NETWORK;
		} // end 'K' if statement
		else if (row.back() == 'Y') {
			degreeType = SECURITY;
		} // end 'Y' if statemment
		else if (row.back() == 'E') {
			degreeType = SOFTWARE;
		} // end 'E' if statement

		// studentID
		int rhs = row.find(",");
		string studID = row.substr(0, rhs);

		// firstName
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string firName = row.substr(lhs, rhs - lhs);

		// lastName
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lstName = row.substr(lhs, rhs - lhs);

		//emailAddress
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string emlAddress = row.substr(lhs, rhs - lhs);

		// studentAge
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int studAge = stoi(row.substr(lhs, rhs - lhs));

		// daysInCourse1
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int course1 = stoi(row.substr(lhs, rhs - lhs));

		// daysInCourse2
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int course2 = stoi(row.substr(lhs, rhs - lhs));

		// daysInCourse3
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int course3 = stoi(row.substr(lhs, rhs - lhs));

		Add(studID, firName, lstName, emlAddress, studAge, course1, course2, course3, degreeType);

	} // end if statement
} // end ParseThenAdd


// E.3.a sets the instance variables from part D1 and updates the roster
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {

	int daysInCourse[3];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	//for (int i = 0; i < 5; i++) {
		if (degreeType == NETWORK) {
			classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse, degreeType);
		} // end NETWORK if statement
		else if (degreeType == SECURITY) {
			classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse, degreeType);
		} // end SECURITY if statement
		else if (degreeType == SOFTWARE) {
			classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse, degreeType);
		} // end SOFTWARE if statement
	//} // end for loop
} // end addStudent


// E.3.b removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found
void Roster::Remove(string studentID) {
	bool studentFound = 0;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			studentFound = 1;
		} // end if statement
	} // end for loop
	if (studentFound == 0) {
		cout << "Student with " << studentID << " was not found.\n";
	} // close if statment
} // end removeStudent		

// E.3.c prints a complete tab-separated list of student data using accessor functions 
void Roster::PrintAll() {
	for (int i = 0; i < 5; i++) {
		classRosterArray[i]->Print();
	} // end for loop
} // end PrintAll


// E.3.d correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.		
void Roster::PrintAverageDaysInCourse(string studentID) {
	double theSum = 0.0;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			int * averageDays = classRosterArray[i]->GetDaysInCourse();
			for (int j = 0; j < 3; j++) {
				theSum = theSum + averageDays[j];
			} // end j for loop
			double avgDays = theSum / 3;
			cout << avgDays << endl;
		} // close if statement
	} // end i for loop						
} // end PrintAverageDaysInCourse

	
//E.3.e verifies student email addresses and displays all invalid email addresses to the user
void Roster::PrintInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		bool validEmail = 0;

		Student* student = classRosterArray[i];
		string emailAddress = student->GetEmailAddress();
	
		// find "@" in any position in the string	
		int isPresent = emailAddress.find("@");
		if (isPresent > 0) {
			validEmail = 1;
		}
		// find "." in any position in the string	
		isPresent = emailAddress.find(".");
		if (isPresent > 0) {
			validEmail = 1;
		}
		// find " " in any position in the string
		isPresent = emailAddress.find(" ");
		if (isPresent > 0) {
			validEmail = 0;
		}
		// if valid, email address is printed out
		if (validEmail == 1) {
			cout << emailAddress << endl;
		}
		// if invalid, error message is printed
		if (validEmail == 0) {
			cout << "Invalid Email Address\n";
		}
	} // end for loop			
} // end PrintInvalidEmails

// E.3.f prints out student information for a degree program specified by an enumerated type
void Roster::PrintByDegreeProgram(Degree degreeType) {
	for (int i = 0; i < 5; i++) {                               
		Student* student = classRosterArray[i];
		if (student->GetDegreeProgram() == degreeType) {
			student->Print();
		} // end if statement				
	} // end for loop		
} // end PrintByDegreeProgram

Roster::~Roster() {

}

int main() {

	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Robert,Muhlestein,rmuhles@wgu.edu,26,13,14,23,SOFTWARE" };


	// F.1. Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.
	cout << "C867: Scripting & Programming, C++, 000936977, Robert Muhlestein\n\n";

	// F.2. Create an instance of the Roster class called classRoster.

	Roster* classRoster = new Roster();

	// F.3. Add each student to classRoster

		
	for (int i = 0; i < 5; i++) {
		classRoster->ParseThenAdd(studentData[i]);
	} // end for loop


// F.4 covert the following pseudo code to complete the rest of the main() function:
	
	// PrintAll
	classRoster->PrintAll();

	cout << endl; 
	
	//PrintInvalidEmails
	classRoster->PrintInvalidEmails();

	cout << endl;

// loop through classRosterArray and for each element:
	for (int i = 0; i < 5; i++) {
		classRoster->PrintAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentID());
	}

	cout << endl;

	//PrintByDegreeProgram
	classRoster->PrintByDegreeProgram(SOFTWARE);

	cout << endl; 

	//Removing a student
	classRoster->Remove("A3");

	//Check error message in Remove function
	classRoster->Remove("A3");

	// F.5. call the destructor to release the Roster memory.
	delete classRoster;

	return 0;

} // close int main()

