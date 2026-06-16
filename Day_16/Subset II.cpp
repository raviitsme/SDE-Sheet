#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int index, vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        ans.push_back(ds);

        for (int i = index; i < nums.size(); i++) {

            if (i > index && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]);

            solve(i + 1, nums, ds, ans);

            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};

    Solution obj;

    vector<vector<int>> ans = obj.subsetsWithDup(nums);

    for (auto subset : ans) {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}