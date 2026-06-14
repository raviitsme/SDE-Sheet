#include <bits/stdc++.h>
using namespace std;

class TrappingRainWater {
public:

    // Brute Force
    // Time Complexity : O(N^2)
    // Space Complexity : O(1)

    int trap_brute(vector<int>& height) {

        int n = height.size();
        int water = 0;

        for (int i = 0; i < n; i++) {

            int leftMax = 0, rightMax = 0;

            for (int j = 0; j <= i; j++) {
                leftMax = max(leftMax, height[j]);
            }

            for (int j = i; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }

            water += min(leftMax, rightMax) - height[i];
        }

        return water;
    }

    // Better Approach
    // Time Complexity : O(N)
    // Space Complexity : O(N)

    int trap_better(vector<int>& height) {

        int n = height.size();

        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int water = 0;

        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }

    // Optimal Approach (Two Pointers)
    // Time Complexity : O(N)
    // Space Complexity : O(1)

    int trap_optimal(vector<int>& height) {

        int n = height.size();

        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        int water = 0;

        while (left <= right) {

            if (height[left] <= height[right]) {

                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];

                left++;
            }
            else {

                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];

                right--;
            }
        }

        return water;
    }
};

int main() {

    TrappingRainWater solver;

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "--- Brute Force ---" << endl;
    cout << solver.trap_brute(height) << endl;

    cout << endl;

    cout << "--- Better Approach ---" << endl;
    cout << solver.trap_better(height) << endl;

    cout << endl;

    cout << "--- Optimal Approach ---" << endl;
    cout << solver.trap_optimal(height) << endl;

    return 0;
}