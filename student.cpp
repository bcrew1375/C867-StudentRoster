#include "student.h"

std::string Student::getStudentID() {
	return this->studentID;
}

void Student::setStudentID(std::string idNumber) {
	this->studentID = idNumber;
}

std::string Student::getFirstName() {
	return this->firstName;
}

void Student::setFirstName(std::string fName) {
	this->firstName = fName;
}

std::string Student::getLastName() {
	return this->lastName;
}

void Student::setLastName(std::string lName) {
	this->lastName = lName;
}

std::string Student::getEmailAddress() {
	return this->emailAddress;
}

void Student::setEmailAddress(std::string eAddress) {
	this->emailAddress = eAddress;
}

int Student::getAge() {
	return this->age;
}

void Student::setAge(int ageValue) {
	this->age = ageValue;
}

int* Student::getDaysToCompleteCourse() {
	return this->daysToCompleteCourse;
}

void Student::setDaysToCompleteCourse(int* days) {
	for (int i = 0; i < 3; i++)
		this->daysToCompleteCourse[i] = days[i];
}

Student::Student(std::string idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days) {
	this->studentID = idNumber;
	this->firstName = fName;
	this->lastName = lName;
	this->emailAddress = eAddress;
	this->age = ageValue;
	this->daysToCompleteCourse = days;
}

Student::~Student() {
	// Delete the array created for days to complete course.
	delete this->daysToCompleteCourse;
}