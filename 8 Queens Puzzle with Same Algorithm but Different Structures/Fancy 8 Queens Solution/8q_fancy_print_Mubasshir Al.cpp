//Name: Mubasshir Al Shahriar
//Question Index: Assignment: Eight Queens with “Fancy Print” Chessboard:  8 queens - fancy print (still 1d, nested while loops)

#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c)                                 // Bool function named "ok" to be used in the main function to check if a certain position is suitable to place a queen. 
{
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)    // If there is already a queen in same row, column or up or down diagonal, the position is not suitable.
         return false;                                  // It returns false as the position is not good to place a queen.
   return true;                                         // Otherwise (if the position is suitable), it returns true.
}


void print(int q[])          // Void function named "print" to be used in the main function to print the solved result with fancy chessboard and fancy (black and white) queens. 
{         
   static int solution = 0;  // Counts the number of solutions.
   int i, j, k, l;
   typedef char box[5][7];   // "box" is now a data type: a 5x7 2D array of characters
   box bb, wb, *board[8][8]; // "bb" and "wb" are boxes (5x7 arrays) (respectively black and white boxes). "Board" is an 8x8 array of pointers to boxes.
                             // We don't have to clean up the board after printing as it's not static,
                             // So it'll be reinitialized the next time you call the function.

   // "bb" represents black box and "wb" represents white box. They each represent a square of the chessboard.
   // We only need to create one of each, since the chessboard can contain many pointers to the same box.
   for (i=0; i<5; i++)
      for (j=0; j<7; j++) 
      {
         wb[i][j] = ' ';
         bb[i][j] = '0';
      }
   
   // Now creating 2 more boxes to represent the black and white queens, by drawing a picture of each queen in the 2D array.
   static box bq = { {'0','0','0','0','0','0','0'},
                     {'0',' '      ,'0',' '      ,'0',' '      ,'0'},
                     {'0',' '      ,' '      ,' '      ,' '      ,' '      ,'0'},
                     {'0',' '      ,' '      ,' '      ,' '      ,' '      ,'0'},
                     {'0','0','0','0','0','0','0'} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,'0',' '      ,'0',' '      ,'0',' '      },
                     {' '      ,'0','0','0','0','0',' '      },
                     {' '      ,'0','0','0','0','0',' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

   // Fill board with pointers to bb and wb in alternate positions.
   for(i=0; i<8; i++)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)             
            board[i][j] = &wb;       // In a certain position, if the sum of row and column is even, that position (box) will be a white box. 
         else
            board[i][j] = &bb;       // If it is odd, then the box/square will be a black box.
   

   // Setting up the current solution on the chessboard by placing pointers to bq and wq in the appropriate squares & connecting solutions q[] with fancy queens (bq/wq) via pointer board.

   for(i=0; i<8; i++)
      if((i+q[i])%2 == 0) // According to the current solution, if the sum of row & column of a particular position where we'd need to place a queen is even,
                          // Then, we're placing wq (white queen) there. 
         board[q[i]][i] = &wq; 
      else
         board[q[i]][i] = &bq;  // And if the sum is odd, we're placing a black queen there.

   cout << "Solution #" << ++solution << ":\n ";

   cout << "1D Output: ";    
   
   for (int i = 0; i < 8; i++)   
   {
      cout << q[i];    // Prints the solved result in 1D format.
   }

   cout << "\n2D fancy chessboard structure with fancy black and white queens for the 1D solution: \n";
   
   // Printing upper border
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   // Printing the fancy chessboard
   for (i=0; i<8; i++)                        // for each board row
      for (k=0; k<5; k++) 
      {                                       // for each box row
         cout << char(179);
         for (j=0; j<8; j++)                  // for each board column
            for (l=0; l<7; l++)               // for each box column
                                              // board[i][j] is the box pointer in the ith row, jth column of the board.
                                              // *board[i][j] is the box being pointed to.
                                              // (*board[i][j])[k][l] is the kth row, lth column of the box.
               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      }

   // Printing lower border
   cout << " ";
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}


int main() 
{
   int q[8] = {}, c = 0;   // Initializes the array q to 0 and also initializes int variable c to 0 which will be used to represent the column in this program.
   q[0] = 0;               // q[c] represents the row of chessboard in this program. Starts from the 1st row, 1st column.

   while (c >= 0)          // This condition will end the loop when it backtracks from the first column.
   {
      c++;                 // Moving to the next column
      if (c > 7)           // If we have passed the last column, a solution is found.
      {          
         print(q);         // Calling the print function to print the found solution in fancy 2D structure.
         c--;              // Backtracks 
      }

      else q[c] = -1;      // If we haven't reached the last column yet, then it sets q[c] to -1 so in inner loop so that we can start q[c] from 0.

      while (c >= 0) 
      {  
         q[c]++;           // Moving to the next row
         if (q[c] > 7) 
            c--;           // If we reach the last row of the column and can't find any suitable row for queen , we'd need to backtrack.
 
         else              // Otherwise, we'd need to call the ok function.
            if (ok(q, c))  // If the ok function returns true, it means that certain row of the column is suitable to place queen.
               break;      // As it returns true, a queen is filled in the row, so, terminating the current (inner) while loop so that we can go to the next column.
      }

   }

   return 0;               // When outer while loop ends, that means we found all the possible solutions and printed fancy output of them. So, the program ends here.
}
