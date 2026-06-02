#include<bits/stdc++.h>
using namespace std;

class SortColors{
public:
    // 1. Brute Force Approach - O(N log N)
    void sortColors_brute(vector<int> &nums) {
        // Simulating the logic of manual sorting (like Quick Sort)
        sort(nums.begin(), nums.end()); 
    }

    // 2. Better Approach (Counting Sort) - O(N) but 2 passes
    void sortColors_better(vector<int> &nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Pass 1: Count the frequencies
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) count0++;
            else if (nums[i] == 1) count1++;
            else count2++;
        }

        // Pass 2: Overwrite original array
        int idx = 0;
        while (count0--) nums[idx++] = 0;
        while (count1--) nums[idx++] = 1;
        while (count2--) nums[idx++] = 2;
    }

    // 3. Optimal Approach (Dutch National Flag Algorithm) - O(N) single pass
    void sortColors_optimal(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            } else if (nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

    // Helper function to print array
    void printArray(const vector<int> &nums) {
        for (int x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    SortColors solver;

    // Test cases setup
    vector<int> arr1 = {2, 0, 2, 1, 1, 0};
    vector<int> arr2 = {2, 0, 2, 1, 1, 0};
    vector<int> arr3 = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    solver.printArray(arr1);
    cout << "\n";

    // 1. Testing Brute Force
    solver.sortColors_brute(arr1);
    cout << "1. Brute Force Result : ";
    solver.printArray(arr1);

    // 2. Testing Better Method
    solver.sortColors_better(arr2);
    cout << "2. Better Method Result: ";
    solver.printArray(arr2);

    // 3. Testing Optimal Method
    solver.sortColors_optimal(arr3);
    cout << "3. Optimal Method Result: ";
    solver.printArray(arr3);

    return 0;
}