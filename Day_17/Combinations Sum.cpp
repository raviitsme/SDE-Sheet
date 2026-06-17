#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int ind, vector<int>& a, int target,
               vector<int>& ds, vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        if(ind == a.size()) return;

        if(a[ind] <= target) {
            ds.push_back(a[ind]);
            solve(ind, a, target - a[ind], ds, ans);
            ds.pop_back();
        }

        solve(ind + 1, a, target, ds, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, a, target, ds, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> a = {2,3,6,7};
    int target = 7;

    auto ans = obj.combinationSum(a, target);

    for(auto &v : ans){
        for(int x : v) cout << x << " ";
        cout << endl;
    }
}