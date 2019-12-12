#include <iostream>
#include <cstring>
#include <vector>

#ifndef STUDENT_H 
#define STUDENT_H

using namespace std;

class Student{
 public: //initialize variables for all students
  Student(char* newFirstName, char* newLastName, int newId, float newGpa);
  char* getFirstName(); //getters
  char* getLastName();
  int getId();
  float getGpa();
  ~Student(); //destructor
 private: //initialize for individual students
  char* firstName = new char[100];
  char* lastName = new char[100];
  int id;
  float gpa;
  


};

#endif