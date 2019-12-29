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

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	// Create an array to be fed to the appropriate subclass.
	/*int days[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	if (degreeProgram == SECURITY) {
		classRosterArray[nextEmptySlot] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, &days, degreeProgram);
	}
	else if (degreeProgram == NETWORK) {
		classRosterArray[nextEmptySlot] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, &days, degreeProgram);
	}
	else if (degreeProgram == SOFTWARE) {
		classRosterArray[nextEmptySlot] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, &days, degreeProgram);
	}
	// Handle an invalid degree program.
	else {

	}*/
}

void Roster::remove(std::string studentID) {

}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		classRosterArray[i]->print();
	}
}

Roster::Roster() {
	// Set class roster array index to first slot.
	nextEmptySlot = 0;
}

Roster::~Roster() {
	delete *classRosterArray;
}

int main()
{
	std::istringstream studentDataStream;

	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string age;
	std::string daysInCourse1, daysInCourse2, daysInCourse3;
	std::string degreeProgram;

	// Create a new class roster.
	Roster* classRoster = new Roster();

	for (int i = 0; i < 5; i++) {
		// Read each string from the studentData const into an input string stream.
		studentDataStream.str(studentData[0]);

		// Parse each piece of data into the appropriate variable using a comma delimiter.
		std::getline(studentDataStream, studentID, ',');
		std::getline(studentDataStream, firstName, ',');
		std::getline(studentDataStream, lastName, ',');
		std::getline(studentDataStream, emailAddress, ',');
		std::getline(studentDataStream, age, ',');
		std::getline(studentDataStream, daysInCourse1, ',');
		std::getline(studentDataStream, daysInCourse2, ',');
		std::getline(studentDataStream, daysInCourse3, ',');
		std::getline(studentDataStream, degreeProgram, ',');

		//classRoster->add(studentID, firstName, lastName, emailAddress, std::stoi(age), std::stoi(daysInCourse1), std::stoi(daysInCourse2), std::stoi(daysInCourse3), NETWORK);
		//classRoster->printAll();
	}

	int input;
	std::cin >> input;

	return 0;
}