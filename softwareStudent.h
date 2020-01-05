#ifndef SOFTWARE_STUDENT
#define SOFTWARE_STUDENT

#include "student.h"

class SoftwareStudent : public Student {
public:
	Degree getDegreeProgram();
	void print();

	SoftwareStudent(std::string idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days,
		Degree degreeProgram);
	~SoftwareStudent();

private:
	Degree degreeProgram;
};

#endif