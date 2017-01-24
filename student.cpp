//Student.cpp
//contains the programs listed in student.h Manages four variables
//First, Last, ID, GPA


#include "student.h"

using namespace std;

Student::Student() {
	first = new char[20];
	last = new char[20];
	id = 0;
	gpa = 0;
}

Student::~Student() {
	delete first;
	delete last;
}

int Student::getId() {
	return id;
}

float Student::getGpa() {
	return gpa;
}

char* Student::getFirst() {
	return first;
}

char* Student::getLast() {
	return last;
}

