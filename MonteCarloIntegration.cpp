
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
double MC(double lowBound, double upBound, int iterations){
    double totalSum=0;
    double randNum, functionVal; 
    int iter = 0; 
    

    while (iter < iterations - 1){
        randNum = lowBound + (float(rand())/RAND_MAX) * (upBound - lowBound); 
        functionVal = myFunction(randNum); 
        totalSum+=functionVal; 
        iter++;

    }
    double estimate = (upBound - lowBound)*totalSum/iterations; 
    return estimate; 

};

int main() {
    double lowerBound, upperBound; 
    lowerBound = 1; 
    upperBound=5; 
    int iterations=2000000; 
    double estimate = MC(lowerBound,upperBound, iterations);
    cout << estimate << endl;
    
    return 0; 

}
