#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include "queue.h"
using namespace std;


// include queue.h or equivalent 
// CS421 HW1 Write a generator in C++ for L = {x | x is a binary number}.
// Your name:Antonio Monje
// Copy the recognizer function here from the other file
//  The recognizer function should return TRUE or FALSE                                                        
//  checking each character                                                                                    
//  to make sure it is 0 or 1. (leading 0's are allowed).                                                  
bool recognizer(string s)
{
  //iterate as long until you reach the length of the string                                              
  for(int i = 0; i < s.length(); i++)
    {                                                                                                           
      if(s[i] != '0' && s[i] != '1')//check to see if it's binary or not                                  
        {
          return false;
        }                                                                                                   
    }
  return true;
}


// main: It should create each string over E = {0,1,2} systematically                                          
//   (short to long) and pass each string to the recognizer function                                            
//   created in Part a).  Hint: use a queue to generate strings                                                 
//   Only those strings for which the recognizer returned TRUE                                                  
//   should be displayed.                                                                                       
//   Keeps on going until the queue overflows but the user can                                                  
//   terminate the program with control-C                                                                       
//   after 20 strings have been displayed.                                                                      
int main()
{
  int count = 0;
  queue Q1;
  Q1.add("0");
  Q1.add("1");
  Q1.add("2");
  string input;
  string token;
  //while loop will go on forever unless you terminate the program after 20 items are displayed or when the queue overflows from to many items. the queue size was set to 150 in queue.h.
  while(true)
    {
 //the try block checks the content of the queue with the recognizer function to see if they are binary or not.
      try
	{
	  Q1.remove(token);
	  //checks to see if the queue item removed was binary or not with recognizer function if yes display it
	  if(recognizer(token) == true)
	    {
	      cout << token << endl;
	      count++;
	    }
	  //if more then 20 binary numbers are displayed you can terminate the program
	  if(count == 20)
	    {
	      count++;
	      cout << "over 20 items have been checked enter exit to stop program\n";
	      cin >> input;
	      if(input == "exit" || input == "EXIT")
		{
		  cout << "Program Terminating...\n"; exit(1);
		}
	    }
	  //add more elements to be checked to the queue
	  Q1.add(token + "0");
	  Q1.add(token + "1");
	  Q1.add(token + "2");
	}
      //if the queue overflows or underflows display error message and terminate the program
      catch(queue::Overflow)
	{cerr << "Error: you have caused the queue to overflow. Program terminating...\n"; exit(1);}
      catch(queue::Underflow)
	{cerr << "Error: You have caused the queue to underflow. Program terminating...\n"; exit(1);}
    }
  return 0;
}
