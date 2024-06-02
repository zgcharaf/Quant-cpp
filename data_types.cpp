#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
using namespace std; 

int main() {
    double x = pow(1.7539, 0.0); 
    int n = (int) x; 
    cout << x << endl; 
    cout << n << endl; 

    int a = 123; 
    int t = 1; 
    bool tru = t;
    double d = a; 
    cout << d << endl;
    cout << a << endl;
    cout << t << endl;

    cout << tru << endl;

    cout << (long double)t/a << endl;
    
    const char* speech = "to be or not to be?";
    cout << speech << endl;

    int i = 3, j =  i++; 
    cout << j<< endl; 

    cout << (true || false) << endl; //True
    cout << (true && false) << endl; //False

    cout << ((true && false) || true )<< endl; 

    cout << (true && false || true) << endl;

    cout <<( 3*5==15 && ((7 * 3==33) ||( true!=false))) << endl;
    cout << ((7 * 3==33) ||( true==false)) << endl;

    signed int k = 3;
    unsigned int m = 5; 
    cout << k - m << endl;

    return 0;
}
