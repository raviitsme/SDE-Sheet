#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
    /*
        Brute Force : 
        First we will generate all the possible permutation for the given array.
        Then we will do a linear search on all generated permutations and suppose we find the given 
        array at index.
        Then, we will return the (index + 1)th term which will be our required next permutation.
    */

    // Better method : 
    // Using built-in STL method for next permutation.
    void nextPermutation(vector<int> &arr) {
        next_permutation(arr.begin(), arr.end());
    }   

    // Optimized method :
    /*  Find the longest prefix match from the right, 
        and set the breakpoint where the left element is smaller than the right element. 
        Swap the element with the next smallest element that is greater than it from the right side. 
        At last, sort the remaining suffix to get the next permutation. */
    
    void optimized_next_permutation(vector<int> &arr) {
        int n = arr.size();
        int index = -1;
        
        // To find the break point
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] < arr[i + 1]) {
                index = i;
                break;
            }
        }

        if(index == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }

        // Swap the element just largest to the current (index)th element
        for(int i = n - 1; i >= index; i--) {
            if(arr[i] > arr[index]) {
                swap(arr[i], arr[index]);
                break;
            }
        }

        // Swap the remaining suffix to get the required next permutation
        reverse(arr.begin() + index + 1, arr.end());
    }

    // Helper function to cleanly print array configurations
    void printArray(const vector<int> &arr) {
        for(auto i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main () {
    Solution solver;

    // --- Testing Better Method (STL Approach) ---
    cout << "=== Testing Better Method (STL) ===" << endl;
    vector<int> arr1 = {2, 1, 5, 4, 3, 0, 0};
    cout << "Original array: ";
    solver.printArray(arr1);

    solver.nextPermutation(arr1);
    cout << "Next permutation: ";
    solver.printArray(arr1); // Expected: 2 3 0 0 1 4 5

    cout << endl;

    // --- Testing Optimized Method (Custom 3-Step) ---
    cout << "=== Testing Optimized Method ===" << endl;
    vector<int> arr2 = {2, 1, 5, 4, 3, 0, 0};
    cout << "Original array: ";
    solver.printArray(arr2);

    solver.optimized_next_permutation(arr2);
    cout << "Next permutation: ";
    solver.printArray(arr2); // Expected: 2 3 0 0 1 4 5

    cout << endl;

    // --- Testing Edge Case (Completely Descending Array) ---
    cout << "=== Testing Edge Case (Maximized Order) ===" << endl;
    vector<int> arr3 = {3, 2, 1};
    cout << "Original array: ";
    solver.printArray(arr3);

    solver.optimized_next_permutation(arr3);
    cout << "Next permutation: ";
    solver.printArray(arr3); // Expected: 1 2 3

    return 0;
}