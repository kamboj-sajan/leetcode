// Last updated: 25/09/2026, 01:25:16
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
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k== 0)return head;
//         int n = 1;
//         ListNode* cnt = head;
//         while(cnt->next != NULL){
//             cnt = cnt->next;
//             n++;
//         }
//         k %= n;
//         if(k == 0)return head;
//         ListNode* newlast = head;
//         ListNode* temp = head;
//         ListNode* newhead;
//         for(int i=0; i<n-k-1; i++){
//             temp = temp->next;
//             newlast = newlast ->next;
//         }
//         newhead = temp->next;
//         while(newlast->next != NULL){
//             newlast = newlast ->next;
//         }
//         temp->next = NULL;
//         newlast->next = head;
//         return newhead;
//     }
// };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL)
            return NULL;

        ListNode* temp = head;
        int cnt = 0;

        while(temp) {
            cnt++;
            temp = temp->next;
        }

        k = k % cnt;
        if(k == 0)
            return head;

        int rot = cnt - k;

        temp = head;

        while(rot > 1) {
            temp = temp->next;
            rot--;
        }

        ListNode* front = temp->next;

        temp->next = NULL;

        ListNode* tail = front;

        while(tail->next)
            tail = tail->next;

        tail->next = head;

        return front;
    }
};