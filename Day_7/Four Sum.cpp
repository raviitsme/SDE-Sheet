#include<bits/stdc++.h>
using namespace std;

class FourSum {
public:
    // Brute solution
    vector<vector<int>> four_sum_brute(vector<int> &nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    for(int l = k + 1; l < n; l++) {
                        long long sum =(long long)nums[i] + nums[j] + nums[k] + nums[l];

                        if(sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    } 

    // Better solution
    vector<vector<int>> four_sum_better(vector<int> &nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                unordered_set<long, long> hashset;
                for(int k = j + 1; k < n; k++) {
                    long long curr_sum =(long long)nums[i] + nums[j] + nums[k];
                    long long rem = target - curr_sum;

                    if(hashset.find(rem) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)rem};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    vector<vector<int>> four_sum_optimized(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1; j < n; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n + 1;

                while(left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(left < right && nums[right] == nums[right + 1]) right--;
                    } else if(sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }

};