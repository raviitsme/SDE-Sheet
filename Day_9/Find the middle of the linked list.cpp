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

class MiddleOfLinkedList {
public:

    // Brute Force Approach
    // Time Complexity : O(N + N/2)
    // Space Complexity : O(1)
    ListNode* middleNode_brute(ListNode* head) {

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int mid = (count / 2) + 1;

        temp = head;

        while(temp != NULL) {
            mid--;

            if(mid == 0) break;

            temp = temp -> next;
        }

        return temp;
    }

    // Optimal Approach (Slow & Fast Pointer)
    // Time Complexity : O(N)
    // Space Complexity : O(1)
    ListNode* middleNode_optimal(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

void printFromNode(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* createList(vector<int>& arr) {

    if (arr.empty()) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main() {

    MiddleOfLinkedList solver;

    vector<int> arr = {1, 2, 3, 4, 5, 6};

    ListNode* head = createList(arr);

    cout << "--- Brute Force Approach ---" << endl;
    ListNode* middle1 = solver.middleNode_brute(head);
    cout << "Middle Node : " << middle1->val << endl;

    cout << endl;

    cout << "--- Optimal Approach ---" << endl;
    ListNode* middle2 = solver.middleNode_optimal(head);
    cout << "Middle Node : " << middle2->val << endl;

    printFromNode(middle2);

    return 0;
}