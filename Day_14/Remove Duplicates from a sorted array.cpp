#include <bits/stdc++.h>
using namespace std;

class RemoveDuplicates {
public:

    // Brute Force (Using Set)
    // Time Complexity : O(N log N)
    // Space Complexity : O(N)

    int removeDuplicates_brute(vector<int>& nums) {

        set<int> st;

        for(int x : nums) {
            st.insert(x);
        }

        int index = 0;

        for(auto it : st) {
            nums[index++] = it;
        }

        return st.size();
    }

    // Optimal (Two Pointers)
    // Time Complexity : O(N)
    // Space Complexity : O(1)

    int removeDuplicates_optimal(vector<int>& nums) {

        int i = 0;

        for(int j = 1; j < nums.size(); j++) {

            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

void printArray(vector<int>& nums, int k) {

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int main() {

    RemoveDuplicates solver;

    vector<int> arr1 = {1,1,2,2,3,3,4,4,5};
    vector<int> arr2 = arr1;

    cout << "--- Brute Force (Set) ---" << endl;
    int k1 = solver.removeDuplicates_brute(arr1);
    cout << "Length = " << k1 << endl;
    printArray(arr1, k1);

    cout << endl;

    cout << "--- Optimal Approach ---" << endl;
    int k2 = solver.removeDuplicates_optimal(arr2);
    cout << "Length = " << k2 << endl;
    printArray(arr2, k2);

    return 0;
}