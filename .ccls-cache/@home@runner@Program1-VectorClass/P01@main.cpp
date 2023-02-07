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
 *   This program is creating an entire class called Vectors using
 *   a linked list. Said class Vector will have several methods to create
 *   a list and manipulate this list at your own whim. From pushing a
 *   integer to the front of the list or to the back, or sorting
 *   a dynamically made array into ascending order.
 *   At the end of the program it will print the result to the outfile.
 *
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
#include <fstream>
#include <iostream>

using namespace std;

struct Node {
              // Creating node structure
  int data;   // Creates spot for data
  Node *next; // Creates a spot for next pointer      
  Node *prev; // Creates a spot for prev pointer 

  // Constructor for Node
  Node(int d, Node *n = NULL, Node *p = NULL) {
    data = d; //passes in d for data
    next = n; //passes in n for next
    prev = p; //passes in p for prev
  }
};
/***********************************************************
 * Vector
 *
 * Description:
 *      This class will have several methods that will allow for
 *      the user when needed,to dynamically create a list of integers
 *      that can be manipulated in different ways.
 *
 * Private Methods:
 *      - None
 *
 * Public Methods:
 *      -  void pushFront(int val)
 *      -  void pushFront(Vector &V2)
 *      -  void pushRear(int val)
 *      -  void pushRear(Vector V1)
 *      -  void inOrderPush(int val)
 *      -  int popFront()
 *      -  int popRear()
 *      -  int popAt(int loc)
 *      -  int peakFront()
 *      -  int peakBack()
 *      -  int find(int val)
 *      -  int getSize()
 *      -  void print()
 * Usage:
 *
 *      -  v1.pushFront(18);          //pushes number to the front
 *      -  v1.pushRear(18);           //pushes number to the back
 *      -  v1.print();                //prints to outfile
 *      -  Vector v2(A,5);            //creates an array
 *      -  x = v1.popFront();         //takes off the front and deletes
 *      -  v2.inOrderPush(27);        //makes list of ints increasing order
 *      -  x = v1.popRear();          //
 *      -  x = v2.popAt(3);           //
 *      -  x = v2.find(51);           //
 *      -  Vector v4("input.dat");    //
 *
 **************************************************************/
class Vector {
private:
  Node *head; //Creates head(the start of the list)
  int size;   //creates size variable to 

public:
  /**
   * Public : Vector
   *
   * Description:
   *      Sets head to NULL and size to 0;
   *
   * Params:
   *      -None
   *
   * Returns:
   *      - Nothing
   */
  Vector() {
    head = NULL;
    size = 0;
  }

  /**
   * Public : Vector(int A[], int amount)
   *
   * Description:
   *   Takes in an array and the size or amount also increments size
   *   creates two nodes traverse and temp is dynamically created. 
   * Params:
   *      - an integer array
   *      - an integer amount
   *
   * Returns:
   *      - nothing
   */
  Vector(int A[], int amount) {
    head = NULL;                        
    Node *traverse = head;              
    int num;
    Node *temp = new Node(num);         //Dynamically allocate space for temp

    for (int i = 0; i < amount; i++) {  //uses amount to know how long to run  
      Node *temp = new Node(num);       
      pushRear(A[i]);                   //Let pushRear do all the work
      size++;                            
    }
  }

  /**
   * Public : vector(string FileName)
   *
   * Description:
   *   Passes in an input filename opens it and
   *   reads in the integers in the file.
   * Params:
   *      - string FileName
   
   *
   * Returns:
   *      - nothing
   */
  Vector(string FileName) {
    head = NULL;
    size = 0;
    ifstream infile;
    infile.open(FileName);
    int temp;

    while (!infile.eof()) { //Run till the end of file
      infile >> temp;
      pushRear(temp);       //Let pushRear do the work
      size++;               //increments count of size
    }
    infile.close();
  }

  /**
   * Public : Vector(Vector &V1)
   *
   * Description:
   *  Passes vector V1 by reference in goes through the list
   *  and gets the data that was in said list. Copy Constructors weird cousin.
   * Params:
   *      - Vector &V1
   *
   * Returns:
   *      nothing
   */
  Vector(Vector &V1) {

    head = NULL;
    size = 0;
    int num;
    Node *traverse = V1.head;
    while (traverse != NULL) {  //while traverse is able to move run
      num = traverse->data;
      this->pushRear(num);      //use pushRear to do the heavy lifting
      traverse = traverse->next;
      size++;                   //increment count
    }
  }

