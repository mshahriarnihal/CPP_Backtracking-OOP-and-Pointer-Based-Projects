//Student's Name: Mubasshir Al Shahriar
//Question Index: Assignment: 8 numbers in a cross - Backtracking with 2 while-loops.


#include <iostream>
#include <cmath>
using namespace std;


void print(int q[])                                         //this function will be used in the main to print the result as a cross shape with 8 with numbers.
{
   static int solnum = 0;  
   cout << "Solution #: " << ++solnum << endl << endl;      //counts and print the numbers of solutions.
   cout << " "  << q[1] << q[4] << endl;
   cout << q[0] << q[2] << q[5] << q[7] << endl;
   cout << " "  << q[3] << q[6] << endl;
   cout << endl;
}


bool ok(int a[8], int b)  //this is the ok function to check if a certain number in a certain position is suitable with the 2 conditions of the problem.
{
   static int ha[8][5] = {                     //this is helper array, it will be used to check the numbers in adjacent boxes of a certain position. 
                            {-1,-1,-1,-1,-1},
                            { 0,-1,-1,-1,-1},
                            { 0, 1,-1,-1,-1},
                            { 0, 2,-1,-1,-1},
                            { 1, 2,-1,-1,-1},
                            { 1, 2, 3, 4,-1},
                            { 2, 3, 5,-1,-1},
                            { 4, 5, 6,-1,-1} 
                         };
 
 
 
   for(int i = 0; i < b; i++) 
   {
      if (a[i] == a[b])                        //it will check and make sure that it assigns a number (which is b in this function) in a position which has not been used already.
         return false;                         //if it is then it returns false. 
   }


   int j = 0;
   while(ha[b][j] != -1)                       // -1 is like a sentinel here, once it finds the value -1, the while loop terminates and it goes to the next row of the helper array.
   {

      if(abs(a[b] - a[ha[b][j]]) == 1)         //it checks if the number and other number(s) in it's adjacent squares are consecutive.
         return false;
         j++;     
   
   }
   
   return true;                                //if the number passes those 2 tests, which means the number is suitable for the position, then it returns true.

}


int main() 
{
   int q[8] = {0}, c = 0;  //here c represent the serial numbers of the boxes/squares and q[c] represent the values (numbers 1-8) put in the boxes. 
   
   q[c]=1;                 //first starting by assigning the value of the first (box no. 0) to 1. 
    
   while(c >= 0)           //this outer while loop will let the program to end when the value of c will be -1, which means when it will find all the possible solutions.
   {
      c++;                 //going to the next square/box.

      if(c == 8)           //it will call the print function to print the result when one solution set will be found.
      {
         print(q);
         c--;              //after printing the solution, it goes for backtracking to find another solution.
      }
            
      else                 
      {               
         q[c] = 0;         //if haven't found a complete solution yet, it will start checking from number 0 that which number can be assigned to the current square.
      }
      
      while(c >= 0)        //inner while loop.s
      {        
         q[c]++;           //goes to the next number. 
         
         if(q[c] == 9)     //check if it already has checked all the numbers (1-8) for current position.
         {
            c--;           //if it already has checked all numbers and none of them passed the tests, it backtracks to previous position.
         }
     
         else if(ok(q, c))
         {
            break;         //if the number passes (ok function returns true), then this inner while loop terminates, keeps the number assigned, and goes to next box (in outer while loop).
         }

      }

   }
   
return 0;

}