/*
 * Student.h
 *
 *  Created on: Apr 20, 2020
 *      Author: ernielail
 */
#include <string>
#include "degree.h"
using namespace std;

#ifndef Student_H_
#define Student_H_


class Student {

	public:
		Student(string id, string fName, string lName, string email, int age, int numDays1, int numDays2, int numDays3, DegreeProgram degree);
	
		void Print() const;
	
		void SetID(string id);
		string GetID() const;
	
		void SetFirstName(string fName);
		string GetFirstName() const;
	
		void SetLastName(string lName);
		string GetLastName() const;
	
		void SetEmail(string email);
		string GetEmail() const;
		bool CheckEmail() const;
	
		void SetAge(int age);
		int GetAge() const;
	
		void SetNumberOfDays(int numDays, int location);
		int GetNumberOfDays(int location) const;
	
		void SetDegree(DegreeProgram degree);
		DegreeProgram GetDegree() const;
		string GetDegreeString() const;
	
	private:
		string studentId;
		string firstName;
		string lastName;
		string email;
		int age;
		DegreeProgram degree;
		int numberOfDays[3];
};

#endif /* Student_H_ */
