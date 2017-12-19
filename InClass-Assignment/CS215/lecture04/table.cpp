// File: table.cpp
// Example of table formatting

#include <iostream>  // cout, endl
#include <cmath>     // pow()
#include <iomanip> // manipulator for output
using namespace std;

int main ()
{
  cout << left; // left-justified
  cout << setw(4) << "n" <<  "  " << setw(8) << "2^n" << endl;
  cout << setw(4) << "----" << "  " << setw(8) << "--------" << endl;
   for (int i = 0; i < 16; i=i+4)
     cout << setw(4) << i << "  " << setw(8) << pow(2,i) << endl;

   return 0;
}
