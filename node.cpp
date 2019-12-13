
#include <iostream>
#include <cstring>
#include <vector>

#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student* newStudent){
  //value = 0;
  student = NULL;
  next = NULL;
}

/*void Node::setValue(int newValue){
  value = newValue;
}

int Node::getValue(){
  return value;
}*/

Student* Node::getStudent(){
	return student;
}

void Node::setStudent(Student* newStudent){
	student = newStudent;
}

void Node::setNext(Node* newNext){
  next = newNext;
}

Node* Node::getNext(){
  return next;
}

Node::~Node(){
  delete &student;
  next = NULL;
}