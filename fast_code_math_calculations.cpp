
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


double levy_pdf(double x, double mu, double c){
    if (x<= mu){
        return 0.0;
    }
    double n = sqrt( c /(2 * M_PI)) * exp(-c /(2* (x- mu)));
    double d = pow(x-mu, 1.5); 
    return n/d;
}

double levy_cdf(double x, double mu, double c){
    if (x <= mu){
        return 0.0;
    }
    return erfc( sqrt( c / ( 2 * ( x - mu ))));
}
double n_cdf (double x, double mean, double stdv){
    double variance = stdv*stdv; 
    double d = sqrt(2 * M_PI * variance); 
    double e = -((x-mean)*(x-mean))/(variance * 2); 
    return exp(e)/d;
}
double n_pdf (double x, double mean, double stdv){
    return 0.5 * (1+ erf((x-mean)/(stdv*sqrt(2)));
}




 int main() {
     
    cout << factorial(3) << endl;
    cout << EU_CALL_payoff(100, 10);
    cout << EU_PUT_payoff(10, 100) <<endl; 
    cout << cdf(2, 2, 2);
    return 0; 

}

