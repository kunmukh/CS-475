// File: cipher.cpp
// Kunal Mukherjee
// cs 215
// Jan 15, 2017

#include<iostream> 
#include<fstream> 
#include<cstdlib>


int main (int argc, char * argv[]) 
{
   using namespace std;  

   // 1. Check for correct number of arguments
   if (argc != 4)
     {
       cout << "Usage: " << argv[0] << " inputfile outfile integer " << endl;
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
int shift = atoi(argv[3]);  //Convert the string into an integer
 if (shift < 0 || shift > 25 )
     {
       cout << argv[3] << " should be more than 0 " << endl;
       exit(1);
     }

   
   // 3. Copy one character at a time by reading a char until stream fails (usually EOF)
     
   char ch;
   while (infile.get(ch))  // when read goes past the end
                           //, the stream becomes invalid ==> false
   {
   
   //    3.1 Write char to output file
     if ( ch >= 'a' && ch <= 'z')  //Check to see if the chracter is a lower or uppercase letter
       {
	 ch = (((ch - 'a') + shift) % 26) + 'a';  // Deciphers the text
     outfile << ch;
   }

     else if ( ch >= 'A' && ch <= 'Z')
       {
	 ch = (((ch - 'A') + shift) % 26) + 'A';
     outfile << ch;
   }
     else
       {
	 outfile << ch;
       }    
   }

     // 4. Close files
   infile.close();
   outfile.close();

   return 0; 
} // end main
