#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
using namespace std;


class Student {
public:

//variable declarations
	string studentID;
	string fName;
	string lName;
	string email;
	int age;
	int DaysInCourse[3];
	DegreeProgram degreeprogram;
	
	Student(); //Empty constructor
	Student(string studentID, string fName, string lName, string email, int age, int DaysinCourse[3], DegreeProgram degreeprogram); //Constructs Student Object

//Accessors
	string GetStudentID();
	string GetFName();
	string GetLName();
	string GetEmail();
	int GetAge();
	int * GetDaysInCourse();
	DegreeProgram GetDegree();

//Mutators
	void SetStudentID(string studentID);
	void SetFName(string fName);
	void SetLName(string lName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDaysInCourse(int daysInCourse[]);
	void SetDegree(enum DegreeProgram);

//prints each student
	virtual void print();

};

#endif
