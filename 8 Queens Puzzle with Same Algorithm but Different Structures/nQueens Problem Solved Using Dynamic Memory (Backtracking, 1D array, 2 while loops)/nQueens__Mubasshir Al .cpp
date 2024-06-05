//Name: Mubasshir Al Shahriar (Nihal)
//Question Index: Assignment: The n queens problem using dynamic memory. 


#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c) 
{
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)    // If there is already a queen in same row, column or up or down diagonal, the position is not suitable, so it will return false.
         return false;                                  
   return true;                                         // Otherwise (if the position passes all 3 tests, which means that certain position is suitable to place a queen), it returns true.
}


int nqueens(int n) 
{
 
   int* q = new int[n];                // Dynamically declaring an array of size n. Here I'm using the "new" operator to request the heap to dynamically allocate the memory. 
   q[0] = 0;
   int c = 0, solutionsnum = 0;        // "solutionsnum" represents the total number of solutions that exists to solve the nQueens puzzle.

      while (c >= 0)                   // This condition will end the loop when it backtracks from the first column, which means, when we'll find all possible solutions.
   {
      c++;                             // Moving to the next column.
      if (c > n-1)                     // If we have passed the last column, that means a solution is found.
      {          
         solutionsnum++;               // Incrementing the number of solutions as a solution is found which should be added to the total number solutions.
         c--;                          // Backtracks to start searching for another solution. 
      }

      else q[c] = -1;                  // If we haven't reached the last column yet, then it sets q[c] to -1 so in inner loop so that we can start q[c] from 0.

      while (c >= 0) 
      {  
         q[c]++;                       // Moving to the next row
         if (q[c] > n-1) 
            c--;                       // If we've reached the last row of the column and can't find any suitable row for queen , we'd need to backtrack.
 
         else                          // Otherwise, we'd need to call the ok function to check if current row is suitable.
            if (ok(q, c))              // If the ok function returns true, it means that certain row of the column is suitable to place queen.
               break;                  // As it returns true, a queen is filled there, so, terminating this inner while loop so that we can go to the next column to place a queen there.
      }

   }
   

   delete [] q;                        // Deallocating q by calling the delete [] operator. It deletes the array and allows to free up the memory to make it available for future use.
   
   return solutionsnum;                // Returns the total number of solutions for "n" queens problem .

}





int main() 
{

   int n = 12;

   cout << "Please enter a number to see how many sets of solution are possible with that number of queens in a chessboard: ";
   cin >> n;                                                                                   // Added this to let the user set the number of queens. The number must not be too large.
   cout << endl;

   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n"; // Calling the previously created "nqueens" function which returns total number of solutions.
                                                                                               // This function doesn't print the solutions, rather just returns total number of solutions.                 
   return 0;

}
   
