
#include <iostream>
 #include <cmath>

using namespace std; 
//Author : Charaf ZGUIOUAR

double P(double u, double d, double R ){
    return (R - d)/(u - d);
}
double S(double S0, double  u, double d, int n, int k){
    return S0*pow(u, k)*pow(d, n-k); 
}
  