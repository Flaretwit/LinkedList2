#include "node.h"
//main.cpp
#include <vector>

using namespace std;

int main() {

	return 0;
}


//compares the input to known commands
int parseCommand(char *input) {
	if(!strcmp(input, "ADD")) {
		return ADD;
	}
	else if(!strcmp(input, "PRINT")) {
		return PRINT;
	}
	else if(!strcmp(input, "DELETE")) {
		return DELETE;
	}	
	else if(!strcmp(input, "EXIT")) {
		return EXIT;
	}
	else {
		return 0;
	}
}

//adds a student the vector: list. 
Node* getInfo() {
	Student* student = new Student();
	Node newNode = new Node(student);
	
	cout << "Enter first name: ";
	cin >> student->first;
	cin.clear();

	//deals with last name
	cout << "Enter last name: ";
	cin >> student->last;
	cin.clear();

	//deals with id
	cout << "Enter ID number: ";
	cin >> student->id;
	
	cin.clear();	
	
	//deals with gpa
	cout << "Enter GPA: ";
	cin >> student->gpa;
	
	return newNode;
}

void addEntry(Node* node, Node* current) {
	if(
	if(node->getStudent()->getId() > current->getStudent()->getId()) {
		node->setNext(current->getNext());
		current->setNext(node);
	}
	else {
	addEntry(node, current->getNext());
	}
}
