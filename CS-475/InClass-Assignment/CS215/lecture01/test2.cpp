#include<iostream>

int main(int argc, char*argv[])
{
  using namespace std;
  for (int i = 0; i < argc; i++)
    { cout << "arg[" << i << "]=" << argv[i] << endl;}
  return 0;
}
