#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main() {

	cout << "C867 - Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001398566" << endl;
	cout << "Name: Hans Fritz" << endl << endl;

	Roster classRoster;


	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Hans,Fritz,hfritz7@my.wgu.edu,25,53,30,55,SOFTWARE" };

	classRoster.parse(studentData);

	cout << "Displaying all students:" << endl;
	classRoster.printAll();

	cout << "Displaying invalid emails:" << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterarray[i]->GetStudentID());
	} 
	cout << endl;

	cout << "Showing students in degree program: SOFTWARE" << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing A3:" << endl;
	classRoster.remove("A3");
	cout << endl;

	classRoster.printAll();

	cout << "Removing A3 again" << endl << endl;
	classRoster.remove("A3");
	cout << "DONE." << endl;
}