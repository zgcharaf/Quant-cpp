#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

double n (double x ){
    const double A = 1.0/std::sqrt(2.0*3.14);
    return A * std::exp(-x*x*0.5);
};
auto cndN = [](double x){
    return 0.5 * (1.0 - std::erf(-x/std::sqrt(2.0)));
};

template <typname V> 
 ComputedData <V> CallValues (const OptionData<V>& optData, const V& S){
    V K = std::get <0> (optData)
 }
int main(){
std::cout << cndN(100) << std::endl;
};