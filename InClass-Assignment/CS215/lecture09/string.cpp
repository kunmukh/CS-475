#include<string>
#include<iostream>

int main()
{
  using namespace std;

  string word1 = "hot", word2 = "dog";
  string word3;
  
  //concatenation
  word3 = word1 + word2;
  
  //output
  cout << word1 << " + " << word2 << " = " << word3 << endl;
  
  //Accesing individual chracter
  cout << "First letter in "  << word1 << " is " << word1[0] << endl;
  cout << "Last letter in " << word1 << " is "
       << word1[word1.length()-1] << endl;
  cout << "First letter in " << word2 << " is " << word2.at(0) << endl;
  cout << "Last letter in" << word2 << " is "
       << word2.at(word2.length()-1) << endl;
  
  //input
  cout << "Enter a word: ";
  cin >> word1;
  cout << word1 << " was entered" << endl;
  // comparisons
  if (word1 == word2)
    cout << word1 << " == " << word2 << endl;
  if (word1 < word2)
    cout << word1 << " < " << word2 << endl;
   if (word1 > word2)
    cout << word1 << " > " << word2 << endl;

   //find
   size_t position = word3.find("dog");
   if (position != string::npos) //string::npos is value of not found
     cout << "dog starts at index " << position << " in " << word3 << endl;

  
  cout << "Enter a line: ";
  cin.ignore(); //disgard teh next character in the stream
  getline(cin, word2);
  cout << word2 << " was entered" <<endl;

  
  
  return 0;
}
