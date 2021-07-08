#include <iostream>
#include <sstream>
#include <regex>
#include <string>
#include "roster.h"

using namespace std;

//constructor
Roster::Roster() {
	this->numStudents = 5;
	this->studentNum = 0;
}

//destructor
Roster::~Roster(){
	for (int i = 0; i <= numStudents; i++) {
		delete this->classRosterarray[i];
	}
	delete[] *classRosterarray;
}

//add function
void Roster::add(string studentID, string fName, string lName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram, int i) {

	int DaysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterarray[i] = new Student(studentID, fName, lName, email, age, DaysInCourse, degreeprogram);

}

//remove function
void Roster::remove(string studentID) {

	for (int i = 0; i < 5; ++i) {
		if (classRosterarray[i]) {
			if (classRosterarray[i]->GetStudentID() == studentID) {
				classRosterarray[i] = 0;
			}
		}
		else if (classRosterarray[i] == 0) {
			cout << "The student with the ID: " << studentID << " was not found." << endl;
		}
	}
}

//PrintAll function
void Roster::printAll() {

	for (int i = 0; i < numStudents; ++i) {
		if (this->classRosterarray[i] == nullptr) {
			continue;
		}
		else {
			(this->classRosterarray[i])->print();
		}
	}
	cout << endl;
}

// Prints average days in course 
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numStudents; ++i) {
		if (this->classRosterarray[i]->GetStudentID() == studentID) {
			int * Days = (classRosterarray[i])->GetDaysInCourse();
			cout << "Student ID: " << studentID << ", average days in course is: " << ((Days[0] + Days[1] + Days[2])/3) << endl;
		}
	}
}

//Prints Students by degree
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	for (int i = 0; i < numStudents; ++i) {
		if (this->classRosterarray[i]->GetDegree() == degreeprogram) {
			this->classRosterarray[i]->print();
		}
	}
}

//Check if email is valid
bool is_email_valid(const std::string& email) {
	// define a regular expression
	const std::regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// try to match the string with the regular expression
	return std::regex_match(email, pattern);
};

//Prints the invalid emails
void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		string emailToCheck = this->classRosterarray[i]->GetEmail();
		bool valid = is_email_valid(emailToCheck);
		if (!valid) {
			cout << emailToCheck << " - is invalid." << endl;
		}
	}
}

//Parses input string, then adds students
void Roster::parse(const string row[]) {
	
	for (int i = 0; i < numStudents; i++) {
		string toParse = row[i];
		vector<string> result;
		stringstream s_stream(toParse);
		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
			}
		string studentID = result.at(0);
		string fName = result.at(1);
		string lName = result.at(2);
		string email = result.at(3);
		int age = stoi(result.at(4));
		int daysInCourse1 = stoi(result.at(5));
		int daysInCourse2 = stoi(result.at(6));
		int daysInCourse3 = stoi(result.at(7));
		
		DegreeProgram degreeprogram;

		if (result.at(8) == "SECURITY") {
			degreeprogram = SECURITY;
		}

		else if (result.at(8) == "NETWORK") {
			degreeprogram = NETWORK;
		}

		else if (result.at(8) == "SOFTWARE") {
			degreeprogram = SOFTWARE;
		}
	
	add(studentID, fName, lName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram, i);
	}

}