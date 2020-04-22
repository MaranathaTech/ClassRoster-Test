/*
 * roster.h
 *
 *  Created on: Apr 20, 2020
 *      Author: ernielail
 */
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

#ifndef ROSTER_H_
#define ROSTER_H_


class Roster {
public:

	int classRosterArrayPopulation;
	Student *classRosterArray[5];

	Roster();
	~Roster();

	//Functions used to mutate the class roster array:
	void Add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	void Remove(string studentId);

	//Print functions to output class roster array data:
	void PrintAll() const;
	void PrintAverageDaysInCourse(string studentId) const;
	void PrintInvalidEmails() const;
	void PrintByDegreeProgram(DegreeProgram degree) const;

};

#endif /* ROSTER_H_ */
