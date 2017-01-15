//Node class for Main.cpp

#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

//Constructor: stores a Student*, sets next to NULL
Node::Node(Student* newStudent){
  student = newStudent;
  next = NULL;
}

//Deconstructor: deletes Student*, sets next to NULL
Node::~Node(){
  delete student;
  next = NULL;
}

Node* Node::getNext(){
  return next;
}

void Node::setNext(Node* newNext){
  next = newNext;
}

Student* Node::getStudent(){
  return student;
}
