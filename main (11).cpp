#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	string name;
  int age;
	Node* next;
	Node* prev;
  
  Node(string val, int a) {
        prev = NULL;
        name = val;
        age = a;
        next = NULL;
    }
};

class LinkedList {
public:
  Node* head;
  Node* tail;
  int length;

  LinkedList(string value, int age) {
      head = new Node(value, age);
      tail = head;
      length = 1;
  }

  void prepend(string value, int age) {
    Node* n = new Node(value, age);
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
    length++;
  }

  void append(string value, int age) {
    if (head == NULL) {
        prepend(value, age);
      return;
    }
    Node* n = new Node(value, age);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    length++;
  }
  
  vector<string> printList() {
    vector<string> array;
    currentNode = head;
    while(currentNode != NULL){
        array.push_back(currentNode -> value);
        currentNode = currentNode -> next;
    }
    return array;
  }

  Node* traverseToIndex(int index) {

    //Check parameters
    int counter = 0;
    Node* currentNode = head;
    while(counter != index){
      currentNode = currentNode->next;
      counter++;
    }
    return currentNode;
  }

  void insert(int index, string value, int age){
    if(index >= length) {
      append(value, age);
      return;
    }
    Node* newNode = new Node(value, age)
    Node* leader = traverseToIndex(index-1);
    Node* holdingPointer = leader -> next;
    leader -> next = newNode;
    newNode -> prev = leader;
    newNode -> next = holdingPointer;
    holdingPointer -> prev = newNode;
    this.length++;
  }

  void remove(int index) {
    if(index == length - 1){
      tail = tail -> prev;
      tail -> next = NULL;
      length--;
      return;
    }
    if(index == 0){
      head = head -> next;
      head -> prev = NULL;
      length--;
      return
    }
    Node* leader = traverseToIndex(index-1);
    Node* unwantedNode = leader -> next;
    Node* nextNode = leader -> next -> next;    
    leader -> next = nextNode;
    nextNode -> prev = leader;
    length--;
  }



int main() {
LinkedList* myLinkedList = new LinkedList("Grandmom", 76);
myLinkedList.append("Father", 53);
myLinkedList.append("Mother", 51);
myLinkedList.append("Vaibhav", 18);
myLinkedList.append("Sister", 15);
}
