/*****************************************************************************
*                    
*  Author:           Prof. Griffin (Commented by Delton Hughes)
*  Email:            dlhughes0129@my.msutexas.edu
*  Label:            A03
*  Title:            Proper Program Commenting
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        This program
* 
*  Usage:
*        how to use the program if necessary
* 
*  Files:   main.cpp
*           test.out
*           README.md
*****************************************************************************/
#include <iostream>
#include <fstream>

using namespace std; 

struct Node {
  
}; 
class Vector {
  private: 
  Vector(int *A, int size)
  
  
  public:
  
  void inOrderPush(int Val){

  
  }
  int popFront(){
    
  }

  int popRear(){
    
  }

  void pushFront(int Val){
    
  }

  void pushRear(Vector V2){
    
  }

  int popAt(int location, int val){
    
  }
   

  void find(){
    
  }

  void print (){
    
  }
};
int main() {
  
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
//v2.inOrderPush(27);
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

v3.pushFront(v2);
v3.print();
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

Vector v4("input.dat");
v4.pushRear(v3);
v4.print();
// [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
  return 0; 
}