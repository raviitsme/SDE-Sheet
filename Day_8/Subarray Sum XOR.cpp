#include <bits/stdc++.h>
using namespace std;

class SubarrayXOR {
public:

    // 1. Brute Force Approach - O(N^3) Time | O(1) Space
    int countSubarrays_brute(vector<int>& a, int k) {
        int n = a.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int xr = 0;

                for (int l = i; l <= j; l++) {
                    xr ^= a[l];
                }

                if (xr == k) {
                    count++;
                }
            }
        }
        return count;
    }

    // 2. Better Approach - O(N^2) Time | O(1) Space
    int countSubarrays_better(vector<int>& a, int k) {
        int n = a.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int xr = 0;

            for (int j = i; j < n; j++) {
                xr ^= a[j];

                if (xr == k) {
                    count++;
                }
            }
        }
        return count;
    }

    // 3. Optimal Approach (Prefix XOR + Hash Map)
    // O(N) Time | O(N) Space
    int countSubarrays_optimal(vector<int>& a, int k) {
        int n = a.size();

        unordered_map<int, int> xorMap;
        int xr = 0;
        int count = 0;

        xorMap[0] = 1;

        for (int i = 0; i < n; i++) {
            xr ^= a[i];

            int required = xr ^ k;

            if (xorMap.find(required) != xorMap.end()) {
                count += xorMap[required];
            }

            xorMap[xr]++;
        }

        return count;
    }
};

int main() {
    SubarrayXOR solver;

    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;

    cout << "--- Count Subarrays with XOR K ---" << endl;

    cout << "1. Brute Force Result  : "
         << solver.countSubarrays_brute(a, k) << endl;

    cout << "2. Better Result       : "
         << solver.countSubarrays_better(a, k) << endl;

    cout << "3. Optimal Result      : "
         << solver.countSubarrays_optimal(a, k) << endl;

    return 0;
}