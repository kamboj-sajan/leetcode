// Last updated: 25/09/2026, 01:24:52
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
//     ListNode* deleteDuplicates(ListNode* head) {
//         if(head == NULL || head->next == NULL)return head;
//         ListNode* temp = head;
//         while(temp->next != NULL && temp->next->next != NULL){
//             if(temp->val == temp->next->val){
//                 temp->next = temp->next->next;
//             }else{
//                 temp = temp->next;
//             }
//         }
//         if(temp->val == temp->next->val){
//             temp->next = NULL;
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL)
            return head;

        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {

            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};