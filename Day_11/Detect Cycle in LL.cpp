#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode (int x) {
        val = x;
        next = NULL;
    };
};

class DetectCycle {
public:
    bool hasCycle_brute(ListNode* head) {
        unordered_map<ListNode*, int> mpp;

        ListNode* temp = head;
        
        while(temp != NULL) {
            if(mpp.find(temp) != mpp.end()) {
                return true;
            }
            mpp[temp] = 1;
            temp = temp -> next;
        }
        return false;
    }
};

int main() {
    DetectCycle sol;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head->next->next->next->next->next = head->next->next;

    cout << "Brute : " << endl;
    if (sol.hasCycle_brute(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;
}