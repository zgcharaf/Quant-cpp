
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std; 
//Author : Charaf ZGUIOUAR

double myFunction(double x ){
    return ((pow(x, 2))+(pow(x/2, 3)) + (x));
};
double MC(double lowBound, double upBound, int iterations, double statsArray[]){
    double totalSum=0;
    double randNum, functionVal; 
    int iter = 0; 
    double TSS = 0; //total sum squared 
    

    while (iter < iterations - 1){
        randNum = lowBound + (float(rand())/RAND_MAX) * (upBound - lowBound); 
        functionVal = myFunction(randNum); 
        totalSum+=functionVal; 
        TSS += pow(functionVal, 2); 
        iter++;

    }
    double estimate = (upBound - lowBound)*totalSum/iterations; 
    double expected = totalSum/iterations; 
    double expectedSquare = TSS/iterations; 
    double std = (upBound-lowBound) * pow( (expectedSquare - pow(expected, 2) )/(iterations -1),0.5); 

    statsArray[0] = estimate; 
    statsArray[1] = std;
    


    return estimate; 

};

int main() {
    double lowerBound, upperBound; 
    lowerBound = 1; 
    upperBound=5; 
    int iterations; 
    double stats[2];
    
    for (int i ; i <20; i++){
        iterations = 2 * pow(4,i);
        double estimate = MC(lowerBound,upperBound, iterations, stats);
        printf("Estimate for %.1f -> %.1f is %.3f, STD = %.4f, (%i iterations)\n",
			lowerBound, upperBound, stats[0], stats[1], iterations);

    }
    
    return 0; 

}
//Estimate for 1.0 -> 5.0 is 4.284, STD = 4.2839, (2 iterations)
// Estimate for 1.0 -> 5.0 is 68.335, STD = 17.9030, (8 iterations)
//Estimate for 1.0 -> 5.0 is 60.174, STD = 8.1791, (32 iterations)
//Estimate for 1.0 -> 5.0 is 75.499, STD = 4.5144, (128 iterations)
//Estimate for 1.0 -> 5.0 is 71.390, STD = 2.1652, (512 iterations)
//Estimate for 1.0 -> 5.0 is 72.945, STD = 1.1075, (2048 iterations)
//Estimate for 1.0 -> 5.0 is 73.710, STD = 0.5583, (8192 iterations)
//Estimate for 1.0 -> 5.0 is 73.064, STD = 0.2786, (32768 iterations)
//Estimate for 1.0 -> 5.0 is 72.757, STD = 0.1386, (131072 iterations)
//Estimate for 1.0 -> 5.0 is 72.804, STD = 0.0695, (524288 iterations)
//Estimate for 1.0 -> 5.0 is 72.877, STD = 0.0348, (2097152 iterations)
//Estimate for 1.0 -> 5.0 is 72.813, STD = 0.0174, (8388608 iterations)
//Estimate for 1.0 -> 5.0 is 72.856, STD = 0.0087, (33554432 iterations)
//Estimate for 1.0 -> 5.0 is 72.839, STD = 0.0043, (134217728 iterations)
//Estimate for 1.0 -> 5.0 is 72.833, STD = 0.0022, (536870912 iterations)
//So as expected a 4-fold increase in the sample size produced a 2-fold decrease in the estimator’s error!
//Monte Carlo Integration retains the 1/sqrt(n) error scaling regardless of the number of dimensions of the integral, making it ideal for high-dimension scaling.
//
//