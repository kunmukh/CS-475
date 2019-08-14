#include <iostream>
#include <queue> // STL Queue ADT

int main()
{
  using namespace std;
  queue<int> que; //only has default constructor that creates a empty stack
  int n;

  cout << "Enter a positive intiger: ";
  cin >> n;

  for (int i = 0; i < n; i++)
    que.push(i);  
  cout << "Size: " << que.size() << endl;
  cout << "Change the front element to 99" << endl;
  que.front() = 99;

  cout << "Popping the stack" << endl;
  while (!que.empty())
    {
      cout <<  "popped: " << que.front() << endl;
      que.pop();
    }
  return 0;
}
