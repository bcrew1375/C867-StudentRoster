#ifndef STUDENT
#define STUDENT

#include <iostream>
#include "Degree.h"

class Student {
public:
	// Getter and setter pairs
	std::string getStudentId();
	void setStudentId(std::string idNumber);

	int getAge();
	void setAge(int ageValue);

	int* getDaysToCompleteCourse();
	void setDaysToCompleteCourse(int* days);

	std::string getFirstName();
	void setFirstName(std::string fName);

	std::string getLastName();
	void setLastName(std::string lName);

	std::string getEmailAddress();
	void setEmailAddress(std::string eAddress);

	virtual Degree getDegreeProgram() = 0;
	void setDegreeProgram(Degree type);

	// Constructor
	Student(int idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days, Degree type);
	// Destructor
	~Student();
	// Print student data
	virtual void print();

private:
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;

	int age;
	int* daysToCompleteCourse = new int[3];
};

#endif