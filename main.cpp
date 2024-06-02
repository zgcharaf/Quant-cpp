
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std; 
//Author : Charaf ZGUIOUAR
int factorial(int n){
    if (n == 0){
        return 1; 
    }
    return n * (factorial(n-1)); 

}
double EU_CALL_payoff(double S, double K){
    return S>K ? (S-K) : K;
}; 
double EU_PUT_payoff(double S, double K){
    return S<K ? (K-S) : K;
}; 



double n_pdf(double mean, double x, double std){
    double variance =  pow(std,2);
    double d = sqrt( 2 * variance * M_PI); 
    double e = -((x-mean)*(x-mean))/(2*variance);
    return exp(e)/d;
}
double cdf(double x, double mean, double std){
    return 0.5*(1+erf((x-mean)/(std*sqrt(2))));
}
 
 int main() {
     
    cout << factorial(3) << endl;
    cout << EU_CALL_payoff(100, 10);
    cout << EU_PUT_payoff(10, 100) <<endl; 
    cout << cdf(2, 2, 2);
    return 0; 

}
