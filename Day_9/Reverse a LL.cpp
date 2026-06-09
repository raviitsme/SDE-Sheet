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

class ReverseLinkedList {
public:

    // Brute Approach (Using Stack)
    // Time Complexity : O(N)
    // Space Complexity : O(N)
    ListNode* reverseList_brute(ListNode* head) {

        stack<int> stk;

        ListNode* temp = head;

        while (temp != NULL) {
            stk.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while (temp != NULL) {
            temp->val = stk.top();
            stk.pop();
            temp = temp->next;
        }

        return head;
    }

    // Optimal Approach (Three Pointers)
    // Time Complexity : O(N)
    // Space Complexity : O(1)
    ListNode* reverseList_optimal(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
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

    ReverseLinkedList solver;

    vector<int> arr = {1, 2, 3, 4, 5};

    // Better Approach Test
    ListNode* head1 = createList(arr);

    cout << "--- Brute Approach (Stack) ---" << endl;
    cout << "Original List : ";
    printList(head1);

    head1 = solver.reverseList_brute(head1);

    cout << "Reversed List : ";
    printList(head1);

    cout << endl;

    // Optimal Approach Test
    ListNode* head2 = createList(arr);

    cout << "--- Optimal Approach (Three Pointers) ---" << endl;
    cout << "Original List : ";
    printList(head2);

    head2 = solver.reverseList_optimal(head2);

    cout << "Reversed List : ";
    printList(head2);

    return 0;
}