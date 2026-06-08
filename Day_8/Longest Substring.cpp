#include <bits/stdc++.h>
using namespace std;

class LongestSubstring {
public:

    // 1. Brute Force Approach - O(N^3) Time | O(N) Space
    int lengthOfLongestSubstring_brute(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                unordered_set<char> st;
                bool unique = true;

                for (int k = i; k <= j; k++) {
                    if (st.count(s[k])) {
                        unique = false;
                        break;
                    }
                    st.insert(s[k]);
                }

                if (unique) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }

    // 2. Better Approach - O(N^2) Time | O(N) Space
    int lengthOfLongestSubstring_better(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;

            for (int j = i; j < n; j++) {
                if (st.count(s[j])) {
                    break;
                }

                st.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }

    // 3. Optimal Approach (Sliding Window + HashMap)
    // O(N) Time | O(N) Space
    int lengthOfLongestSubstring_optimal(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            if (mp.find(s[right]) != mp.end() &&
                mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }

            mp[s[right]] = right;

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    LongestSubstring solver;

    string s = "abcabcbb";

    cout << "--- Longest Substring Without Repeating Characters ---" << endl;

    cout << "1. Brute Force Result  : "
         << solver.lengthOfLongestSubstring_brute(s) << endl;

    cout << "2. Better Result       : "
         << solver.lengthOfLongestSubstring_better(s) << endl;

    cout << "3. Optimal Result      : "
         << solver.lengthOfLongestSubstring_optimal(s) << endl;

    return 0;
}