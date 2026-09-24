// Last updated: 25/09/2026, 01:23:51
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp = head;
//         while(temp != NULL){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         sort(arr.begin(),arr.end());
//         ListNode* t = head;
//         for(int i: arr){
//             t->val = i;
//             t = t->next;
//         }
//         return head;
//     }
// };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        // Merge sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        if (a != nullptr)
            tail->next = a;
        else
            tail->next = b;

        return dummy.next;
    }
};