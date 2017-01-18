#pragma once
#include<vector>
#include<map>
#include<iostream>
#include<stdio.h>
#include "string.h"
#include "student.h"
using namespace std;

class Node{
 public:
  Node(Student*); //Constructor
  ~Node(); //Deconstructor
  Node* getNext(); //Get next Node pointer
  Student* getStudent(); //Get student pointer
  void setNext(Node*); //Set the next pointer to the corresponding node pointer
 protected:
  Student* student;
  Node* node;
};
