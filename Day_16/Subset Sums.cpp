#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int ind, int sum, vector<int>& arr, vector<int>& ans) {
        if (ind == arr.size()) {
            ans.push_back(sum);
            return;
        }

        solve(ind + 1, sum + arr[ind], arr, ans);
        solve(ind + 1, sum, arr, ans);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;

        solve(0, 0, arr, ans);

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    vector<int> arr = {2, 3};

    Solution obj;

    vector<int> ans = obj.subsetSums(arr, arr.size());

    for (int x : ans)
        cout << x << " ";

    return 0;
}