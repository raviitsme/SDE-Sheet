#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    };
};

class AddLL {
public:
    ListNode* add_ll_optimal(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            if(l1 != NULL) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }

            if(l2 != NULL) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }

            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp -> next = node;
            temp = temp -> next;
        }
        return dummy -> next;
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

    AddLL add;

    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);

    ListNode* result = add.add_ll_optimal(l1, l2);

    cout << "Result : ";
    printList(result);

    return 0;
}