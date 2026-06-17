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

        for(int i = ind; i < a.size(); i++) {

            if(i > ind && a[i] == a[i-1]) continue;
            if(a[i] > target) break;

            ds.push_back(a[i]);
            solve(i + 1, a, target - a[i], ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(), a.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, a, target, ds, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> a = {10,1,2,7,6,1,5};
    int target = 8;

    auto ans = obj.combinationSum2(a, target);

    for(auto &v : ans){
        for(int x : v) cout << x << " ";
        cout << endl;
    }
}