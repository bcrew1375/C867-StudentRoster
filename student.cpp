#include "student.h"

std::string Student::getStudentId() {
	return studentId;
}

void Student::setStudentId(std::string idNumber) {
	studentId = idNumber;
}

std::string Student::getFirstName() {
	return firstName;
}

void Student::setFirstName(std::string fName) {
	firstName = fName;
}

std::string Student::getLastName() {
	return lastName;
}

void Student::setLastName(std::string lName) {
	lastName = lName;
}

std::string Student::getEmailAddress() {
	return emailAddress;
}

void Student::setEmailAddress(std::string eAddress) {
	emailAddress = eAddress;
}

int Student::getAge() {
	return age;
}

void Student::setAge(int ageValue) {
	age = ageValue;
}

int* Student::getDaysToCompleteCourse() {
	return daysToCompleteCourse;
}

void Student::setDaysToCompleteCourse(int* days) {
	for (int i = 0; i < 3; i++)
		daysToCompleteCourse[i] = days[i];
}

Student::Student(int idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days, Degree type) {
	studentId = idNumber;
	firstName = fName;
	lastName = lName;
	emailAddress = eAddress;
	age = ageValue;
	daysToCompleteCourse = days;
}

Student::~Student() {
	delete &studentId;
	delete &firstName;
	delete &lastName;
	delete &emailAddress;
	delete &age;
	delete &daysToCompleteCourse;
}

void Student::print() {
	std::cout << "";
}