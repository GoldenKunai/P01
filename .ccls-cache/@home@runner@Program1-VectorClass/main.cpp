/*****************************************************************************
*                    
*  Author:           Delton Hughes
*  Email:            dlhughes0129@my.msutexas.edu
*  Label:            P01
*  Title:            Vector Class
*  Course:           CMPS 3013
*  Semester:         Spring 2020
* 
*  Description:
*        This program is creating an entire class called Vectors using a linked list.
*        Said class Vector will have several methods to create a list and manipulate
*        this list at your own whim. From pushing a integer to the front of the list
*        or to the back, or sorting a dynamically made array into ascending order. 
*        At the end of the program it will print the result to the outfile.
*        
*        . 
*        
*  Usage: 
*       -Allows the user to dynamicall create a linked list or a Vector
*       
*       
*  Files:            
*       main.cpp     :driver program
*       input.dat    :dat file with integer list
*       input1.dat   :dat file with integer list
*       input2.dat   :dat file with integer list
*       input3.dat   :dat file with integer list
*****************************************************************************/
#include <iostream>
#include <fstream>

using namespace std; 

struct Node {
  //Creating node structure 
  int data;
  Node *next;
  Node *prev; 

  //Constructor for Node
  Node(int d, Node *n=NULL, Node *p= NULL){
    data=d; 
    next=n;
    prev=p; 
  }
}; 
/**
 * Vector
 * 
 * Description:
 *      This class will have several methods that will allow for the user when needed
 *      to dynamically
 * 
 * Private Methods:
 *      - 
 *      - 
 *      - 
 * 
 * Public Methods:
 *      -  void pushFront(int val) 
 *      - 
 *      - 
 *      -
 *      -
 *      -
 *      -
 *      -
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */
class Vector {
  private: 
  Node *head; 
  int size; 
  public:

  Vector(){
  head = NULL;
  size = 0;
  }

  Vector(int A[], int amount){
    head=NULL;
    Node *traverse = head; 
    int num;
    Node*temp=new Node(num);
    
    
    for(int i = 0; i < amount; i++){
      Node * temp = new Node(num);
      pushRear(A[i]);
      size++;
    }
  }

  Vector(string FileName){
    head = NULL;
    size = 0;
    ifstream infile; 
    infile.open(FileName); 
    int temp;

    while(!infile.eof()) {
      infile >> temp;
      pushRear(temp);
      size++;
    }
    infile.close();
  
  }

  Vector(Vector &V1){

    head = NULL; 
    size = 0;
    int num; 
    Node *traverse = V1.head;
    while(traverse != NULL)
    {
      num=traverse->data;
      this->pushRear(num);
      traverse=traverse->next; 
      size++;
    }
   
  }
  
  
  public:
  //Push item to the front 
  void pushFront(int val)
  {
    Node *temp = new Node(val);
    if(head == NULL)
    {
      head = temp;
    }
    else
    {  
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
    size++;
  }
  
  void pushFront(Vector &V2){
    Node * traverse = V2.head;
    for(int i = 0; i < V2.getSize(); i++){
      this->pushFront();
    }
  }
  //Push item to the back 
  void pushRear(int val){
    Node *temp = new Node(val);

    if (head == NULL)
      head = temp;
    else {
      Node *traverse = head;
      while (traverse->next)
        traverse = traverse->next;

      temp->prev = traverse;
      traverse->next = temp;
    }
    // increment count
    size++;
  }

  void pushRear(Vector V1){
    
  }

  void inOrderPush(int val){
    Node *temp = new Node(val);

    if (head == NULL)
      head = temp;

    else if (temp->data < head->data)
      pushFront(val);

    else {
      Node *traverse = head;
      while (traverse->next && traverse->next->data < temp->data)
        traverse = traverse->next;

      if (traverse->next == NULL)
        pushRear(val);
      else {
        temp->next = traverse->next;
        traverse->next = temp;
        temp->prev = traverse;
        temp->next->prev = temp;
      }
    }
  }
  
  int popFront(){
    Node * pop = head;
    head = head -> next; 
    return head->data; 
    //Deleting node
    delete pop; 
    //Decrement size count
    size--; 
  }

  int popRear(){
    Node * pop = head; 

    Node * traverse = head; 

    while(traverse){
      pop = traverse->next; 
      traverse = traverse->next; 
      
    }
    return pop->data; 
    traverse->prev->next=NULL; 
    size--; 
  }

  void pushAt(int loc, int val){
    Node * temp = new Node(val); 
    int index = 0; 

    if(head==NULL) {
      head = temp; 
    }
    else { 
      //Need to be able to traverse to find index
      Node * traverse = head; 
      
      while(loc-1 != index){
        traverse = traverse->next; 
        index++;   
      } 
      temp->next = traverse->next;
      temp->prev = traverse; 
      traverse->next = temp;
    }
    size++;
  }

  int popAt(int loc){
    //Need to be able to traverse to find index
    Node * traverse = head; 
    Node * pop = head; 
    int index = 0; 

    while(loc-1 != index){
      traverse = traverse->next; 
      pop = pop -> next;
      index++;   
    } 
    
    traverse->prev->next = traverse->next; 
    traverse->next->prev=traverse; 
    return pop->data;
    delete pop; 

    size--;
  }

  int peakFront(){
    return head->data;
  }

  int peakBack(){
    Node * traverse = head;

    while(traverse->next) {
      traverse = traverse->next; 
    }
    return traverse->data;
  }

  int find(int val){
  
  int index = 0; 
  Node *traverse = head; 

  while(traverse)
  {
    traverse = traverse->next; 
    index++;
    if(traverse->data == val)
    {
      return index; 
    }
    else if(traverse->data != val)
    {
        return -1; 
    }
  } 
}
   
  int getSize(){
    return size; 
  }

  void print(){
    ofstream outfile;
    outfile.open("test.out", ios::app);
    Node *traverse = head; 
   
    
    outfile << "[";
    cout << "[";
    while(traverse) {
      outfile << traverse->data;
      cout << traverse->data;
      traverse = traverse -> next; 
      if(traverse != NULL){
        outfile << ", ";
        cout << ", ";
      }
      
    }
    outfile << "]" << endl;
    cout << "]" << endl;
  }

};

int main() {
ofstream outfile; 
outfile.open("test.out");

outfile << "Delton Hughes" << endl;
outfile << "2/6/2023" << endl;
outfile << "Fall 2143"<< endl; 
cout << endl;
int x = 0;

Vector v1;
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print();
// [25, 20, 18, 18, 20, 25]

int A[] = {11,25,33,47,51};
Vector v2(A,5);
v2.print();
// [11, 25, 33, 47, 51]

v2.pushFront(9);
v2.inOrderPush(27);
v2.pushRear(63);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]

v1.pushRear(v2);
v1.print();
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
cout<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33]
cout<<x<<endl;
// 47

x = v2.popAt(3);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]
cout<<x<<endl;
// 27

x = v2.find(51);
cout<<x<<endl;
// 5

x = v2.find(99);
cout<<x<<endl;
// -1

Vector v3(v1);
v3.print();
// [18, 20, 25, 9, 11, 25, 27, 33]

// v3.pushFront(v2);
v3.print();
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

Vector v4("input.dat");
v4.pushRear(v3);
v4.print();
// [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
outfile.close();
  return 0; 
}