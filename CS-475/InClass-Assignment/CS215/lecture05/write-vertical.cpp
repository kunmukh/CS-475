// File: write-vertical.cpp
// Inclass exercise for 01/20/2017

#include <iostream>

// Function prototype goes here
void write_vertical(int num);

int main()
{
   using namespace std;

   int n;

   cout << "Enter a positive integer: ";
   cin >> n;

   write_vertical(n);

   return 0;
}

// Function definition goes here
void write_vertical(int num)
{
  using namespace std;
  //Base-Case QUestion
  if (num < 10) // only one digit,  just print it out
    cout << num << endl;
  else
    {
      // smaller-Caller Question
      // recursive call on  divide by 10

      // General case Question
      //print the smaller version
      //then print the remainder
      write_vertical(num/10);
      cout << num%10 << endl;
    }
  
}