  /**
   * Public : void pushFront(int val)
   *
   * Description:
   *   Pushes the value in the parameter to the front
   *   of the list. 
   * Params:
   *      - int val

   *
   * Returns:
   *      - void
   */
  void pushFront(int val) {
    Node *temp = new Node(val);
    if (head == NULL) {          //when head equals null
      head = temp;
    } else {                     
      temp->next = head;         //The next two lines:
      head->prev = temp;         //These connect the nodes so we 
      head = temp;               //do not lose the data (stitches together)
    }
    size++;                      //increment count
  }      

  /**
   * Public:void pushFront(Vector &V2)
   *
   * Description:
   *   Is suppose to push an entire list into the front 
   *   of another list. 
   * Params:
   *      - Vector &V2
   *
   * Returns:
   *      - void
   */
  void pushFront(Vector &V2) {
    Node *traverse = V2.head;
    for (int i = 0; i < V2.getSize(); i++) {
      // this->pushFront();
    }
  }

  /**
   * Public: void pushRear(int val)
   *
   * Description:
   *  Does exactly what pushFront does but pushes the int value
   *  to the back of the list.
   * Params:
   *      - int va

   *
   * Returns:
   *      - void
   */
  void pushRear(int val) {
    Node *temp = new Node(val);    //Creating space for temp

    if (head == NULL)              //If head is null then temp is head
      head = temp;
    else {                         //otherwise
      Node *traverse = head;       
      while (traverse->next)       //While there is a next in traverse
        traverse = traverse->next; //keep going

      temp->prev = traverse;       
      traverse->next = temp;
    }
    size++;                        //// increment count
  }

