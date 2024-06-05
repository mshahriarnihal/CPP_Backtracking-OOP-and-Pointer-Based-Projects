//Author's Name: Mubasshir Al Shahriar (Nihal)
//Question Index: Assignment: Complete the "dumb" 8 queens program that we looked at in lecture. Use the 1 dimensional array representation.

#include <iostream>
using namespace std;

bool ok_func(int chbr[])  //creating a new bool function named "ok_func" that will take the 1D array and will run the tests to check if there is any queen in the same row,up diagonal or down diagonal. If it detect any queen, it will return false value, and if it passes all the test without finding any queen on those place, it will return true.

{
   for(int c = 7; c > 0; c--)
   {
        
      for (int i=0; i<c; i++)  
      if(chbr[i]==chbr[c] || (c-i) == abs (chbr[c]-chbr[i]))           
      {
         return false;
      }        
   }
   
   return true;
} 


void print(int chbr[8], int c)  //this void function will be mainly used to print the found 1D outputs in 2D chessboard structure.
{            
   cout << "Solution No. " << c << endl;  //this prints the numer of solutions
   cout << "1D Output: ";    
   
   for (int i = 0; i < 8; i++)   
      {
         cout << chbr[i];     //this is the 1d output values.
      }

   cout << "\n2D Chessboard Structure for the 1D Output: \n";

   for(int i = 0; i < 8; i++) 
   {
      for (int j = 0; j < 8; j++) 
      {
         if (chbr[j]==i)
         {
            cout << "1 ";    //this nested for loops and if statement here is used to print the 2D structure of the chessboard according to the found 1D values.
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



int main ()
{
 
   int chbr[8]={0}, counter = 0;   //here I initialized a 1d version of chessboard and declared the variable named 'counter' to keep the track of the number of solutions.

   for(int i0 = 0; i0 < 8; i0++)   //used 8 for loops (nested) here to set all the possible configurations of the chessboard with 8 queens
   {
      for(int i1=0; i1 < 8; i1++)
      {
         for(int i2 = 0; i2 < 8; i2++)
         {
            for(int i3 = 0; i3 < 8; i3++)
            {
               for(int i4 = 0; i4 < 8; i4++)
               {
                  for(int i5 = 0; i5 < 8; i5++)
                  {
                     for(int i6 = 0; i6 < 8; i6++)
                     {
                        for(int i7 = 0; i7 < 8; i7++)
                        {
                           chbr[0]=i0;   //assigned the values here, outer most for loop's i0 represents left most array element & inner most (i7) represents right most window of the array
                           chbr[1]=i1;
                           chbr[2]=i2;
                           chbr[3]=i3;
                           chbr[4]=i4;
                           chbr[5]=i5;
                           chbr[6]=i6;
                           chbr[7]=i7;

                           if(ok_func(chbr)) 
                           {                          //if the ok_func returns true, which means, if a certain position passes eligibility tests to place queen, the output will be printed.
                              print(chbr, ++counter);
                           }
 
                        }
                     }
                  }
               }
            }
         }
      }
   }           
    
   return 0;     //the program ends here.

}