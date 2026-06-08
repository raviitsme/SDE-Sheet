#include <bits/stdc++.h>
using namespace std;

class LongestSubarray {
public:
    // 1. Brute Force Approach - O(N^2) Time | O(1) Space
    // (Works for all inputs: Positives, Negatives, and Zeros)
    int longestSubarray_brute(vector<int>& a, long long k) {
        int n = a.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            long long current_sum = 0;
            for (int j = i; j < n; j++) {
                current_sum += a[j];
                
                if (current_sum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }

    // 2. Better Approach (Prefix Sum + Hash Map) - O(N) Time | O(N) Space
    // (CRITICAL: This is the standard OPTIMAL solution if the array contains NEGATIVE numbers)
    int longestSubarray_better(vector<int>& a, long long k) {
        int n = a.size();
        unordered_map<long long, int> preSumMap;
        long long rem_sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            rem_sum += a[i]; 

            if (rem_sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            long long remaining = rem_sum - k;
            if (preSumMap.find(remaining) != preSumMap.end()) {
                int len = i - preSumMap[remaining];
                maxLen = max(maxLen, len);
            }

            if (preSumMap.find(rem_sum) == preSumMap.end()) {
                preSumMap[rem_sum] = i;
            }
        }
        return maxLen;
    }

    // 3. Optimized Approach (Sliding Window / Two-Pointer) - O(N) Time | O(1) Space
    // (CRITICAL: This approach ONLY works if the array contains strictly POSITIVE numbers & Zeros)
    int longestSubarray_optimized(vector<int>& a, long long k) {
        int left = 0, right = 0;
        long long sum = a[0];
        int maxLen = 0;
        int n = a.size();

        while (right < n) {
            while (left <= right && sum > k) {
                sum -= a[left];
                left++;
            }

            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
            if (right < n) {
                sum += a[right];
            }
        }
        return maxLen;
    }
};

int main() {
    LongestSubarray solver;
    
    // Test Case: Only Positive Numbers (Teeno approaches sahi chalengi)
    vector<int> a = {1, 2, 3, 1, 1, 1, 1};
    long long k = 3;

    cout << "--- Testing Longest Subarray with Sum K ---" << endl;
    
    cout << "1. Brute Force Result  : " << solver.longestSubarray_brute(a, k) << endl;
    cout << "2. Better (Map) Result : " << solver.longestSubarray_better(a, k) << endl;
    cout << "3. Optimized Result    : " << solver.longestSubarray_optimized(a, k) << endl;

    return 0;
}