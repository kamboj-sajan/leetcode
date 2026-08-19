// Last updated: 19/08/2026, 16:04:01
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
/*if(head == NULL) return head;
        if(head->data == node){
            Node* temp = head;
            head = head->next;
            free(temp);
            return head;
        }
        Node* temp = head;
        Node* prev = NULL;
        while(temp->next != NULL){
            if(temp->data == node){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
        */
        node->val = node->next->val;
        ListNode* temp = node->next;   
        node->next = node->next->next;
        delete temp;                  
    }
};