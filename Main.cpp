/* C++ Project 7 - Nathan Purwosumarto - 1/15/2017
LinkedLists Part 2 - Use of Linked Lists to hold, modify, and display a list of Student*'s */

#include <iostream>
#include <string.h>
#include "Student.h"
#include "Node.h"

using namespace std;

void getInput(char* input);
void trimWhitespace(char* text);
void setLowercase(char* text);
void addStudent(Node* & head);
void display(Node* head);

int main()
{
  Node* head = NULL;
  bool running = true;
  char input[81];
  int idDelete = 0;

  while(running){
    cout << "Awaiting input: ";
    getInput(input);
    //if input = QUIT, then end the program
    if(strcmp(input, "quit") == 0){
      cout << "Program Terminated." << endl;
      running = false;
    }
    //if input = ADD, then add a student
    else if(strcmp(input, "add") == 0){
      addStudent(head);
    }
    else if(strcmp(input, "print") == 0){
      display(head);
    }
  }

  return 0;

}

void addStudent(Node* & head){
  char nameFirst[81];
  char nameLast[81];
  int id;
  float gpa;
  cout << "\n-----ADDING STUDENT-----\n";
  cout << "Enter first name: ";
  cin.getline(nameFirst, 81);
  cout << "Enter last name: ";
  cin.getline(nameLast, 81);
  cout << "Enter student ID: ";
  cin >> id;
  cin.ignore(80,'\n');
  cout << "Enter student GPA: ";
  cin >> gpa;
  cin.ignore(80, '\n');
  Student* s = new Student(nameFirst, nameLast, id, gpa);
  Node* n = new Node(s);
  Node* current = head;
  if(current == NULL){
    //cout << "set head" << endl;
    head = n;
    //display(head);
  }
  else{
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(n);
  }
}

void display(Node* head){
  cout << "\n-----PRINTING STUDENTS-----\n\n";
  if(head == NULL){
    cout << "There are no students stored." << endl;
  }
  else{
    Node* current = head;
    while(current != NULL){
      cout << current->getStudent()->getName() << ", " << current->getStudent()->getId() << ", " << current->getStudent()->getGpa() << endl;
      current = current->getNext();
    }
  }
}



//stores user input into a char*
void getInput(char* input){
  fill(input, input + 81, ' ');
  cin.getline(input, 81);
  trimWhitespace(input);
  setLowercase(input);
}

//deletes excess whitespace from a char*
void trimWhitespace(char* text){
  char* newText = text;
  char lastChar = ' ';
  while(*text != '\0'){
    if(!(*text == ' ' && lastChar == ' ')){
      *newText = *text;
      lastChar = *text;
      newText++;
    }
    text++;
  }
  if(*(newText-1) != ' '){
    *newText = '\0';
  }
  else{
    *(newText-1) = '\0';
  }
}

//sets all characters in a char* to lowercase
void setLowercase(char* text){
  for(int i = 0; i < strlen(text); i++){
    text[i] = tolower(text[i]);
  }
}
