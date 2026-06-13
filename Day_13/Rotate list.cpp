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

class Solution {
private:
    ListNode* findNthNode(ListNode* temp, int k) {
        int c = 1;
        while (temp != NULL) {
            if (c == k)
                return temp;
            c++;
            temp = temp->next;
        }
        return temp;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head;
        if (head == NULL || k == 0)
            return head;
        int len = 1;

        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        k = k % len;
        if (k % len == 0)
            return head;
        tail->next = head;
        ListNode* newTail = findNthNode(head, len - k);
        head = newTail->next;
        newTail->next = NULL;
        return head;
    }
};

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

void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Solution obj;

    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    head = obj.rotateRight(head, k);

    cout << "After Rotating by " << k << ": ";
    printList(head);

    return 0;
}