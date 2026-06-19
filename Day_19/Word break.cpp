#include <bits/stdc++.h>
using namespace std;

void solve(string s, unordered_set<string> &dict,
           string current, vector<string> &ans) {

    if (s.size() == 0) {
        ans.push_back(current);
        return;
    }

    for (int i = 1; i <= s.size(); i++) {
        string prefix = s.substr(0, i);

        if (dict.find(prefix) != dict.end()) {
            string remaining = s.substr(i);

            if (current.empty()) {
                solve(remaining, dict, prefix, ans);
            } else {
                solve(remaining, dict, current + " " + prefix, ans);
            }
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    vector<string> ans;
    solve(s, dict, "", ans);

    return ans;
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> wordDict(n);

    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    vector<string> result = wordBreak(s, wordDict);

    if (result.empty()) {
        cout << "No valid sentences" << endl;
    } else {
        for (auto &x : result) {
            cout << x << endl;
        }
    }

    return 0;
}