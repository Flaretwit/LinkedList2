//student.h
//Header file for the Student class

using namespace std;

class Student {
	public:
		Student();
		~Student();
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
