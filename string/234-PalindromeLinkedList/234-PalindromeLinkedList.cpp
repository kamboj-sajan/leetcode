// Last updated: 19/08/2026, 16:04:11
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
    ListNode* reverseLl(ListNode* head){
        if(head == NULL ||head->next == NULL)return head;
        ListNode* newhead = reverseLl(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = reverseLl(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;
        while(second != NULL){
            if(first->val != second->val){
                reverseLl(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLl(newhead);
        return true;
    }
};