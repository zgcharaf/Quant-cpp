#include <iostream>
#include <array>
using namespace std;

int main() {
    array <int, 4> nums = {100,200,300,400}; 
    cout<< nums.at(1)<<endl;

    cout<< nums.front()<<endl; //first element
    cout<< nums.back()<<endl; // last element 

    cout<< nums.empty()<<endl; // check if empty 

    int points = 0; 
    int answers [3]; 
    cout << "Type the missing number in the sequence"<<endl;
    cout << "1, 4, 5, 10, 16, ?" << endl; 
    cin >> answers[0];
    cout << "2, 4, 8, 16, 32, ?" << endl; 
    cin >> answers[1];
    cout << "1, 1, 2, 3, 5, ?" << endl; 
    cin >> answers[2];
    cout << "Sequence 1"<<endl;

    int sequences [3][5] = {
        {1, 5, 10, 16, 23},
        {2, 4, 8, 16, 32},
        {1, 1, 2, 3, 5}};

    if (answers[0]==sequences[0][4]){
        points++;
    };
    if (answers[1]==sequences[1][4]){
        points++;
    };
    if (answers[2]==sequences[2][4]){
        points++;
    };
    cout << "Your points is "<< points << " From 3"<< endl;
}