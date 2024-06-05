//Writer's Name: Mubasshir Al Shahriar (Nihal)
//Question Index: Assignment: Non-recursive Towers of Hanoi (Using Vector)


#include <iostream>
#include <vector>
using namespace std;

int main() 
{
   vector<int> t[3];  //Initializing the vector t which gonna represent the 3 towers.
   int n;
   cout << "Please enter the total number of rings you want to move: ";
   cin >> n;
   cout << endl;

   int firstpriority = 0, secpriority = 0;  //Which tower will be our priority to make as "to" tower will depend on whether the total number of rings is even or odd.
   
   if(n % 2 == 0)
   {  
      firstpriority = 2, secpriority = 1;  //If total number of rings is even, we'd need to move the rings counter-clock wise. 
                                           //So, the priority tower should be the next next tower,which means (from + 2). So, the first priority will be 2, 1 will be second priority. 
       
   }
   
   else
   {
      firstpriority = 1, secpriority = 2;  //If n is odd, then we'd need to move them clock wise. So, first priority will be 1 (from + 1). 2 (from + 2) will be our second priority then.
   }


   int from = 0, to = firstpriority, candidate = 1, move = 0; //from=0, because on first move we move ring1(cand) from tower1(initial 'from' tower) to 'to' tower(depends on who's priority) 

   // Initialize the towers
   for(int i = n + 1; i >= 1; --i)
      t[0].push_back(i);

   t[1].push_back(n+1);
   t[2].push_back(n+1);

   while (t[1].size() < n+1) //While t[1] doesn't contain all of the rings.
                             //It will contain all the rings correctly when the solution will be found. Then size of t[1] will be equal to n+1 and this while loop will be terminated. 
   { 
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
      //char (0 + 'A') prints "A", char (1 + 'A') prints "B." This was used here to represent the 3 towers as tower "A", "B" and "C." 


   t[to].push_back(t[from].back()); //This will move the ring from the top of the "from tower" to the top of the "to tower" (first copy it, then delete it from the "from tower")
   t[from].pop_back();              //When we're moving the ring from the "from tower" to "to tower", we're actually copying it. After that, here it deletes that ring from the "from tower" 




   if (t[(to+1)%3].back() < t[(to+2)%3].back())  //The next "from tower" will be the  the tower with the smallest ring that has not just been moved (on the last move).
   {
      from = (to + 1) % 3;
   }

   else
   {
      from = (to + 2) % 3;
   }


   //The next/new "candidate" will be the ring on top of the t[from] tower (selected "from tower" for that move).
   candidate = t[from].back();

  //New "to towwer" will be the closest tower(firstpriority) on which candidate can be placed.This means the next tower which has the first priority (Depending on whether n is odd or even)


   if (t[(from + firstpriority) % 3].back() > candidate)
      to = (from + firstpriority) % 3;                   //If the tower which has the first priority/closest is suitable to place the candidate, then that tower will be the new "to tower."


   else
      to = (from + secpriority) % 3;    //If the tower which has first priority isn't suitable to receive "candidate" ring, then the new "to tower" will be the tower with second priority. 
   
   }                    
                                        //This loop will be continued until all the rings are moved to the tower B correctly. After that's done, the loop ends and the program ends. 

   return 0;

}