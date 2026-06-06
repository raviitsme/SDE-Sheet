#include <bits/stdc++.h>
using namespace std;

class MajorityElements {
public:
    // 1. Brute force
    vector<int> majority_brute(vector<int> &nums){
        int n = nums.size();
        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(result.size() == 0 || result[0] != nums[i]) {
                int c = 0;

                for(int j = 0; j < n; j++) {
                    if(nums[i] == nums[j]) {
                        c++;
                    }
                }

                if(c > (n/3)) {
                    result.push_back(nums[i]);
                }
            }
            if(result.size() == 2) break;
        }
        return result;
    }

    // 2. Better Approach (Using Hash Map)
    vector<int> majority_better(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        vector<int> result;

        // Step 1: Count frequencies of all elements
        for(int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Iterate over map and filter elements strictly greater than n/3
        for(auto &pair : freqMap) {
            if(pair.second > n / 3) {
                result.push_back(pair.first);
            }
            if(result.size() == 2) break; // Maximum 2 elements are possible
        }

        return result;
    }

    // 3. Optimized Approach (Extended Boyer-Moore Voting Algorithm)
    vector<int> majority_optimized(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(c1 == 0 && el2 != nums[i]) {
                c1 = 1;
                el1 = nums[i];
            } else if(c2 == 0 && el1 != nums[i]) {
                c2 = 1;
                el2 = nums[i];
            } else if(el1 == nums[i]) {
                c1++;
            } else if(el2 == nums[i]) {
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1 = 0;
        c2 = 0;
        for(int i = 0; i < n; i++) {
            if(el1 == nums[i]) c1++;
            if(el2 == nums[i]) c2++;
        }
        int mini = (int)(n/3) + 1;
        if(c1 >= mini) ans.push_back(el1);
        if(c2 >= mini) ans.push_back(el2);
        return ans;
    }
};
int main() {
    MajorityElements sol;

    vector<int> arr = {11, 33, 33, 11, 33, 11};

    // 1. Brute Force Test
    vector<int> ans_brute = sol.majority_brute(arr);
    cout << "Answer using brute     : " << ans_brute[0] << " , " << ans_brute[1] << endl;

    // 2. Better Map Test
    vector<int> ans_better = sol.majority_better(arr);
    cout << "Answer using better    : " << ans_better[0] << " , " << ans_better[1] << endl;

    // 3. Optimized Voting Test
    vector<int> ans_optimized = sol.majority_optimized(arr);
    cout << "Answer using optimized : " << ans_optimized[0] << " , " << ans_optimized[1] << endl;

    return 0;
}