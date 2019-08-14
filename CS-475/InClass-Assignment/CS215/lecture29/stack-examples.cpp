#include <iostream>
#include <stack> // STL stack ADT

int main()
{
  using namespace std;
  stack<int> stk; //only has default constructor that creates a empty stack
  int n;

  cout << "Enter a positive intiger: ";
  cin >> n;

  for (int i = 0; i < n; i++)
    stk.push(i);  
  cout << "Size: " << stk.size() << endl;
  cout << "Change the top element to 99" << endl;
  stk.top() = 99;

  cout << "Popping the stack" << endl;
  while (!stk.empty())
    {
      cout <<  "popped: " << stk.top() << endl;
      stk.pop();
    }
  return 0;
}
