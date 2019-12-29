#include "softwareStudent.h"

Degree SoftwareStudent::getDegreeProgram() {
	return degreeProgram;
}

void SoftwareStudent::print() {
	std::cout << this->studentID << "\t";
	std::cout << "First Name: " << this->firstName << "\t";
	std::cout << "Last Name: " << this->lastName << " \t";
	std::cout << "Age: " << this->age << " \t";
	std::cout << "Days in course: {" << this->daysToCompleteCourse[0] << ", " << this->daysToCompleteCourse[1] << ", " << this->daysToCompleteCourse[2] << "} \t";
	std::cout << "Degree Program: Software";
	std::cout << std::endl;
}

SoftwareStudent::SoftwareStudent(std::string idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days, Degree degreeProg)
	: Student(idNumber, fName, lName, eAddress, ageValue, days) {
	this->degreeProgram = degreeProg;
}

SoftwareStudent::~SoftwareStudent() {

}