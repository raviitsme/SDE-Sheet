#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<int>& ds,
               vector<vector<int>>& ans, vector<int>& used) {

        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(used[i]) continue;

            ds.push_back(nums[i]);
            used[i] = 1;

            solve(nums, ds, ans, used);

            ds.pop_back();
            used[i] = 0;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> used(nums.size(), 0);

        solve(nums, ds, ans, used);

        return ans;
    }
};

int main() {

    vector<int> nums = {1,2,3};

    Solution obj;

    vector<vector<int>> ans = obj.permute(nums);

    for(auto &v : ans) {
        cout << "[ ";
        for(auto x : v)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}