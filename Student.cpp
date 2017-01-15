//Student class for Main.cpp

#include <iostream>
#include "Student.h"
#include <string.h>

using namespace std;

Student::Student(char* newNameFirst, char* newNameLast, int newId, float newGpa){
  name = new char[81];
  strcpy(name, newNameFirst);
  strcat(name, " ");
  strcat(name, newNameLast);
  id = newId;
  gpa = newGpa;
}

Student::~Student(){
  delete name;
}

char* Student::getName(){
  return name;
}

int Student::getId(){
  return id;
}

float Student::getGpa(){
  return gpa;
}

