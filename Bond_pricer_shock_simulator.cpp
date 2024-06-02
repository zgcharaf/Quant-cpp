#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
using namespace std; 
//Author : Charaf ZGUIOUAR
double compundInterest(double P, double i, int n){
    double interest = P * pow(1+i, n) - P; 
    return interest; 
}

double priceBond(double n, double r, double c, double capital=100){ // n = duration, //r=yield //c=coupon in currency //capital in currency 
    long double result = 0; 
    for (int i =1; i <=n ; i++){
        if(i == n){
            result += (capital+c)/pow(1+r,i); 
            continue;
        };
        result += c/pow(1+r,i); 
    }
    return result;

}
double shockprice(double n, double r, double c, double capital=100, double percentage = 0){
    double p0 = priceBond(n, r, c, capital); 
    cout << "intial price "; 
    cout << p0 << endl; 
    double p1 =  priceBond(n, r*(1+percentage), c, capital);
    double sensitivity = ((p1-p0)/p0) *100;
    if (percentage >0 ){

        cout << "100bp increase in interest rates "; 
        cout << p1 << endl;
        cout << "for a "<< percentage*100  << " percent increase" << " the sensitivity " << sensitivity <<  endl;
    }else{
        cout << "100bp drop in interest rates "; 
        cout << p1 << endl;
        cout << "for a "<< percentage*100  << " percent drop"  << " the sensitivity " << sensitivity << endl;


    }
    
    
    return 0; 
}
int main() {

    vector <vector<double>> bonds = {
        {5, 0.05, 4, 100, -0.02}, 
        {4, 0.05, 4, 100, -0.02}, 
        {3, 0.05, 4, 100, -0.02}, 
        {2, 0.05, 4, 100, -0.02}, 
        {1, 0.05, 4, 100, -0.02}, 
    }; 

    int len = sizeof(bonds)/sizeof(double); 

    for(int i=0;  i < len; i++){
        cout << shockprice(bonds[i][0], bonds[i][1], bonds[i][2], bonds[i][3],bonds[i][4]) <<endl;
    }
     


}