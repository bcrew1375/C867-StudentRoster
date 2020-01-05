#ifndef STUDENT
#define STUDENT

#include <iostream>

#include "Degree.h"

class Student {
public:
	// Getter and setter pairs
	
	// Handles student ID numbers.
	std::string getStudentID();
	void setStudentID(std::string idNumber);

	// Handles student age.
	int getAge();
	void setAge(int ageValue);

	// Handles an array of three integers representing the average days to complete a course.
	int* getDaysToCompleteCourse();
	void setDaysToCompleteCourse(int* days);

	// Handles student first name.
	std::string getFirstName();
	void setFirstName(std::string fName);

	// Handles student last name.
	std::string getLastName();
	void setLastName(std::string lName);

	// Handles student email address.
	std::string getEmailAddress();
	void setEmailAddress(std::string eAddress);

	// Handles student degree program. To be defined in subclass.
	virtual Degree getDegreeProgram() = 0;
	// Prints student data. To be defined in subclass.
	virtual void print() = 0;

	// Constructor
	Student(std::string idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days);
	// Destructor
	~Student();

private:
	// Variables internal to Student class. To be externally accessed through getters and setters.
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;

	int age;
	int* daysToCompleteCourse;
};

#endif