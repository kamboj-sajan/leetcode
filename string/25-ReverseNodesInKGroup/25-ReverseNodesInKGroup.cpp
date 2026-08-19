// Last updated: 19/08/2026, 16:13:05
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
    ListNode* ReverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
public:
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* KthNode = getKthNode(temp , k);
            if(KthNode == NULL){
                if(prevNode)prevNode -> next = temp;
                break;
            }
            ListNode* nextNode = KthNode -> next;
            KthNode -> next = NULL;
            ReverseLL(temp);
            if(temp == head){
                head = KthNode;
            }
            else{
                prevNode -> next = KthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};