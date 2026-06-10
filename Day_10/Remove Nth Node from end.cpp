#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    };
};

class RemoveNode {
public:
    // Brute force | TC - O(len(list) + O(len(list) - N)) | SC - O(1)
    ListNode* remove_node_brute(ListNode* head, int n) {
        int c = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            c++;
            temp = temp -> next;
        }
        if(c == n) {
            ListNode* newNode = head -> next;
            free(head);
            return newNode;
        }

        int res = c - n;
        temp = head;
        while(temp != NULL) {
            res--;
            if(res == 0) break;
            temp = temp -> next;
        }
        ListNode* deleteNode = temp -> next;
        temp -> next = temp -> next -> next;
        free(deleteNode);
        return head;
    }

    // Optimal | TC - O(len(list)) | SC - O(1)
    ListNode* remove_node_optimal(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        if(fast == NULL){
            ListNode* newNode = head -> next;
            free(head);
            return newNode;
        }
        while(fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }

        ListNode* deleteNode = slow -> next;
        slow -> next = slow -> next -> next;
        free(deleteNode);
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
    RemoveNode rN;

    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head1 = createList(arr);

    cout << "--- Brute Force Approach ---" << endl;
    head1 = rN.remove_node_brute(head1, n);
    printList(head1);

    cout << endl;

    ListNode* head2 = createList(arr);

    cout << "--- Optimal Approach ---" << endl;
    head2 = rN.remove_node_optimal(head2, n);
    printList(head2);

    return 0;
}