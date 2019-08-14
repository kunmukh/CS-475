// File: maze.cpp
// Based on Case Study: Escaping from a Maze
// Dale, et al., C++ Plus Data Structures, 6/e, p. 481-494

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>  // usleep, system (Unix Standard Library)

const int MAZE_SIZE = 5;

// Function to create a maze grid
void CreateMaze (std::ifstream& inFile,           // REC'D/P'BACK: input file
		 char maze[MAZE_SIZE][MAZE_SIZE], // P'BACK: filled maze grid
                 int &maxRows, int &maxCols);     // P'BACK: # rows/cols filled

// Function to print a maze grid
void PrintMaze(const char maze[MAZE_SIZE][MAZE_SIZE], // REC'D: grid to print
	       int maxRows, int maxCols);             // REC'D: # rows/cols

// Function to try to find path to exit staring at [row][col]
bool TryToEscape (char maze[MAZE_SIZE][MAZE_SIZE], // REC'D/P'BACK: maze grid
		  int row, int col,                // REC'D: start location
		  int maxRows, int maxCols);

// Recursive helper function that tries to find path in each direction

void Try(char maze[MAZE_SIZE][MAZE_SIZE],  // REC'D/P'BACK: maze grid
	 int row, int col,                 // REC'D: start location
	 bool& free,                       // P'BACK: result status
	 int maxRows, int maxCols);

int main(int argc, char *argv[])
{
   using namespace std;

   if (argc != 2)
   {
      cout << "Usage: " << argv[0] << " mazefile" << endl;
      exit(1);
   }
   
   ifstream inFile (argv[1]);
   if (!inFile)
   {
      cout << "Error: unable to open mazefile" << endl;
      exit(1);
   }
   
   char maze[MAZE_SIZE][MAZE_SIZE];  // maze grid
   int maxRows;		             // number of rows filled
   int maxCols;		             // number of columns filled
   CreateMaze (inFile, maze, maxRows, maxCols);
   PrintMaze (maze, maxRows, maxCols);
   
   int row, col;       // starting position indexes
   bool free = false;  // true if escaped the maze, false otherwise

   // Ask user for starting location
   cout << "\nEnter row (1-" << maxRows << ") and col (1-" << maxCols
	<< ") of starting position: ";
   cin >> row >> col;
   
   // Try to find a path to exit from [row][col]
   // Note: don't need to pass maxRows and maxCols, since the grid
   // border prevents going off the grid, assume row, col are valid indexes
   if (TryToEscape(maze, row, col, maxRows, maxCols))
      cout << "\nFree" << endl;
   else
      cout << "\nTrapped" << endl;

   maze[row][col] = 'S';  // mark the starting location for printing
   PrintMaze(maze, maxRows, maxCols);

   return 0;
}

void CreateMaze (std::ifstream& inFile, char maze[MAZE_SIZE][MAZE_SIZE],
                 int &maxRows, int &maxCols)
{
   using namespace std;
   int rowIndex, colIndex;
   inFile >> maxRows >> maxCols;

   string row;
   // Read each row from the file
   for (rowIndex = 1; rowIndex <= maxRows; rowIndex++)
   {
      inFile >> row;
      // Set left border character
      maze[rowIndex][0] = '+';
      // Copy row to maze grid
      for (colIndex = 1; colIndex <= maxCols; colIndex++)
	 maze[rowIndex][colIndex] = row[colIndex-1];
      // Set right border character
      maze[rowIndex][maxCols+1] = '+';
   }

   // Set top and bottom border characters
   for (colIndex = 0; colIndex <= maxCols+1; colIndex++)
   {
      maze[0][colIndex] = '+';
      maze[maxRows+1][colIndex] = '+';
   }
}

void PrintMaze(const char maze[MAZE_SIZE][MAZE_SIZE], int maxRows, int maxCols)
{
   using namespace std;
   int rowIndex, colIndex;
  
   cout << "\nMaze" << endl;
   // For each row
   for (rowIndex = 1; rowIndex <= maxRows; rowIndex++)
   {
      // Print each character in a row
      for (colIndex = 1; colIndex <= maxCols; colIndex++)
	 cout << " " << maze[rowIndex][colIndex];
      cout << endl;
   }
}

bool TryToEscape (char maze[MAZE_SIZE][MAZE_SIZE], int row, int col,
		  int maxRows, int maxCols)
{
   bool free = false;  // initialize for first call
   // call recursive helper function
   Try (maze, row, col, free, maxRows, maxCols);  
   return free;
}

// Helper recursive function to try to find path to exit from [row][col]

void Try(char maze[MAZE_SIZE][MAZE_SIZE], int row, int col, bool& free,
	 int maxRows, int maxCols)   // Passed back : status of path, true if found exit
{
   system ("clear"); // only works in Unix
   PrintMaze(maze, maxRows, maxCols);
   usleep(1000000);  // .1 sec, only works in Unix

   // Base case:  path is blocked, just return
   if ((maze[row][col] != '*') && (maze[row][col] != '+'))
   {
      // Base case: found the exit, set free to true
      if (maze[row][col] == 'E')
	 free = true;
      else
      {
	 // General case: mark this pace and possibiy try each direction
	 // Mark this place
	 maze[row][col] = '*';

	 // Smaller caller: change row/col index by one
	 // Try down
	 Try (maze, row+1, col, free, maxRows, maxCols);
	 if (!free)  // still looking
	    // Try up
	    Try (maze, row-1, col, free, maxRows, maxCols);
	 if (!free)  // still looking
	    // Try right
	    Try (maze, row, col+1, free, maxRows, maxCols);
	 if (!free) // still looking
	    // Try left
	    Try (maze, row,col-1, free, maxRows, maxCols);
	 // Tried all directions, but not part of path to exit, so unmark
	 if (!free) 
	    maze[row][col] = 'O';

	 //if (maze[row][col] == 'E')
	 // free = true;
	 // else if (maze[row][col] == 'O')
	 //{
	 //   mark the cell as visited
	 //   maze[row][col] = '*';
	 // try to go each direction
	 // try going up
	 // Try (maze, row-1, col, free);
	 // try going left
	 // if (!free) // path not found
	 // Try (maze, row, col-1, free);
	 //try going down
	 //if (!free) // path not found
	 // Try (maze, row+1, col, free);
	 // try going right
	 // if (!free)
	 // Try (maze, row, col+1, free);
	 //} // if neither then its a wall or visited cell, so just return
      }
   }
}
