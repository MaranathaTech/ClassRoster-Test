/*
 * roster.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: ernielail
 */

#include "roster.h"
#include "student.h"
#include <string>
#include <iostream>
using namespace std;


Roster::Roster() {
	//set array length
	this->classRosterArrayPopulation = 0;
	return;
}


Roster::~Roster() {

	for(int i=0; i < this->classRosterArrayPopulation; i++){
			delete this->classRosterArray[i];
	}

	this->classRosterArrayPopulation = 0;

	return;
}


//function to add new students
void Roster::Add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree){
	//create student
	Student *student = new Student(studentId, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);

	//add student pointer to array
	this->classRosterArray[this->classRosterArrayPopulation] = student;

	//iterate counter up
	this->classRosterArrayPopulation++;

	return;
}


//function to remove students
void Roster::Remove(string studentId){

	bool found = false;

	//loop though class roster array
	for(int i = 0; i < this->classRosterArrayPopulation - 1; i++) {

		//check student ID for match
		if(this->classRosterArray[i]->GetID() == studentId){

			found = true;

			//loop remaining items and shift array elements down
			for(int j=i; j < (this->classRosterArrayPopulation); j++)
			{
				this->classRosterArray[j]=this->classRosterArray[j + 1];
			}

			//null the last item
			this->classRosterArray[this->classRosterArrayPopulation - 1] = nullptr;

			//iterate counter down
			this->classRosterArrayPopulation--;
		}
	}

	if (found == false){
		cout << "A student with this ID was not found." << endl;
	}

	return;
}


//print functions to output class roster array data:
void Roster::PrintAll() const{
	//loop though class roster array
	for(int i = 0; i < this->classRosterArrayPopulation; i++) {
		this->classRosterArray[i]->Print();
	}

	return;
}


//print function for average days in course
void Roster::PrintAverageDaysInCourse(string studentId) const{
	bool found = false;

	//loop though class roster array
	for(int i = 0; i < this->classRosterArrayPopulation; i++) {

		//check student ID for match
		if(this->classRosterArray[i]->GetID() == studentId){
			found = true;
			int averageDays = (this->classRosterArray[i]->GetNumberOfDays(0) + this->classRosterArray[i]->GetNumberOfDays(1) + this->classRosterArray[i]->GetNumberOfDays(2)) / 3;
			cout << studentId << "'s average days in course: " << averageDays << endl;
		}
	}

	if (found == false){
		cout << "A student with this ID was not found." << endl;
	}

	return;
}


//print function to find invalid sttudent emails
void Roster::PrintInvalidEmails() const{

	bool found = false;

	//loop though class roster array
	for(int i = 0; i < this->classRosterArrayPopulation; i++) {
		//check student Degree for match
		if(this->classRosterArray[i]->CheckEmail() == false){
			found = true;
			cout << this->classRosterArray[i]->GetID() << " has an invalid email address." << endl;
		}

	}

	if (found == false){
		cout << "No invalid emails found." << endl;
	}

	return;

}


//print function to print all users for specified degree
void Roster::PrintByDegreeProgram(DegreeProgram degree) const{

	bool found = false;

	//loop though class roster array
	for(int i = 0; i < this->classRosterArrayPopulation; i++) {

		//check student Degree for match
		if(this->classRosterArray[i]->GetDegree() == degree){

			found = true;

			string degreeString = this->classRosterArray[i]->GetDegreeString();

			cout << this->classRosterArray[i]->GetID() << " is currently enrolled in the " << degreeString << " program." << endl;

		}

	}

	if (found == false){
		cout << "No students with this degree were found." << endl;
	}

	return;

}


