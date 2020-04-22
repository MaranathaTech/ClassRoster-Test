/*
 * Student.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: ernielail
 */

#include "student.h"
#include <iostream>
using namespace std;


Student::Student(string id, string fName, string lName, string email, int age, int numDays1, int numDays2, int numDays3, DegreeProgram degree){

	this->studentId = id;
	this->firstName = fName;
	this->lastName = lName;
	this->email = email;
	this->age = age;
	this->degree = degree;
	this->SetNumberOfDays(numDays1, 0);
	this->SetNumberOfDays(numDays2, 1);
	this->SetNumberOfDays(numDays3, 2);

	return;
}


//print all student data
void Student::Print() const {
	cout << this->GetID() ;
	cout << " [tab] First Name: " << this->GetFirstName();
	cout << " [tab] Last Name: " << this->GetLastName();
	cout << " [tab] Age: " << this->GetAge();
	cout << " [tab]daysInCourse: {" << this->GetNumberOfDays(0) << ", " << this->GetNumberOfDays(1) << ", " << this->GetNumberOfDays(2) << "}";
	cout << " Degree Program: " << this->GetDegreeString() << endl;

   return;
}


void Student::SetID(string id){
	this->studentId = id;
	return;
}


string Student::GetID() const {
	return this->studentId;
}


void Student::SetFirstName(string fName){
	this->firstName = fName;
	return;
}


string Student::GetFirstName() const {
	return this->firstName;
}


void Student::SetLastName(string lName){
	this->lastName = lName;
	return;
}


string Student::GetLastName() const {
	return this->lastName;
}


void Student::SetEmail(string email){
	this->email = email;
	return;
}


string Student::GetEmail() const {
	return this->email;
}


//function to check the existing email variable for validity
bool Student::CheckEmail() const {

	if(this->email.find(" ") != string::npos){

		return false;

	}
	else if(this->email.find("@") == string::npos || this->email.find(".") == string::npos){

		return false;

	}

	return true;

}


void Student::SetAge(int age){
	this->age = age;
	return;
}


int Student::GetAge() const {
	return this->age;
}


void Student::SetNumberOfDays(int numDays, int location){
	this->numberOfDays[location] = numDays;
	return;
}


int Student::GetNumberOfDays(int location) const {
	return this->numberOfDays[location];
}


void Student::SetDegree(DegreeProgram degree){
	this->degree = degree;
	return;
}


DegreeProgram Student::GetDegree() const {
	return this->degree;
}


string Student::GetDegreeString() const {

	DegreeProgram degree = this->GetDegree();

	switch(degree){
			case NETWORK:
				return "Network";
				break;
			case SOFTWARE:
				return "Software";
				break;
			case SECURITY:
				return "Security";
				break;
			default:
				return "Unknown";
				break;
		}

}

