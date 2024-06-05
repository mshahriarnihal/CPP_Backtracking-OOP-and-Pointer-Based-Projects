//Student's First Name: Mubasshir Al Shahriar
//Question Index: Assignment: Redo the 8 queens 1 dimensional array program with backtracking WITHOUT gotos.


#include <iostream>
using namespace std;


bool ok(int q[], int c)   // This function returns true if queen in column c is ok. It actually runs that 3 tests to check if a certain position in the column is suitable or not for queen. 
{
   for (int i=0; i<c; i++)  
   if(q[i]==q[c] || (c-i) == abs (q[c]-q[i]))  //checks if there is any other queen in the same row or up or down diagonal of a certain position.         
   {
      return false;
   }         
   return true;  
}


void print(int q[]) //This function will print the solved result both as 1D value and in a 2D shape. 
{
   static int SolCounter = 0;  //Keeps counting total number of solutions. 
   cout << "Solution No. " << ++SolCounter << endl;

   cout << "1D Output: ";    
   
   for (int i = 0; i < 8; i++)   
   {
      cout << q[i];    //prints the solved result in 1D format.
   }

   cout << "\n2D Chessboard Structure for the 1D Output: \n";

   for(int i = 0; i < 8; i++) 
   {
      for (int j = 0; j < 8; j++) 
      {
         if (q[j]==i)
         {
            cout << "1 ";    //this nested for loops & if statement is used to print 2D structure of chessboard with solved result, it will help to visualise the result as a chessboard.
         }
         else
         {
            cout << "0 ";
         }
      }
      cout << endl;
   }
   cout << endl;
}



int main() 
{
   int q[8] = {}, c = 0; // Initializes the array q to 0 and also initializes int variable c to 0 which will be used to represent the column in this program.
   q[c]=0;  //q[c] represents the row of chessboard in this program. Starts from the 1st row, 1st column

   while (c >= 0)  // This condition will end the loop if it backtrack from the first column.
   {
      c++;   // Moving to the next column.
      
      if (c==8)
      {
         print (q);   //If we've reached & passed the last column, that means we successfully found 1 set of solution. So, here calling the print function to print that found solution.
         c--;  //After printing, it will backtrack to start searching for another set of solution.
      }
      
      else                 //If we haven't reached the last column yet, then we will have to find a suitable position for the queen in this current column.
      {               
         q[c]=-1;          //This will set the value of row in the current column to -1 so that it can start searching for a suitable row from the very first row in the column.
      }

      
      while (c >= 0) 
      {
         q[c]++;  // Moving to the next row.

         if (q[c]==8)   
         {
            c--;    // If it reaches the last row of the column and can't find any suitable row for queen , it will backtrack. 
         }
     
         else if (ok (q, c))  // Otherwise, calling the ok function. If the ok function returns true, it means that certain row of the column is suitable to place queen.
         {
            break;   //  As it returns true, so, terminating the current while loop to go back to the beginning of the outer loop in order to go to the next column.
         }

      }

   }

return 0;

}