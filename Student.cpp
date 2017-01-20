//Student class for Main.cpp

#include <iostream>
#include "Student.h"
#include <string.h>

using namespace std;

//Constructor, takes in two char*'s, an id, and a float
Student::Student(char* newNameFirst, char* newNameLast, int newId, float newGpa){
  name = new char[81];
  strcpy(name, newNameFirst);
  strcat(name, " ");
  strcat(name, newNameLast);
  id = newId;
  gpa = newGpa;
}

//Deconstructor
Student::~Student(){
  delete name;
}

//Returns name
char* Student::getName(){
  return name;
}

//Returns id
int Student::getId(){
  return id;
}

//Returns gpa
float Student::getGpa(){
  return gpa;
}

