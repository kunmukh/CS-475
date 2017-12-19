// File: combinations.cpp
// Inclass exercise for 01/20/2017
#include <iostream>

// Function prototype goes here
int combinations(int group,  // received : total number of items in the group
		 int members);  // reveived: number of items in each subgroup


int main()
{
   using namespace std;

   int n, m;

   cout << "Enter the total number in the group: ";
   cin >> n;
   cout << "Enter the number in each subgroup: ";
   cin >> m;

  cout << "Number of combinations = " << combinations(n,m) << endl;

   return 0;
}

// Function definition goes here
int combinations(int group,  // received : total number of items in the group
		 int members) // reveived: number of items in each subgroup
{
  // Base Case Question -  versions of the problem which do not require recursion
  // when members = 1 and when members = group
  if (members == 1)
    return group;
  if (members == group)
    return 1;
  // smaller-Caller question - versions of the problem that are smaller
  // when group and members are one smaller , and when the group is one smaller

  // General case Question- how to use the smaller versio to get the result for the original version
  // add the two smaller-caller versions together
  return combinations (group -1, members-1)
    + combinations(group-1, members);
  

}
