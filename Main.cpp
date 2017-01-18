/* C++ Project 7 - Nathan Purwosumarto - 1/15/2017
LinkedLists Part 2 - Use of Linked Lists to hold, modify, and display a list of Student*'s */

#include <iostream>
#include <string.h>
#include <iomanip>
#include <limits>
#include "Student.h"
#include "Node.h"

using namespace std;

int getInt(char* message);
float getFloat(char* message);
void getInput(char* input);
void trimWhitespace(char* text);
void setLowercase(char* text);
void addStudent(Node* & head);
void deleteStudent(Node* & head);
void display(Node* head);
void average(Node* head);



int main()
{
  Node* head = NULL;
  bool running = true;
  char input[81];

  cout << "\nWelcome to the new and improved Student List v2.0!\n";
  cout << "Your commands are: add, print, average, delete, and quit.\n\n";
  

  while(running){
    cout << "Awaiting input: ";
    getInput(input);
    //if input = QUIT, then end the program
    if(strcmp(input, "quit") == 0){
      cout << "\nProgram Terminated." << endl;
      running = false;
    }
    //if input = ADD, then add a student
    else if(strcmp(input, "add") == 0){
      addStudent(head);
    }
    else if(strcmp(input, "print") == 0){
      display(head);
    }
    else if(strcmp(input, "average") == 0){
      average(head);
    }
    else if(strcmp(input, "delete") == 0){
      deleteStudent(head);
    }
  }

  return 0;

}

void addStudent(Node* & head){
  char nameFirst[81];
  char nameLast[81];
  int id;
  float gpa;
  char msg[81];
  cout << "\n-----ADDING STUDENT-------\n";
  cout << "Enter first name: ";
  cin.getline(nameFirst, 81);
  cout << "Enter last name: ";
  cin.getline(nameLast, 81);
  strcpy(msg, "Enter student ID: ");
  id = getInt(msg);
  strcpy(msg, "Enter student GPA: ");
  gpa = getFloat(msg);
  cin.ignore(80, '\n');
  Student* s = new Student(nameFirst, nameLast, id, gpa);
  Node* n = new Node(s);
  if(head == NULL){
    head = n;
  }
  else if(head->getStudent()->getId() > id){
    n->setNext(head);
    head = n;
  }
  else{
    Node* current = head;
    while(current->getNext() != NULL &&
	  (current->getNext()->getStudent()->getId() <= id)){
      current = current->getNext();
    }
    n->setNext(current->getNext());
    current->setNext(n);
  }
  cout << "\n";
}

void deleteStudent(Node* & head){
  char msg[81];
  strcpy(msg, "Enter ID of student to delete: ");
  cout << "\n-----DELETING STUDENT------\n";
  //tell the user if there are no students
  if(head == NULL){
    cout << "\nThere are no students stored.\n" << endl;
  }
  else{
    int idDelete = getInt(msg);
    //if the id of Node* head matches the id to be deleted, set head to the next Node* in the list if it exists, otherwise set head to null
    if(head->getStudent()->getId() == idDelete){
      cout << "\nDeleted student '" << head->getStudent()->getName() << "', " << head->getStudent()->getId() << ", " << fixed << setprecision(2) << head->getStudent()->getGpa() << "\n\n";
      if(head->getNext() == NULL){
    	delete head;
    	head = NULL;
      }
      else{
    	Node* n = head->getNext();
    	delete head;
    	head = n;
      }
    }
    else{
      Node* current = head;
      //iterate through the list until we find a Node* where its next Node* has a student that matches the id to be deleted
      while(current->getNext() != NULL && current->getNext()->getStudent()->getId() != idDelete){
	current = current->getNext();
      }
      //tell the user if no student matching that id was found
      if(current->getNext() == NULL){
	cout << "\nNo students found with ID: " << idDelete << "\n\n";
      }
      //delete specified student and fix the links between the other Node*'s
      else{
	Node* n = current->getNext()->getNext();
	cout << "\nDeleted student '" << current->getNext()->getStudent()->getName() << "', " << current->getNext()->getStudent()->getId() << ", " << fixed << setprecision(2) << current->getNext()->getStudent()->getGpa() << "\n\n";
	delete current->getNext();
	current->setNext(n);
      }
    }
    cin.ignore(81,'\n');
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
      cout << current->getStudent()->getName() << ", " << current->getStudent()->getId() << ", " << fixed << setprecision(2) << current->getStudent()->getGpa() << endl;
      current = current->getNext();
    }
  }
  cout << "\n---------------------------\n";
}

void average(Node* head){
  float total = 0;
  float average = 0;
  int students = 0;
  if(head == NULL){
    cout << "There are no students stored." << endl;
  }
  else{
    Node* current = head;
    while(current != NULL){
      total += current->getStudent()->getGpa();
      students++;
      current = current->getNext();
    }
    average = total / students;
    cout << "\nNumber of students: " << students << "  Average GPA: "<< fixed << setprecision(2) << average << "\n\n";
  }

}


//prompts the user for an integer
int getInt(char* message)
{
  int number;
  bool valid = false;
  while (!valid){
    cout << message;
    cin >> number;
    //delete excess whitespace
    while (cin.peek() == ' '){
      cin.ignore(1);
    }
    if(cin.peek() != '\n'){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else{
      valid = true;
    }
  }
  return number;
}

//prompts the user for a float
float getFloat(char* message)
{
  float number;
  bool valid = false;
  while (!valid){
    cout << message;
    cin >> number;
    //delete excess whitespace
    while (cin.peek() == ' '){
      cin.ignore(1);
    }
    if(cin.peek() != '\n'){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else{
      valid = true;
    }
  }
  return number;
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
