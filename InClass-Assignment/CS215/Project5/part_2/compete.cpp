// File: compete.cpp
// The Compete is a 2-two player card game similar to the game 
// of War.
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Assignment: Programming Project 5 Date assigned: 3/31/2017
// Programmer: Kunal Mukherjee       Date completed:4/4/2017
//-------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <queue>


void AppendQueue (std::queue<int> &destination, std::queue<int> &source);
//REC'D and PASS'BK: destination and source

int main (int argc, char* argv[])
{
  using namespace std;
  
  if (argc != 2)
     {
      cout << "USAGE: " << argv[0] << " inputfile" << endl;
      return 0;
     }

   ifstream inFile(argv[1]);

   if (!inFile)
     {
      cout << "invalid input file" << endl;
      return 0;
     }

   int numGames; //number of games to be played
   int numCards; //the number of cards in each player
   char card; //the  cards in each players hand
   int result; // 0 = tie, 1 = player1 won, 2 = player2 won,
               //other = not finished
   int roundNumber; //the number of round
   int gameNumber = 0; //the game number
   
   inFile >> numGames;

   queue<int> player1; //the queue for the player1
   queue<int> player2; // the queue for player2
   queue<int> discard; // the discard pile

   // play until number of games specified by the user
   while (gameNumber < numGames)
     {
      // clear each players' pile, so that queue's are empty
      while (!player1.empty())
	 player1.pop();
      
      while (!player2.empty())
	 player2.pop();
      
      inFile >> numCards; //store the number of cards

      // add cards to each player 1's pile
      for (int i = 0; i < numCards; i++)
	{
	 inFile >> card;
	 // for cards with values 2 to 9, '2' = 2, '3' = 3, and so on
	 if (card <= '9') //convert the number and put it into the pile
	    player1.push(card - '0');
	 
	 // otherwise, T = 10, J = 11, Q = 12, K = 13, A = 14
	 //depending on the other cards also put them
	 else if (card == 'T')
	    player1.push(10);
	 else if (card == 'J')
	    player1.push(11);
	 else if (card == 'Q')
	    player1.push(12);
	 else if (card == 'K')
	    player1.push(13);
	 else
	    player1.push(14);
      }

      // repeat for player 2
      for (int j = 0; j < numCards; j++)
	{
	 inFile >> card;

	 if (card <= '9')
	    player2.push(card - '0');
	 
	 else if (card == 'T')
	    player2.push(10);
	 else if (card == 'J')
	    player2.push(11);
	 else if (card == 'Q')
	    player2.push(12);
	 else if (card == 'K')
	    player2.push(13);
	 else
	    player2.push(14);
      }

      // reset round number
      roundNumber = 1;

      // reset result
      result = 0;
      
      // increment game number
      gameNumber++;

      // clear the discard pile so that no card is left
      while (!discard.empty())
	 discard.pop();
      
      // play until someone runs out of cards
      while (true)
	{	 
	 // if players have same card then keep turning over cards
	 // until they don't have the same card,
	 //or a player is out of cards

	  //the player 1 card and player 2 card are the same and player 1 card
	  //pile is not empty
	  while (player1.front() == player2.front() && !player1.empty())
	    {
	      // place both cards in discard
	      discard.push(player1.front());
	      player1.pop();
	      discard.push(player2.front());
	      player2.pop();
	    }
	 	 
	 // player1's card is better and player 2 pile is not empty
	  if (player1.front() > player2.front() && !player2.empty())
	    {
	      // discard winner's card
	      discard.push(player1.front());
	      player1.pop();
	    
	      // discard loser's card
	      discard.push(player2.front());
	      player2.pop();
	    
	      // add discard pile to winner's pile
	      AppendQueue (player1, discard);
	    }
	 
	  // player2's card is better and player 1 is not empty
	  else if (player1.front() < player2.front() && !player1.empty())
	    {
	      // discard winner's card
	      discard.push(player2.front());
	      player2.pop();
	    
	      // discard loser's card
	      discard.push(player1.front());
	      player1.pop();
	    
	      // add discard to winner's pile
	      AppendQueue (player2, discard);
	    }
	 
	  // only player 1 is out of cards and player 2 wins
	  if  (player1.empty() && !player2.empty())
	    {
	      AppendQueue (player1, discard);
	      result = 2;
	      break; // game is over
	    }
	 
	 // only player 2 is out of cards and player 1 wins
	  else if (!player1.empty() && player2.empty())
	    {
	      AppendQueue (player2, discard);
	      result = 1;
	      break; // game is over
	    }
	 
	  // both are out of cards and it is a tie
	  else if (player1.empty() && player2.empty())
	    {
	      result = 0;
	      break; // game is over
	    }

	 // if game isn't over, go to next round
	 roundNumber++;
	 
      } // end of round loop

      // end of game
      if (result == 0)
	{
	  cout << "Game " << gameNumber << ": After " << roundNumber
	       << " round(s), the game ends in a tie" << endl;
	}

      else
	    cout << "Game " << gameNumber << ": After " << roundNumber
	      << " round(s), Player " << result << " wins" << endl;
      
   } // end of game loop

   return 0;
}


// Function: AppendQueue
// adds all items of one queue to another

void AppendQueue (std::queue<int> &dest,// REC'D/P'BACK: destination queue,
		  std::queue<int> &source)  //source queue
   // move items until source is empty  
{ 
  while(!source.empty())
    {
      dest.push(source.front());
      source.pop();
    }
}
