#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices of elements
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window's bounds
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove elements from the back that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add the current element's index
            dq.push_back(i);
            
            // The first window reaches size k at index k - 1
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Example test case
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = solver.maxSlidingWindow(nums, k);
    
    // Output the results
    cout << "Input Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\nWindow Size (k): " << k << endl;
    
    cout << "Max Sliding Window: ";
    for (int max_val : result) {
        cout << max_val << " ";
    }
    cout << endl;

    return 0;
}