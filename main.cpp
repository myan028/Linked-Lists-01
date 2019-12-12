#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <iomanip>

#include "node.h"
#include "student.h"

using namespace std;

/*
Code by Michael Yan 12/12/19

This code runs a simple student list using linkedlists/nodes. The user can add a student with name, student id,
and gpa to the list. The user can also print the list which displays all students and their info in the 
database.
*/


//void add(int newValue);
//void print(Node* next);

Node* head = NULL;


//METHOD VS FUNCTION


void add(char* firstName, char* lastName, int id, float gpa){ //add function, pass in parameters
	Student* newStudent = new Student(firstName, lastName, id, gpa);
	Node* current = head;
	if(current == NULL){
		head = new Node();
		head->setStudent(newStudent);
	}
	
	else{
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		current->setNext(new Node());
		current->getNext()->setStudent(newStudent);
	}
}

void print(Node* next){ //print function
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
	
	while(true){ //while running true
		char input[100]; //userinput
		char* firstName = new char[50];
		char* lastName = new char [50];
		int id = 0;
		float gpa = 0;
		cout << "Enter a command ('add', 'print', 'exit'): ";
		cin.getline(input, 100);
		
		if(strcmp(input, "add") == 0){ //if user wants to add a student
			
			//prompts
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
			
			add(firstName, lastName, id, gpa); //call add method and implement user inputs
			//print(head);
			
		}
		
		else if(strcmp(input, "print") == 0){
			print(head); //call print method, prints node head
		}
		
		else if(strcmp(input, "exit") == 0){ //if user wants to exit
			return false; //kill program
		}
		
		else{ //if user enters an unsupported input
			cout << "That action is not recognized." << endl; //cycles back
		}
		
		
	}
  
}
