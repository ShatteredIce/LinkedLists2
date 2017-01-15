#ifndef NODE_H
#define NODE_H

//Header file for Node.cpp
//Node for linked lists of Student class
//Stores values: next Node* and stored Student*

#include <iostream>
#include "Student.h"

using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();
  Node* getNext();
  void setNext(Node*);
  Student* getStudent();
 protected:
  Student* student;
  Node* next;
};
#endif
