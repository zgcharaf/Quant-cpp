
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std; 
//Author : Charaf ZGUIOUAR

 int main() {
    vector <int> nums = { 6, -20, -2, 10, 10, 20, 30, 40, 50}; 
    vector <int>::iterator first = nums.begin();
    vector <int>::iterator end = nums.end() -1; 
    vector <int> :: iterator it; 
    //cout << *end << endl;
    //cout << * (end - 1) << endl; // get the n - 1 ite

    advance(first, 1); 
    //cout << *first << endl; 

    for (it = nums.begin(); it < nums.end(); it++){
        //cout << *it << endl;

    }
    //ranged loop 

    for (int i : nums){
        //cout << i << endl;
    }
    //count the number of times an item shows up 
    int val = 20; 
    reverse (nums.begin(), nums.end());

    int count_times = count(nums.begin(), nums.end(), val); 
    cout << "found " << val << " " << count_times << " times";

    for (int &j: nums){
        cout << j << endl;
    }

}

