#include<bits/stdc++.h>
using namespace std;

class BuyAndSell{
public:
    // Bruteforce
    int maxProfit_brute(vector<int> &nums){
        int maxProfit = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] > nums[i]) {
                    int currProfit = nums[j] - nums[i];
                    maxProfit = max(currProfit, maxProfit);
                }
            }
        }
        return maxProfit;
    }

    // Better approach
    int maxProfit_better(vector<int> &nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> maxFuture(n);
        maxFuture[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            maxFuture[i] = max(nums[i], maxFuture[i + 1]);
        }
        int maxProfit = 0;
        for(int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, maxFuture[i] - nums[i]);
        }
        return maxProfit;
    }

    // Optimized approach
    int maxProfit_optimized(vector<int>& prices) {
        int profit = 0;
        int left = 0;
        int right = 1;
        while(right < prices.size()) {
            if(prices[left] < prices[right]) {
                int currProfit = prices[right] - prices[left];
                profit = max(profit, currProfit);
            } else {
                left = right;
            }
            right++;
        }
        return profit;
    }
};

int main() {
    BuyAndSell solver;

    // Example Input: Buy on Day 2 (price = 1) and sell on Day 5 (price = 6)
    // Profit = 6 - 1 = 5
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "=== Stock Buy and Sell Challenge ===" << endl;
    cout << "Prices per day: ";
    for(int price : prices) {
        cout << price << " ";
    }
    cout << "\n\n";

    // 1. Brute Force Method Test
    int bruteRes = solver.maxProfit_brute(prices);
    cout << "1. Brute Force Result : " << bruteRes << " (Expected: 5)" << endl;

    // 2. Better Method Test
    int betterRes = solver.maxProfit_better(prices);
    cout << "2. Better Method Result: " << betterRes << " (Expected: 5)" << endl;

    // 3. Optimized Method Test
    int optimizedRes = solver.maxProfit_optimized(prices);
    cout << "3. Optimized Result   : " << optimizedRes << " (Expected: 5)" << endl;

    return 0;
}