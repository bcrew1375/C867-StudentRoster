#include "securityStudent.h"

Degree SecurityStudent::getDegreeProgram() {
	return degreeProgram;
}

void SecurityStudent::print() {
	std::cout << this->studentID << "\t";
	std::cout << "First Name: " << this->firstName << "\t";
	std::cout << "Last Name: " << this->lastName << " \t";
	std::cout << "Age: " << this->age << " \t";
	std::cout << "Days in course: {" << this->daysToCompleteCourse[0] << ", " << this->daysToCompleteCourse[1] << ", " << this->daysToCompleteCourse[2] << "} \t";
	std::cout << "Degree Program: Security";
	std::cout << std::endl;
}

SecurityStudent::SecurityStudent(std::string idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days, Degree degreeProg)
	: Student(idNumber, fName, lName, eAddress, ageValue, days) {
	this->degreeProgram = degreeProg;
}

SecurityStudent::~SecurityStudent() {

}