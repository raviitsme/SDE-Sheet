#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxAr = 0;
        int ele = 0;
        int nse = 0;
        int pse = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                ele = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxAr = max(maxAr, (heights[ele] * (nse - pse - 1)));
            }
            st.push(i);
        }

        while(!st.empty()){
            nse = n;
            ele = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxAr = max(maxAr, (heights[ele] * (nse - pse - 1)));
        }
        return maxAr;
    }
};

int main() {
    Solution solver;
    
    // Test Case from our dry run
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    int result = solver.largestRectangleArea(heights);
    
    cout << "Histogram heights: ";
    for(int h : heights) {
        cout << h << " ";
    }
    cout << "\nMaximum Rectangle Area: " << result << endl;

    return 0;
}