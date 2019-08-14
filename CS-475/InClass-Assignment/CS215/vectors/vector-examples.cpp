// Example of vectors

#include <iostream>
#include <vector> // vector<T>
#include <string>

void PrintVector (const std::vector<int> & vec); // passed the received-only
                                                 // object by const refrence
                                                 // for efficiency 
int main()
{
  using namespace std;
  
  //vector<T> is template class, T is a type parameter
  vector<int> intVec; // empty vector of interger
  vector<string> strVec; // empty vector of string

  // vectors know their size(length)
  cout << "Number of element in intVec: " << intVec.size() << endl;

  //add element to vector dynamically
  for (int i = 0; i < 5; i++)
    intVec.push_back(i*10); // add elemnt to end of the vector
  PrintVector(intVec);

  cout << "Number of element in intVec: " << intVec.size() << endl;
  cout << "The first element of intVec is: " << intVec.front() << endl;
  cout << "The last element of intVec is: " << intVec.back() << endl;

  intVec.pop_back();//remove the last element from vector
  PrintVector(intVec);
  
  cout << "Number of element in intVec: " << intVec.size() << endl;
  cout << "The last element of intVec is: " << intVec.back() << endl;


  intVec.clear(); //makes a vector empty
  cout << "NUmber of element in intVec: " <<intVec.size() << endl;
  PrintVector(intVec);  

  return 0;
}

void PrintVector (const std::vector<int> & vec)
{
  using namespace std;

  cout << "The vector size is: " << endl;
  for (int i = 0; i < vec.size(); i++)
    cout << "vec[" << i << "] = " << vec[i] << endl;
}

