#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <iomanip>

#include "node.h"
#include "student.h"

using namespace std;

//void add(int newValue);
//void print(Node* next);

Node* head = NULL;

void add(char* firstName, char* lastName, int id, float gpa){
	Student* newStudent = new Student(firstName, lastName, id, gpa);
	Node* current = head;
	if(current == NULL){
		head = new Node(newStudent); ////////
		head->setStudent(newStudent);
	}
	
	else{
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		current->setNext(new Node(newStudent)); //////
		current->getNext()->setStudent(newStudent);
	}
}

void print(Node* next){
	if(next == head){
		cout << "List:\n\n";
	}
	if(next != NULL){
		cout << "Name: " << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << ", ID: " << next->getStudent()->getId() << ", GPA: "  << fixed << setprecision(2) << next->getStudent()->getGpa() << "\n" << endl; //prints student info in the node
		print(next->getNext());
	}
}


/*Student* add(){
	Student* newStudent = new Student();
	
	
}*/


int main(){
	//Node *head = NULL;
	//Node *tail = NULL;
	
	while(true){
		char input[100];
		char* firstName = new char[50];
		char* lastName = new char [50];
		int id = 0;
		float gpa = 0;
		cout << "Enter a command ('add', 'print', or 'exit'): ";
		cin.getline(input, 100);
		
		if(strcmp(input, "add") == 0){ //if user wants to add a student
			cout << "Enter the student's first name: ";
			cin.getline(firstName, 50);
			cout << "Enter the student's last name: ";
			cin.getline(lastName, 50);
			
			cout << "Enter their student id: ";
			cin >> id;
			cin.clear(); cin.ignore(10000, '\n');
			
			cout << "Enter the student's gpa: ";
			cin >> gpa;
			cin.clear(); cin.ignore(10000, '\n');
			
			add(firstName, lastName, id, gpa);
		}
		
		else if(strcmp(input, "print") == 0){ //if user wants to print list
			print(head);
		}
		
		else if(strcmp(input, "exit") == 0){ //if user wants to exit
			return false;
		}
		
		else{ //if user enters an unsupported input
			cout << "That action is not recognized." << endl;
		}
		
		
	}
  
}
