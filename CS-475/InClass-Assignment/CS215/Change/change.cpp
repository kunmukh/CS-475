//Kunal Mukherjee
//Homework 2
//18th Jan, 2017
// Dr.Hwang

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void compute_change (int cent , int &dollar, int &quarter, int &dime, int &penny);
int main (int argc, char * argv[]) 
{
   // 1. Check for correct number of arguments
   if (argc != 3)
     {
       cout << "Usage: " << argv[0] << " inputfile outfile " << endl;
       exit(1);
     }
   
   // 2. Open files and check for success
   ifstream infile (argv[1]);             // input file stream
   if (!infile)                           // streams convert to boolean: true means valid
                                          //                             false means invalid
     {
       cout << "Error opening input file: " << argv[1] << endl;
       exit(1);
     }
   
   ofstream outfile (argv[2]);             // outfile file stream
   if (!outfile)                            // streams convert to boolean: true means valid
                                            //                           false means invalid
     {
       cout << "Error opening output file: " << argv[2] << endl;
       exit(1);
     }

   outfile << setw(10) << "Amount" << setw(10) << "Dollars" << setw(10) << "Quarters" << setw(10) << "Dimes" << setw(10) << "Pennies" << endl;
   outfile << endl;
   
   int  cent, dollar, quarter, dime, penny;

   while (infile >> cent)
	 {     
	   compute_change ( cent , dollar, quarter, dime, penny);	   
	   outfile << setw(10) << cent << setw(10) << dollar << setw(10) << quarter << setw(10) << dime << setw(10) << penny << endl;
	   
	 }
       // }    


       infile.close();
       outfile.close();

       return 0; 

       }

   void compute_change (int cent , int &dollar, int &quarter, int &dime, int &penny)
   {
     dollar  = cent  / 100;
     int remaning_quarter = cent  % 100;
     quarter = remaning_quarter / 25;
     int remaining_dime = remaning_quarter % 25;
     dime = remaining_dime / 10;
     int remaining_cent = remaining_dime % 10;
     penny = remaining_cent;
   }
     
   
   

