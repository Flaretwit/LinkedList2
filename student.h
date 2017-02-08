//student.h
//Header file for the Student class
#include <iostream>
using namespace std;

class Student {
	public:
		Student();
		~Student();
		void setId(int id);
		void setGpa(float gpa);
		void setFirst(char* first);
		void setlast(char* last);
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
