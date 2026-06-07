#include <bits/stdc++.h>
using namespace std;

class LongestConsecutiveSequence {
private:
    // Helper function for Brute Force to check if an element exists in the array
    bool linearSearch(vector<int>& arr, int num) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == num) return true;
        }
        return false;
    }

public:
    // 1. Brute Force Approach - O(N^2) Time | O(1) Space
    int longestConsecutive_brute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int current_count = 1;

            while (linearSearch(nums, x + 1) == true) {
                x = x + 1;
                current_count = current_count + 1;
            }

            longest = max(longest, current_count);
        }
        return longest;
    }

    // 2. Better Approach (Sorting) - O(N log N) Time | O(1) Space
    int longestConsecutive_better(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // Step 1: Array ko sort karein
        sort(nums.begin(), nums.end());

        int longest = 1;
        int current_count = 1;
        int lastSmaller = nums[0];

        for (int i = 1; i < n; i++) {

            if (nums[i] == lastSmaller + 1) {
                current_count += 1;
                lastSmaller = nums[i];
            }

            else if (nums[i] != lastSmaller) {
                longest = max(longest, current_count);
                current_count = 1; 
                lastSmaller = nums[i];
            }
        }
        
        return max(longest, current_count);
    }

    // 3. Optimized Approach (Hash Set) - O(N) Time | O(N) Space
    int longestConsecutive_optimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            if (st.find(x - 1) == st.end()) {
                int current_count = 1;

                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    current_count += 1;
                }
                
                longest = max(longest, current_count);
            }
        }
        return longest;
    }
};

int main() {
    LongestConsecutiveSequence solver;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << "--- Longest Consecutive Sequence ---" << endl;
    
    // Test Brute Force
    cout << "Brute Force Result : " << solver.longestConsecutive_brute(nums) << endl;

    // Test Better (Sorting)
    cout << "Better Result       : " << solver.longestConsecutive_better(nums) << endl;

    // Test Optimized (Hash Set)
    cout << "Optimized Result    : " << solver.longestConsecutive_optimized(nums) << endl;

    return 0;
}