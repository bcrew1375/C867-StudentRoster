#ifndef NETWORK_STUDENT
#define NETWORK_STUDENT

#include "student.h"

class NetworkStudent : Student {
public:
	Degree getDegreeProgram();
	void setDegreeProgram(Degree degreeProgram);

private:
	Degree degreeType;
};

#endif