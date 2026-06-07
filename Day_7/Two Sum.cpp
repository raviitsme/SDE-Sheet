#include<bits/stdc++.h>
using namespace std;

class TwoSum{
public:

    // Brute force
    vector<int> two_sum_brute(vector<int> &nums, int target){
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    // Better Solution
    vector<int> two_sum_better(vector<int> &nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> indices;

        for(int i = 0; i < n; i++) {
            indices.push_back({nums[i], i});
        }

        sort(indices.begin(), indices.end());
        int left = 0, right = n - 1;
        while(left < right) {
            int current_sum = indices[left].first + indices[right].first;

            if(current_sum == target) {
                return {indices[left].second, indices[right].second};
            } else if(current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }

    // Optimized
    vector<int> two_sum_optimized(vector<int> &nums, int target){
        int n = nums.size();
        unordered_map<int, int> mpp; 

        for(int i = 0; i < n; i++) {
            int a = nums[i];
            int rem = target - a;

            if(mpp.find(rem) != mpp.end()) {
                return {mpp[rem], i};
            }
            mpp[a] = i;
        }
        return {};
    }

};

int main() {
    TwoSum solver; // Class ka object create kiya

    // Test Case 1: Standard Positive Array
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    
    cout << "--- Test Case 1 (Target: " << target1 << ") ---" << endl;
    
    vector<int> res_brute1 = solver.two_sum_brute(nums1, target1);
    cout << "Brute Force Result : [" << res_brute1[0] << ", " << res_brute1[1] << "]" << endl;
    
    vector<int> res_better1 = solver.two_sum_better(nums1, target1);
    cout << "Better Result       : [" << res_better1[0] << ", " << res_better1[1] << "]" << endl;
    
    vector<int> res_opt1 = solver.two_sum_optimized(nums1, target1);
    cout << "Optimized Result    : [" << res_opt1[0] << ", " << res_opt1[1] << "]" << endl;
    cout << endl;


    // Test Case 2: Array with Duplicate Elements (Edge Case)
    vector<int> nums2 = {3, 2, 4, 3};
    int target2 = 6; // 3 + 3 = 6 (indices 0 aur 3)
    
    cout << "--- Test Case 2 (Target: " << target2 << " with duplicates) ---" << endl;
    
    vector<int> res_brute2 = solver.two_sum_brute(nums2, target2);
    cout << "Brute Force Result : [" << res_brute2[0] << ", " << res_brute2[1] << "]" << endl;
    
    vector<int> res_better2 = solver.two_sum_better(nums2, target2);
    cout << "Better Result       : [" << res_better2[0] << ", " << res_better2[1] << "]" << endl;
    
    vector<int> res_opt2 = solver.two_sum_optimized(nums2, target2);
    cout << "Optimized Result    : [" << res_opt2[0] << ", " << res_opt2[1] << "]" << endl;
    cout << endl;

    return 0;
}