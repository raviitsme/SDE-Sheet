#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPal(string &s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    void solve(int ind, string &s,
               vector<string>& path,
               vector<vector<string>>& ans) {

        if(ind == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i = ind; i < s.size(); i++) {

            if(isPal(s, ind, i)) {
                path.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, s, path, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    string s = "aab";

    auto ans = obj.partition(s);

    for(auto &v : ans){
        for(auto &x : v) cout << x << " ";
        cout << endl;
    }
}