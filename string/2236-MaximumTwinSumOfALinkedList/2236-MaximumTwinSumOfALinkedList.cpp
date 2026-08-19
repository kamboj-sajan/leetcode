// Last updated: 19/08/2026, 15:33:09
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
//     int pairSum(ListNode* head) {
//        vector<int> vec;
//        while(head->next != NULL){
//         vec.push_back(head->val);
//         head = head->next;
//        }
//        vec.push_back(head->val);
//        int n = vec.size();
//        int maxi = INT_MIN;
//        for(int i=0; i<=n/2-1; ++i){
//         maxi = max(maxi,vec[i]+vec[n-1-i]);
//        }
//        return maxi;
//     }
// };


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* middle = middleNode(head);
        ListNode* second = middle->next;
        middle->next = NULL;
        ListNode* first = reverse(head);
        int res = 0;
        while(first){
            res = max(res,first->val + second->val);
            first = first->next;
            second = second->next;
        }
        return res;
    }
};