#ifndef STUDENT_H
#define STUDENT_H

//Student class, stored in Node*'s
//Stores a char* name, int id, and float gpa, with corresponding accessors.

#include <iostream>

using namespace std;

class Student {
 public:
  Student(char*, char*, int, float);
  ~Student();
  char* getName();
  int getId();
  float getGpa();
 protected:
  char* name;
  int id;
  float gpa;
};

#endif
