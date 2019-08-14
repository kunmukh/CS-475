#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype> //tolower, isalpha

int main()
{
  using namespace std;
  string phrase;
  stack<char> stk;
  queue<char> que;

  cout << "Enter a phrase: ";
  getline(cin, phrase);

  for (int i = 0; i < phrase.length(); i++)
    {
      //put the letter at index i into stack and queue
      char ch = tolower(phrase[i]);
      //
      if(isalpha(ch))
	{
	  stk.push(ch);
	  que.push(ch);
	}
    }

  bool palindrome = true;

  while (palindrome && !que.empty())
    {
      if (stk.top() == que.front()) //a match
	{
	  stk.pop();
	  que.pop();
	}
      else
	palindrome = false; // not a match, so not a palindrome
    }

  if (palindrome)
    cout << "The phrase is a palindrome" << endl;
  else
    cout << "The phrase is not a palindrome" << endl;

  return 0;
}
