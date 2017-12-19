// Function: write_vertical
// From Savitch, _Problem Solving with C++
// Prints the number n is the screen vertically with each digit on a 
// separate line.
// Assumes that n >= 0
// Uses an iterative solution
void write_vertical(int n)
{
    int tens_in_n = 1;
    int left_end_piece = n;
    while (left_end_piece > 9)
    {
        left_end_piece = left_end_piece/10;
        tens_in_n = tens_in_n * 10;
    }
    //tens_in_n is a power of ten that has the same number 
    //of digits as n. For example, if n is 2345, then 
    //tens_in_n is 1000.
 
    for (int power_of_10 = tens_in_n;
         power_of_10 > 0; 
	 power_of_10 = power_of_10 / 10)
    {
        cout << (n / power_of_10) << endl;
        n = n % power_of_10;
    }
}  // end write_vertical
