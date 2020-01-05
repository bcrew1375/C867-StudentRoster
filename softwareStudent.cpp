#include "softwareStudent.h"

Degree SoftwareStudent::getDegreeProgram() {
	return degreeProgram;
}

void SoftwareStudent::print() {
	int* days;

	days = this->getDaysToCompleteCourse();

	std::cout << this->getStudentID() << "\t";
	std::cout << "First Name: " << this->getFirstName() << "\t";
	std::cout << "Last Name: " << this->getLastName() << " \t";
	std::cout << "Age: " << this->getAge() << " \t";
	std::cout << "Days in course: {" << days[0] << ", " << days[1] << ", " << days[2] << "} \t";
	std::cout << "Degree Program: Software";
	std::cout << std::endl;
}

SoftwareStudent::SoftwareStudent(std::string idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days, Degree degreeProg)
	: Student(idNumber, fName, lName, eAddress, ageValue, days) {
	this->degreeProgram = degreeProg;
}

SoftwareStudent::~SoftwareStudent() {

}