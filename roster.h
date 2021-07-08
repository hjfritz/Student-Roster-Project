#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <string>
using namespace std;


class Roster {
public:
	
	Roster(); // constuctor
	~Roster(); // deconstructor

	//Function Declarations
	void add(string studentID, string fName, string lName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram, int i);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void parse(const string row[]);

	//Declares Class Roster Array and other Roster variables
	Student *classRosterarray[5];
	int numStudents = 5;
	int studentNum = -1;
};

#endif // 