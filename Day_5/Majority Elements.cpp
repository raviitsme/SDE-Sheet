#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. Brute Force Approach - O(N^2) Time | O(1) Space
    int majorityElement_brute(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }
            // Check if the current element's count exceeds n / 2
            if (count > n / 2) {
                return nums[i];
            }
        }
        return -1; // Default fallback if no majority element exists
    }

    // 2. Better Approach (Using Hash Map) - O(N) Time | O(N) Space
    int majorityElement_better(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> frequencyMap;
        
        // Count frequencies of each element
        for (int num : nums) {
            frequencyMap[num]++;
            
            // Check during insertion to return early if possible
            if (frequencyMap[num] > n / 2) {
                return num;
            }
        }
        return -1;
    }

    // 3. Optimized Approach (Boyer-Moore Voting Algorithm) - O(N) Time | O(1) Space
    int majorityElement_optimized(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        // Step 1: Find the potential majority candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    
    cout << "Brute Force Result: " << solver.majorityElement_brute(nums) << endl;
    cout << "Better (Map) Result: " << solver.majorityElement_better(nums) << endl;
    cout << "Optimized (Voting) Result: " << solver.majorityElement_optimized(nums) << endl;
    
    return 0;
}