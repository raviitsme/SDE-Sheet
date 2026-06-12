#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class CycleStart {
public:

    // Brute Force (Hash Map) | TC - O(N) SC - O(N)

    ListNode* detectCycle_brute(ListNode* head) {

        unordered_map<ListNode*, int> mpp;

        ListNode* temp = head;

        while (temp != NULL) {

            if (mpp.find(temp) != mpp.end()) {
                return temp;
            }

            mpp[temp] = 1;
            temp = temp->next;
        }

        return NULL;
    }

    // Optimal (Floyd's Cycle Detection) | TC - O(N) SC - O(1)

    ListNode* detectCycle_optimal(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};

int main() {

    CycleStart solver;

    // Creating:
    // 3 -> 2 -> 0 -> -4
    //      ^         |
    //      |_________|

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Cycle starts at node with value 2
    head->next->next->next->next = head->next;

    cout << "--- Brute Force ---" << endl;

    ListNode* ans1 = solver.detectCycle_brute(head);

    if (ans1)
        cout << "Cycle starts at node : " << ans1->val << endl;
    else
        cout << "No Cycle" << endl;

    cout << endl;

    cout << "--- Optimal Approach ---" << endl;

    ListNode* ans2 = solver.detectCycle_optimal(head);

    if (ans2)
        cout << "Cycle starts at node : " << ans2->val << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}