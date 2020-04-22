//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;


int main() {

	Roster classRoster = Roster();

	//add students
	classRoster.Add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
	classRoster.Add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
	classRoster.Add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
	classRoster.Add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
	classRoster.Add("A5", "Ernest", "Lail", "ern@gmail.com", 39, 1, 2, 3, SOFTWARE);

	//print all students
	classRoster.PrintAll();

	//print all invalid emails
	classRoster.PrintInvalidEmails();

	//loop through classRosterArray and print average days in course for each student:
	for(int i = 0; i < classRoster.classRosterArrayPopulation; i++) {

		string studentId = classRoster.classRosterArray[i]->GetID();
		classRoster.PrintAverageDaysInCourse(studentId);

	}

	//print all students for specified degree program
	classRoster.PrintByDegreeProgram(SOFTWARE);

	//demonstrate Student Removals
	classRoster.Remove("A3");
	classRoster.PrintAll();
	classRoster.Remove("A3");

	return 0;
}
