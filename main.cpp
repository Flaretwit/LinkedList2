//main.cpp
#include "node.h"
#include <vector>
#include <iostream>
#include <iomanip>

#define ADD 1
#define PRINT 2
#define DELETE 3
#define EXIT 4
#define AVERAGE 5

using namespace std;

int parseCommand(char* input);
Node* getInfo();
void add(Node*& head, Node* current);
void print(Node* head);
void deleteNode(Node*& head, int id);
void averageList(Node* head);


int main() {
	bool continueon = true;
	Node* head;

	cout << "Welcome to StudentList v. 2. Uses a LinkedList implementation now." << endl;
	while(continueon) {
		char* input = new char[20];
		cout << "Would you like to ADD, PRINT, DELETE, or EXIT?" << endl;
		cin >> input;
						int id2 = 0;
		switch(parseCommand(input)) {
			case ADD:
				add(head, getInfo());
				break;
			case PRINT:
				if(head!= NULL) {
				print(head);
			}
				break;
			case DELETE:
				cout << "What is the id of the student you want to delete?" << endl;
				cin >> id2;
				deleteNode(head, id2);
				break;
			case AVERAGE:
				averageList(head);
				break;
			case EXIT:
					continueon = false;
					break;
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
	else if(!strcmp(input, "AVERAGE")) {
		return AVERAGE;
	}
	else {
		return 0;
	}
}

//adds a student the vector: list.
Node* getInfo() {
	Student* student = new Student();
	char* first = new char[20];
	cout << "Enter first name: ";
	cin >> first;
	cin.clear();
	student->setFirst(first);
  char* last = new char[20];
	//deals with last name
	cout << "Enter last name: ";
	cin >> last;
	cin.clear();
	student->setLast(last);

	int id = 0;
	//deals with id
	cout << "Enter ID number: ";
	cin >> id;
	cin.clear();
	student->setId(id);

	//deals with gpa
	float gpa = 0.0;
	cout << "Enter GPA: ";
	cin >> gpa;
	student->setGpa(gpa);
	Node* newNode = new Node(student);
	return newNode;
}

//adds an entry to the linkedlist in ascending order based on ID
void add(Node*& head, Node* current) {
	if(head == NULL) {
		head = current;
		return;
	}
	else if(current->getStudent()->getId() < head->getStudent()->getId()){
			current->setNext(head);
			head = current;
			return;
	}
	else {
		Node* next = head->getNext();
		add(next, current);
		head->setNext(next);
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
void deleteNode(Node*& head, int id) {
	Node* temp;
	//if no head
	if(head == NULL) {
		cout << "No students to delete";
		return;
	}
	//if head is the partner to delete
	if(head->getStudent()->getId() == id) {
		temp = head;
		head = head->getNext();
		delete temp;
		cout << "Student with ID " << id << " was just deleted :D." << endl;
		return;
	}
	else {
		temp = head->getNext();
		deleteNode(temp, id);
		head->setNext(temp);
	}
}

//Averages all student GPAs
void averageList(Node* head){
  float total = 0;
  int number = 0;
  Node* temp = head;
  float average = 0;
  if(head == NULL){
    cout << "There are no students" << endl;
    return;
  }
  while(temp != NULL){
    total = total + temp->getStudent()->getGpa();
    number++;
    temp = temp->getNext();
  }
  average = total/number;
  cout << "Average: " << setprecision(2) << fixed << average << endl;
}