  /**
   * Public : void pushRear(Vector V1)
   *
   * Description:
   *   Is suppose to push the list to the back of another list.
   *
   * Params:
   *      - Vector V1
   *
   * Returns:
   *      - void
   */
  void pushRear(Vector V1) {}
  /**
   * Public : void inOrderPush(int val) 
   *
   * Description:
   *  Takes the given list and organized the integers
   *  into increasing order(smallest to largest). 
   * Params:
   *      - int val
   *
   * Returns:
   *      - void
   */
  void inOrderPush(int val) {
    Node *temp = new Node(val);       

    if (head == NULL)                  //if nothing in head
      head = temp;                     //temp is equal tohead

    else if (temp->data < head->data)  //data in temp is less then head data
      pushFront(val);                  //push data value to the front

    else {
      Node *traverse = head;
      while (traverse->next && traverse->next->data < temp->data)
        traverse = traverse->next;     //traverse the list

      if (traverse->next == NULL)      //if next is nothing
        pushRear(val);                 //push to back
      else {                           
        temp->next = traverse->next;   //The next three lines:
        traverse->next = temp;         //This stitches together 
        temp->prev = traverse;         //the mess we made
        temp->next->prev = temp;       //
      }
    }
  }
  /**
   * Public:int popFront()
   *
   * Description:
   *  Takes what is in the front of the list out and 
   *  deletes it to free the space back up.
   * Params:
   *      - nothing
   *
   * Returns:
   *      - integer
   */
  int popFront() {
    Node *pop = head;
    head = head->next;
    return head->data;
    delete pop;         // Deleting node
    size--;             // Decrement size count
  }
  /**
   * Public :  int popRear()
   *
   * Description:
   *  Does exactly the same as popFront but does it to the back.
   *  So it takes what is in the back and deletes its space.
   * Params:
   *      - nothing
   *
   * Returns:
   *      - integer
   */
  int popRear() {
    Node *pop = head;

    Node *traverse = head;

    while (traverse) {          //while we have traverse
      pop = traverse->next;     
      traverse = traverse->next;//allows us to move through list
    }
    return pop->data;           //return whats in the pop data
    traverse->prev->next = NULL;//stiches together
    size--;                     //Decrement count
  }  
  /**
   * Public : void pushAt(int loc, int val)
   *
   * Description:
   *   Takes what is in the location of the indeces
   *   and pushes it to desired location. 
   * Params:
   *      - int loc
   *      - int val

   *
   * Returns:
   *      - integer
   */
  void pushAt(int loc, int val) {
    Node *temp = new Node(val);
    int index = 0;

    if (head == NULL) {  
      head = temp;
    } else {
      Node *traverse = head;

      while (loc - 1 != index) {  //the location before doesnt equal we wont
        traverse = traverse->next;//keep moving
        index++;                  //increment index count to keep track
      }    
      temp->next = traverse->next;//These next 2 lines:
      temp->prev = traverse;      //These tie the nodes 
      traverse->next = temp;      //back together
    }
    size++;                       //size counter increment
  }
  /**
   * Public:int popAt(int loc)
   *
   * Description:
   *  Give what location you want in the index and 
   *  grab it and return it.
   * Params:
   *      - int loc
   *
   * Returns:
   *      -integer
   */
  int popAt(int loc) {
    // Need to be able to traverse to find index
    Node *traverse = head;
    Node *pop = head;
    int index = 0;

    while (loc - 1 != index) {    //the location before doesnt equal we wont
      traverse = traverse->next;  //keep moving
      pop = pop->next;            
      index++;                    //increment index count to keep track
    }

    traverse->prev->next = traverse->next;//This and the next line
    traverse->next->prev = traverse;      //reattache the nodes
    return pop->data;                     //return data in pop
    delete pop;                           //free up the space

    size--;
  }
  /**
   * Public : int peakFront()
   *
   * Description:
   *   Just returns the data in the first node
   *    which is head.
   * Params:
   *      - none
   *
   * Returns:
   *      - integer
   */
  int peakFront() { return head->data; }
  /**
   * Public: int peakBack() 
   *
   * Description:
   *  We will look at the back of the list and 
   *  return it. 
   * Params:
   *      - nothing
   *
   * Returns:
   *      - integer
   */
  int peakBack() {
    Node *traverse = head;

    while (traverse->next) {     //traverse through the list
      traverse = traverse->next;
    }
    return traverse->data;       //found the data return it
  }
  /**
   * Public : int find(int val)
   *
   * Description:
   *  Put in a integer value and find that value in a given list 
   *  and find it. 
   * Params:
   *      -int val

   *
   * Returns:
   *      -integer
   */
  int find(int val) {

    int index = 0;            
    Node *traverse = head;

    while (traverse) {            //as long as we have traverse
      traverse = traverse->next;  //Keep going
      index++;                    //keep track of size of list
      if (traverse->data == val) {//if data equals value return it
        return index;
      } else if (traverse->data != val) {
        return -1;                //If not return negative one
      }
    }
  }
  /**
   * Public :int getSize()
   *
   * Description:
   *   Just returns the incremented size to the user.
   *   
   * Params:
   *      - nothing

   *
   * Returns:
   *      - integer
   */
  int getSize() { return size; }
  /**
   * Public : void print()
   *
   * Description:
   *  This will print to "test.out" the require output formate
   *  for the assignment. Prints the list with [a, b, c] required notation.
   * Params:
   *      - nothing
   *
   * Returns:
   *      -void
   */
  void print() {
    ofstream outfile;
    outfile.open("test.out", ios::app); //open outfile
    Node *traverse = head;

    outfile << "[";                     //add first square bracket
    cout << "[";                        //add first square bracket
    while (traverse) {                  //Until we no longer have traverse
      outfile << traverse->data;        //print data to outfile
      cout << traverse->data;           //print data to console
      traverse = traverse->next;        //keep going down the list
      if (traverse != NULL) {           //if traverse doesnt equal null
        outfile << ", ";                //add a comma and space
        cout << ", ";                   //add a comma and space
      }
    }
    outfile << "]" << endl;             //break out add last square bracket
    cout << "]" << endl;                //break out add last square bracket
  }
};

int main() {
  ofstream outfile;
  outfile.open("test.out");

  outfile << "Delton Hughes" << endl;
  outfile << "2/6/2023" << endl;
  outfile << "Fall 2143" << endl;
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

  int A[] = {11, 25, 33, 47, 51};
  Vector v2(A, 5);
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
  cout << x << endl;
  // 18

  x = v1.popRear();
  x = v1.popRear();
  x = v1.popRear();
  v1.print();
  // [18, 20, 25, 9, 11, 25, 27, 33]
  cout << x << endl;
  // 47

  x = v2.popAt(3);
  v2.print();
  // [9, 11, 25, 33, 47, 51, 63]
  cout << x << endl;
  // 27

  x = v2.find(51);
  cout << x << endl;
  // 5

  x = v2.find(99);
  cout << x << endl;
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
  // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18,
  // 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47,
  // 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
  outfile.close();
  return 0;
}