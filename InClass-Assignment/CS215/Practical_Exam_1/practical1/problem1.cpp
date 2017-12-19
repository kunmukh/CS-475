//Kunal Mukherjee
//Practical Exam
//Problem 1
//14th Feb, 2016

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int Ackermann(int m, int n);

int  main (int argc, char *argv[])
{
  if (argc != 3)
    {
      cout << "Usage: " << argv[0] << "Inputfile Outfile" << endl;
    }

  ifstream infile (argv[1]);

  if (!infile)
    {
      cout << "Error opening input file:" << argv[1] << endl;
      exit(1);
    }

  ofstream outfile (argv[2]);

   if (!outfile)
    {
      cout << "Error opening output file:" << argv[2] << endl;
      exit(1);
    }

   int m;
   int n;
   int ackermann;  

   while (infile >> m)
     {
       infile >> n;

       ackermann = Ackermann(m,n);

       outfile << "Ackermann(" << m << "," << n <<") is "
	       << ackermann << endl;
     }

   infile.close();
   outfile.close();
   return 0;
}

int Ackermann(int m, int n)
{
  if (m == 0)
    {
      return n + 1;
    }
  if ( m > 0 && n == 0)
    {
      return Ackermann(m-1, 1);
    }
  if ( m > 0 && n > 0)
    {
      return Ackermann(m-1, Ackermann(m, n-1));
    }
  else
    return 0;

	 
}

  



       
 
 
 
