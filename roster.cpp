#include <string>
#include <sstream>

#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

const std::string studentData[] = {
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Benjamin,Crew,bcrew7@wgu.edu,35,5,10,15,SOFTWARE"
};

Student** Roster::getClassRosterArray() {
	return this->classRosterArray;
}

/***
Roster add method 
***/
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	// Create an array to be fed to the appropriate subclass.
	int* days = new int[3];

	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;

	if (degreeProgram == SECURITY) {
		classRosterArray[nextEmptySlot] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
		nextEmptySlot++;
	}
	else if (degreeProgram == NETWORK) {
		classRosterArray[nextEmptySlot] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
		nextEmptySlot++;
	}
	else if (degreeProgram == SOFTWARE) {
		classRosterArray[nextEmptySlot] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
		nextEmptySlot++;
	}
	// Handle an invalid degree program.
	else {

	}
}

/***
Roster remove method
***/
void Roster::remove(std::string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr)
			if (classRosterArray[i]->getStudentID() == studentID)
			{
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;

				std::cout << "Student with ID: " << studentID << " was removed." << std::endl;

				return;
			}
	}

	std::cout << "Student with ID: " << studentID << " was not found." << std::endl;
}

/***
Roster print all method
***/
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		classRosterArray[i]->print();
	}
}

/***
Roster print days in course method.
***/
void Roster::printAverageDaysInCourse(std::string studentID) {
	int* days = new int[3];

	int average = 0;

	for (int i = 0; i < 5; i++)
		if (classRosterArray[i]->getStudentID() == studentID) {
			days = classRosterArray[i]->getDaysToCompleteCourse();

			average = (days[0] + days[1] + days[2]) / 3;

			std::cout << "Student " << studentID << "'s average days in course: " << average << std::endl;
		}
}

void Roster::printInvalidEmails() {
	std::string emailAddress;

	bool atSignCheck;
	bool periodCheck;
	bool spaceCheck;

	for (int i = 0; i < 5; i++) {
		atSignCheck = false;
		periodCheck = false;
		spaceCheck = false;

		emailAddress = classRosterArray[i]->getEmailAddress();

		for (int j = 0; j < emailAddress.length(); j++) {
			if (emailAddress[j] == '@')
				atSignCheck = true;
			if (emailAddress[j] == '.')
				periodCheck = true;
			if (emailAddress[j] == ' ')
				spaceCheck = true;
		}

		if ((atSignCheck == false) || (periodCheck == false) || (spaceCheck == true))
			std::cout << "Student " << classRosterArray[i]->getStudentID() << ": " << classRosterArray[i]->getFirstName() << " " <<
			classRosterArray[i]->getLastName() << " has an invalid email: " << classRosterArray[i]->getEmailAddress() << std::endl;
	}
}

/***
Roster print by degree program method.
***/
void Roster::printByDegreeProgram(Degree degreeProgram) {
	for (int i = 0; i < 5; i++)
		if (classRosterArray[i] != nullptr)
			if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
				classRosterArray[i]->print();
}

/***
Roster constructor
***/
Roster::Roster() {
	// Build the initial class roster array.

	std::istringstream studentDataStream;

	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string age;
	std::string daysInCourse1, daysInCourse2, daysInCourse3;
	std::string degreeInput;

	Degree degreeProgram;

	// Set the empty slot to the beginning of the class roster array.
	nextEmptySlot = 0;

	for (int i = 0; i < 5; i++) {
		// Read each string from the studentData const into an input string stream.
		studentDataStream.clear();
		studentDataStream.str(studentData[i]);

		// Parse each piece of data into the appropriate variable using a comma delimiter.
		std::getline(studentDataStream, studentID, ',');
		std::getline(studentDataStream, firstName, ',');
		std::getline(studentDataStream, lastName, ',');
		std::getline(studentDataStream, emailAddress, ',');
		std::getline(studentDataStream, age, ',');
		std::getline(studentDataStream, daysInCourse1, ',');
		std::getline(studentDataStream, daysInCourse2, ',');
		std::getline(studentDataStream, daysInCourse3, ',');
		std::getline(studentDataStream, degreeInput, ',');

		// Determine the correct Degree enum value from the degree string.
		if (degreeInput == "SECURITY")
			degreeProgram = SECURITY;
		else if (degreeInput == "NETWORK")
			degreeProgram = NETWORK;
		else if (degreeInput == "SOFTWARE")
			degreeProgram = SOFTWARE;

		Roster::add(studentID, firstName, lastName, emailAddress, std::stoi(age), std::stoi(daysInCourse1), std::stoi(daysInCourse2),
			std::stoi(daysInCourse3), degreeProgram);
	}
}

/***
Roster deconstructor
***/
Roster::~Roster() {
	for (int i = 0; i < 5; i++)
		if (classRosterArray[i] != nullptr)
			delete classRosterArray[i];
}

int main()
{
	// Create a new class roster.
	Roster* classRoster = new Roster();

	Student** classRosterArray = classRoster->getClassRosterArray();

	// Print assignment information.
	std::cout << "Scripting and Programming - Applications - C867 \tC++ \t\tStudent ID: #001214758  \tBenjamin Crew" << std::endl << std::endl;

	classRoster->printAll();

	std::cout << std::endl;

	classRoster->printInvalidEmails();

	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		classRoster->printAverageDaysInCourse(classRosterArray[i]->getStudentID());
	}

	std::cout << std::endl;

	classRoster->printByDegreeProgram(SOFTWARE);

	std::cout << std::endl;

	classRoster->remove("A3");
	classRoster->remove("A3");

	delete classRoster;

	return 0;
}