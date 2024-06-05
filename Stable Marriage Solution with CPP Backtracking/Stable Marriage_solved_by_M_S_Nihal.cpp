//Student's Name: Mubasshir Al Shahriar (Nihal)
//Question Index: Assignment: Stable Marriage - Backtracking with 2 while loops: You have n men and n woman, and their preference rankings of each other, and you need to match them up so that the total matching is “stable.”



#include<iostream>
using namespace std;

bool ok(int q[], int c)    //bool function named 'ok' to check if a woman can be assigned to a specific man by testing with 3 conditions. c refers to man, q[] refers to woman.
{ 
   static int mp[3][3] = { //men's preference table.

                            {0,2,1},  // Man #0's preferences (preference 0, the left-most one, is the most preferred woman and preference 2, the right-most one is the least preferred one)
                            {0,2,1},  // Man #1's preferences
                            {1,2,0}   // Man #2's preferences
 
                         }; 


   static int wp[3][3] = { //women's preference table.
 
                            {2,1,0},  // Woman #0's preferences (preference 0, the left-most one, is the most preferred man and preference 2, the right-most one is the least preferred one)
                            {0,1,2},  // Woman #1's preferences
                            {2,0,1}   // Woman #2's preferences

                         };
 

   for(int i = 0; i < c; i++)
   {

      if(q[c] == q[i])     //this checks if the same women is already married to another man.
         return false;     //if she is, then it returns false.
       
      if((mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) || (mp[i][q[c]] < mp [i][q[i]] && wp[q[c]][i] < wp[q[c]][c]))  
         return false;     
                           //here second and third condition checks if (Man #i) and (Man#c's wife) or (Man#c) and (Man#i's wife) has mutual greater preference.
                           //if any of those two pairs like each other more than their own partners, it will return false.
                           //lower the value of mp[][] or wp[][], greater their preference is, as preference 0 indicates the most preferred one and 2 refers to the least preferred one.
                           //mp[c][q[i]] tells us how much Man #c likes the woman from previous pair.
                           //mp[c][q[c]] tells us how much Man #c likes his own wife.
                           //wp[q[c]][i] tells us how much Man #c's wife likes Man #i.                           
                           //wp[q[c]][c] tells us how much Man #c's wife likes her own husband.
	                   //mp[i][q[i]] tells us how much Man #i likes his own wife. 
	                   //mp[i][q[c]] tells us how much Man #i likes Man #c's wife. 
	                   //wp[q[i]][i] tells us how much Man #i's wife likes Man #i. 
	                   //wp[q[i]][c] tells us how much Man #i's wife likes Man #c. 

   } 

   return true;            //if it passes all 3 conditions, it returns true.

}


void print(int q[])                                           //void function named 'print' to use in the main function to print the found result.
{
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";   //prints the number of solution. "\t" makes spaces equal to 1 tab, "\n" is same as endl; 

   for(int i = 0; i < 3; i++) 
      {
         cout << i << "      " << q[i] << endl;               //prints which man should be matched with which woman.
      }
    
   cout << endl;
    
}



int main() 
{
   int q[3] = {}, c = 0; // Initializes the int array q and int variable c, c represents men and array q[] represents woman, q[c] represents the woman assigned to man c.
   q[c] = 0;             //first assigning the woman #0 with man #0.

   while (c >= 0)        // This condition will end this outer while loop if it backtrack from c=0 (first man).
   {
      c++;               // moves to the next man to find perfect woman for him.
      
      if (c == 3)
      {
         print (q);      //If it has reached & found a woman for the last man (#2), which means successfully found 1 solution then it calls the print function to print that one solution.
         c--;            //After printing, it will backtrack to start searching for another set of solution.
      }
      
      else               //If it hasn't reached & find a woman for last man yet, then it will have to find a suitable woman for the current man (c).
      {               
         q[c] = -1;      //This will set the value of current woman (q[c]) to -1 so that it can start checking from the very first woman if she's a perfect match with the current man(c).
      }

      
      while (c >= 0)     //This inner while loop is used for the value of elements, which represents women in this program.
      {
         q[c]++;         // Going to test the next woman.

         if (q[c] == 3)   
         {
            c--;         // If it has tested all the women and can't find any suitable woman for current man , it will backtrack. 
         }
     
         else if (ok (q, c))  // Otherwise, calling the ok function. If the ok function returns true, it means that specific woman is a perfect match with the current man.
         {
            break;            //  As it returns true, so, it will terminate this inner while loop to go back to the beginning of the outer loop in order to progress the program.
         }

      }

   }

   return 0;

}