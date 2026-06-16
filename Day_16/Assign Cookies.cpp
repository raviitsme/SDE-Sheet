#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();
        int l = 0, r = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(l < n && r < m) {
            if(s[l] >= g[r]) {
                r++;
            }
            l++;
        }

        return r;
    }
};

int main() {

    vector<int> g = {1, 2, 3}; // greed factors
    vector<int> s = {1, 1};    // cookie sizes

    Solution obj;

    int ans = obj.findContentChildren(g, s);

    cout << "Maximum content children: " << ans << endl;

    return 0;
}