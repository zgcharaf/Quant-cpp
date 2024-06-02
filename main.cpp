
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
int main() {
     
    cout << factorial(3) << endl;
    cout << EU_CALL_payoff(100, 10);
    cout << EU_PUT_payoff(10, 100); 
    return 0; 

}
 