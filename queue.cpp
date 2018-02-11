//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Antonio Monje
//Complier:  g++
//File type: queue implementation file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  count = 0;//the counter
  front = 0;//the front element
  rear = -1;//the rear element
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count == 0)
    return true;
  else
    return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count == MAX_SIZE)
    return true;
  else
    return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(isFull())
    {
      throw Overflow();
    }
  else
    {
      //new rear position
      rear = (rear + 1) % MAX_SIZE;
      //insert new item
      el[rear] = newElem;
      //update the count
      count++;
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if(isEmpty())
    {
      throw Underflow();
    }
  else
    {
      //get front item
      removedElem = el[front];
      //move front
      front = (front + 1) % MAX_SIZE;
      //update the count
      count--;
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if(isEmpty())
    {
      throw Underflow();
    }
  else
    {
      theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;//returns count to show the size
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
//ALGORITHM: for loop that starts at one until it reaches the count displaying the element and incrementing the front using a variable so that the front element doesnt change just the variable
void queue::displayAll()
{
  if(isEmpty())
    {
      cout << "[ empty ]" << endl;
    }
  else
    {
      int x = front;// x is used so that front doesnt change
      cout << "[";
      //for loop starting from one until it reaches the count incrementing by one each loop
      for(int i = 1; i <= count; i++)
	{
	  cout << " " << el[x] << " ";//display the element
	  x = (x + 1) % MAX_SIZE;//increment without changing front
	}
      cout << "]";
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{// ** comment a local variable
  el_t x = el[front];//x is used to add the front element that was deleted
  if(isEmpty())
    {
      throw Underflow();
    }
  else
    {
      remove(el[front]);//remove then you add to go around
      add(x);//adds the element that was deleted
    }
}
