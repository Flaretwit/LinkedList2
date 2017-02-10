//student.h
//Header file for the Student class
#include <iostream>
using namespace std;

class Student {
	public:
		Student();
		~Student();
		void setId(int id);
		void setGpa(float newGPA);
		void setFirst(char* first);
		void setLast(char* last);
		int getId();
		float getGpa();
		char* getFirst();
		char* getLast();
	private:
		char* first;
		char* last;
		int id;
		float gpa;
};
