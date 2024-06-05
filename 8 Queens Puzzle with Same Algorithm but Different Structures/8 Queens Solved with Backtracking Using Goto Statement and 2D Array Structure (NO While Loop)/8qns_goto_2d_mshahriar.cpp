//Author: Mubasshir Al Shahriar (Nihal)
//Question Index: Assignment-01: 8 Queens - 2 Dimensional Array Program with Backtracking, GOTO 


#include <iostream>
using namespace std;

int main() 
{

    int chbr[8][8]={0}, r=0, c=0, solutionnum=0;  //here I initialized a 8x8 chessboard first, then declared some variables I'll need for this program.
    
    chbr[0][0]=1;  //assigning the first queen at first row, first column.
    
    nc: c++;
    if(c==8) goto print;  //this if condition will be true only when it find a solution, then it needs to print the result.
    
    r=-1;  //need to set r=-1 so it can start looking from r=0 (first row).
    
    nr: r++;
    if (r==8) goto backtrack;  //as this if condition will be true only when there's no more suitable row in the current column to place a queen and need to backtrack.
    
    //row test
    for (int i=0; i<c; i++)  
    if(chbr[r][i]==1) goto nr;  //if there is already a queen in the same row, it will make the program jump to nr: label.
    
    
    //upper diagonal test
    for (int i=1; (r-i)>-1 && (c-i)>-1; i++)
    if (chbr[r-i][c-i] == 1) goto nr;   //if there is already a queen in the up diagonal, it will make the program jump to nr: label.
    
    //lower or down diagonal
    for (int i=1; (r+i)<8 && (c-i)>-1; i++)
    if (chbr[r+i][c-i] == 1) goto nr;  //if there is already a queen in the down diagonal, it will make the program jump to nr: label.
    
    //after passing 3 of those tests
    chbr[r][c] = 1; //placing a queen on the suitable position that passed all 3 tests and going next column.
    goto nc;
    
    backtrack: c--;
    if (c == -1)   // this condition will be true when we found all the possible solutions/configurations match with the conditions to place queens, so we need to terminate program.
    {
        return 0;
    }        
    
    r = 0;
    
    while (chbr[r][c] != 1)
    {
        r++;            
    }

    chbr[r][c] = 0;   //finds the previously placed queen and removes it by resetting the value to 0.
    
    goto nr;   //again starts checking next suitable place for queen.
    
    print:     //now I am going to write code that will print the found result in output.
  
    cout << "Solution No. " << ++solutionnum << endl << endl;
  
    for(int r=0; r<8; r++) 
    {
        for(int c=0; c<8; c++) 
        {
            cout  << chbr[r][c] << "  ";
        } 
        cout << endl;
    
    }    
    
    cout << endl;
   
    
    goto backtrack;  //after successfully printing one suitable configuration, need to start backtracking to find another suitable solution.

    return 0;

}