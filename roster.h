#ifndef ROSTER
#define ROSTER

#include "student.h"

class Roster {
public:
	Student** getClassRosterArray();

	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);

	Roster();
	~Roster();

private:
	// Store pointers to each student object in the roster.
	Student* classRosterArray[5];

	// Track the next unused slot in the roster array.
	int nextEmptySlot;
};

#endif