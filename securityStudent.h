#ifndef SECURITY_STUDENT
#define SECURITY_STUDENT

#include "student.h"

class SecurityStudent : public Student {
public:
	Degree getDegreeProgram();
	void print();

	SecurityStudent(std::string idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days,
		Degree degreeProgram);
	~SecurityStudent();

private:
	Degree degreeProgram;
};

#endif