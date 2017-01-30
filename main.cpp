//main.cpp
#include "node.h"
#include <vector>
#include <iostream>
#define ADD 1
#define PRINT 2
#define DELETE 3
#define EXIT 4

using namespace std;

int main() {
	bool continue = true;
	Node* head = new Node();

	cout << "Welcome to StudentList v. 2. Uses a LinkedList implementation now." << endl;
	while(continue) {
		char* input = new char[20];
		cin >> input;
			cout << "Would you like to ADD, PRINT, DELETE, or EXIT?" << endl;
		switch(parseCommand(input)) {
			case ADD:
				add(getInfo(), head);
			case PRINT:
				print(head);
			case DELETE:
				if(current->getStudent()->getId() == head->getStudent()->getId()) {
					Node temp = head;
					head = head->getNext();
					delete temp;
				}
			case EXIT:
				continue = false;
		}
	}


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
		return 0;:
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
//adds an entry to the linkedlist in ascending order based on ID
void add(Node* node, Node* current) {
	if(current->getNext() == NULL) {
		current->setNext(node);
	}
	else if(node->getStudent()->getId() < current->getStudent()->getId()) {
		node->setNext(current->getNext());
		current->setNext(node);
	}
	else {
	add(node, current->getNext());
	}
}
//prints all students and their information (first, last, GPA, id)
void print(Node* current) {
	cout << "Name: " << current->getStudent()->getFirst() << " " << current->getStudent()->getLast() << ", GPA: " <<
	current->getStudent()->getGpa() << ", ID: " << current->getStudent()->getId() << endl;
	if(current->getNext() != NULL) {
		print(current->getNext());
	}
}
//deletes a student from the LinkedList based on ID
void delete(int id, Node* current, Node*& head) {
	//checks the edge of when the head node is the node to delete

	else if(current->getStude)

}
