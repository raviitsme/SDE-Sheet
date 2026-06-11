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

class Solution {
private:
    ListNode* getKthNode(ListNode* temp, int k) {
        k--;
        while(temp != NULL && k > 0){
            temp = temp -> next;
            k--;
        }
        return temp;
    } 

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        
        while(temp != NULL) {
            ListNode* KthNode = getKthNode(temp, k);
            if(KthNode == NULL) {
                if(prevNode) {
                    prevNode -> next = temp;
                    break;
                }
            }

            ListNode* nextNode = KthNode -> next;
            KthNode -> next = NULL;

            reverseLinkedList(temp);
            if(temp == head)
                head = KthNode;
            else 
                prevNode -> next = KthNode;
            
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

ListNode* createList(vector<int>& arr) {

    if(arr.empty()) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printList(ListNode* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    ListNode* head = createList(arr);

    int k = 2;

    Solution obj;

    cout << "Original List : ";
    printList(head);

    head = obj.reverseKGroup(head, k);

    cout << "After Reversing in Groups of " << k << " : ";
    printList(head);

    return 0;
}