#ifndef NETWORK_STUDENT
#define NETWORK_STUDENT

#include "student.h"

class NetworkStudent : public Student {
public:
	Degree getDegreeProgram();
	void print();
	
	NetworkStudent(std::string idNumber, std::string fName, std::string lName, std::string eAddress, int ageValue, int* days,
		Degree degreeProgram);
	~NetworkStudent();

private:
	Degree degreeProgram;
};

#endif