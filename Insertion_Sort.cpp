#include <iostream>
using namespace std;

int main() {
    int arr[8] = {12, 134, 3, 0, 1, -1, -40, 4};
    int len = sizeof(arr) / sizeof(int); 

    // Outer loop: Iterate over each element in the array starting from the second element
    for (int i = 1; i < len; i++) {
        // Store the current element to be positioned correctly in the sorted part of the array
        int temp = arr[i];
        
        // Initialize j to point to the last index of the sorted portion
        int j = i - 1;

        // Inner loop: Shift elements in the sorted portion to the right to create space
        // for the current element (temp) to be inserted in the correct position
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j]; // Shift element to the right
            j--; // Move to the previous element in the sorted portion
        }
        
        // Insert the current element (temp) into its correct position
        arr[j + 1] = temp;
    }

    // Print the sorted array
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }

    return 0;
}
