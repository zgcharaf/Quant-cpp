#include <iostream>
#include <array>
#include <cstring>
#include <vector>
using namespace std;
 

int main() {
    // Internal Sorting, the data is stored in the main memory, External sorting the complete data is not always present in the main memory and is loaded in chunks 
    // Bubble sort  : for n elements the number of comparisons is n-1
    // Selection sort: Find the min of the unsorted list with n elements, find the minimum of n-1 elements\ min(of the first pass) and so on, Time complexity O(n^2)
    int i; 
    int j; 
    int temp;
    

    int arr[8] = {12, 134, 3, 0, 1, -1, -40, 4};
    int len = sizeof(arr)/sizeof(int);
    for(int i = 0; i < 8; i++){
    //std::cout << arr[i] << endl; 
    //std::cout <<  << endl;
    };

    for (int i =0; i < len; i++){
        for (int j = i+1; j <len+1; j++){
        
            if (arr[j] < arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
                




            };
            };
         
    };
    for(int i = 0; i < 8; i++){
        std::cout << arr[i] << "\t"; 
    //std::cout <<  << endl;
    };
   return 0;
}