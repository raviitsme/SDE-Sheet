#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    // Stack stores pairs of {value, minimum_so_far}
    stack<pair<int, int>> st;

public:
    MinStack() {
        // Constructor doesn't need to initialize anything specific
    }
    
    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
        } else {
            // The minimum so far is the smaller of the current value 
            // and the previous minimum (at the top of the stack)
            int currentMin = min(value, st.top().second);
            st.push({value, currentMin});
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack* minStack = new MinStack();
    
    cout << "Pushing: -2, 0, -3" << endl;
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    
    cout << "Current Min: " << minStack->getMin() << " (Expected: -3)" << endl;
    
    minStack->pop();
    cout << "Popped top element." << endl;
    
    cout << "Current Top: " << minStack->top() << " (Expected: 0)" << endl;
    cout << "Current Min: " << minStack->getMin() << " (Expected: -2)" << endl;
    
    delete minStack;
    return 0;
}