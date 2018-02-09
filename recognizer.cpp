#include<iostream>
#include<string>
using namespace std;

// CS421 HW1 Write a recognizer in C++ for L = {x | x is a binary number}.
// Your name:Antonio Monje

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

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout YES IN L or NO NOT IN L depending on what was returned.
int main()
{
  string input; 
  cout << "Enter a binary number please: " << endl;
  getline(cin, input);
  //check to see if the input is binary with the recognizer function
  //display if it's in L or not to the user
  if(recognizer(input) == true)
    {
      cout << input <<  " YES IN L" << endl;
    }
  else
    {
      cout << input << " NO NOT IN L" << endl;
    }
  return 0;
}
