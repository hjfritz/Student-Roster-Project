#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//Empty Constructor
Student::Student() {
	this->studentID = "";
	this->fName = "";
	this->lName = "";
	this->email = "";
	this->age = 0;

	for (int i = 0; i < 3; i++) {
		this->DaysInCourse[i] = 0;
	}
	this->degreeprogram = SECURITY;
}

//Constructs Student Object
Student::Student(string studentID, string fName, string lName, string email, int age, int DaysInCourse[3], DegreeProgram degreeprogram) {
	SetStudentID(studentID);
	SetFName(fName);
	SetLName(lName);
	SetEmail(email);
	SetAge(age);
	SetDaysInCourse(DaysInCourse);
	SetDegree(degreeprogram);
}
//Accessors
	string Student::GetStudentID() { 
		return studentID;
	}

	string Student::GetFName() {
		return fName;
	}

	string Student::GetLName() {
		return lName;
	}

	string Student::GetEmail() {
		return email;
	}

	int Student::GetAge() {
		return age;
	}

	int * Student::GetDaysInCourse() {
		return DaysInCourse;
	}

	DegreeProgram Student::GetDegree() {
		return degreeprogram;
	}

//Mutators
	void Student::SetStudentID(string studentID) {
		this->studentID = studentID;
	}

	void Student::SetFName(string fName) {
		this->fName = fName;
	}

	void Student::SetLName(string lName) {
		this->lName = lName;
	}

	void Student::SetEmail(string email) {
		this->email = email;
	}

	void Student::SetAge(int age) {
		this->age = age;
	}

	void Student::SetDaysInCourse(int DaysInCourse[]) {
		for (int i = 0; i < 3; i++) {
			this->DaysInCourse[i] = DaysInCourse[i];
		}
	}

	void Student::SetDegree(DegreeProgram degreeprogram) {
		this->degreeprogram = degreeprogram;
	}


//Prints out single student
void Student::print() {
	string printdegree;
	if (degreeprogram == 0) {
		printdegree = "SECURITY";
	}
	else if (degreeprogram == 1) {
		printdegree = "NETWORK";
	}
	else {
		printdegree = "SOFTWARE";
	}
	cout << studentID << "\t" << fName << "\t" << lName << "\t" << age << "\t{" << DaysInCourse[0] << "," << DaysInCourse[1] << "," << DaysInCourse[2] << "}\t" << printdegree << endl;
};