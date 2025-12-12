//
//  StackADT.hpp
//  Honors Project
//
//  Written By: Caroline Lo
//  IDE: Xcode

#ifndef StackADT
#define StackADT

#include <stdio.h>

using namespace std;

template <typename T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
    };

    StackNode *top;     // Pointer to the stack top
    int length;

public:
   Stack(){ top = NULL; length = 0; } // Constructor
   ~Stack(); // Destructor

    // Stack operations:
   bool push(T item);
   T pop();
   T peek() { return top-> value; }
   bool isEmpty() { return length == 0; }
   int getLength() { return length; }
};

/*
  Member function push inserts the argument onto
  the stack.
 Input:
 - item
 Output
 - boolean (was successful)
*/
template<typename T>
bool Stack<T>::push(T item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}




/*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
  
  Output:
  - T (item removed)
*/
template<typename T>
T Stack<T>::pop(){
   T item = top->value;
   StackNode *temp = top;
   top = top->next;
   length--;
   delete temp;
   return item;
}


/*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*/
template<typename T>
Stack<T>::~Stack()
{
   while (top)
   {
      StackNode* temp = top;
      top = top->next;
      delete temp;
   }
}

#endif /* StackADT */
