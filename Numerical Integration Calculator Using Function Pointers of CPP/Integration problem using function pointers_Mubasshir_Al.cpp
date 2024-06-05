//Student's First Name: Mubasshir Al, Last Name: Shahriar, CUNYFirst ID: 24398818
//Question Index: Assignment: Integration problem using function pointers 



#include <iostream>
using namespace std;

typedef double (*FUNC)(double);     //*FUNC is a pointer to a function that takes a double variable as input.

// (when you call f(x) it'll call whatever function you passed as the first parameter)


double integrate(FUNC f, double a, double b) //Here FUNC f determines the shape of the curve, double a and double b are lower and upper bound of definite integral.
                                             //It starts summing areas from a and finish sum to b (maximum value of the interval). 
                                             // It will use Riemann sum to estimate the area by dividing it into narrow rectangles and then summing up area of each of these rectangle.
{  
 
   double x = a + (0.0001 / 2);            //x represents the horizontal position of the rectangle of the Riemann sum.
   double width = 0.0001;   //I set the width of the rectangle to 0.0001. The smaller the width is, the better the approximation we'll get. 
   double sum = 0;
   
   while (x < b)          //This loop continues until we reach the upper limit while summing up the areas of the rectangles.
   {
      sum = sum + (f(x) * width);   //f(x) represents the height of rectangles, and width represents the width of rectangles. So, it determines and keep summing up the areas of rectangles.
      x = x + width;
   }
   return sum;          //Returns the total sum of areas of those rectangles. So, basically it's returning the desired value of the integration (area under the curve between x=a and x=b).
}


double line(double x)
{
   return x;
}

double square(double x)
{
   return x*x;
}

double cube(double x)
{
   return x*x*x;
}


int main() 
{
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   
   return 0;
}
