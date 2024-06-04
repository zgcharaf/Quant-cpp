#include "binomialmodel.h"
#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std; 
//Author : Charaf ZGUIOUAR
 
 int main() {
    double S0, r, u, d, p, q, n, R, t; // t time to expiration in years, r the annual interest rate, n = number of periods in the binomial tree
    u = 1.05;
    S0 = 100;
    d = 1/u; 
    r = 0.0374; 
    t=5; 
    n=20;

    R =  1+(r * t/n) ;

    p = P (u, d, R); 
    q = 1 - p; 
    vector<vector<double>> prices(n + 1);
    prices[0].push_back(S0);
 
    if (r >= u || u <= d ){ 
        cout << "Cannot accept those values as that would allow aribitrage" << endl;
    };
    for (int i = 0; i < n; ++i) {
        int elements = i + 2;
        prices[i + 1].resize(elements);
        prices[i + 1][0] = S(prices[i][0], u, d, 1, 1);
        prices[i + 1][1] = S(prices[i][0], u, d, 1, 0);
        for (int j = 2; j < elements; j++) {
            
            prices[i + 1][j] = S(prices[i][j - 1], u, d, 1, 0);
        }
    }

    // Output the binomial tree
    for (int i = 0; i <= n; ++i) {
        for (size_t j = 0; j < prices[i].size(); ++j) {
            cout << prices[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}

