// Last updated: 19/08/2026, 16:07:22
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* insertCopyNodes(Node* temp){
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode -> next = temp->next;
            temp -> next = copyNode;
            temp = temp->next->next;
        }
        return temp;
    }
public:
    Node* connectRandomPointers(Node* temp){
        while(temp != NULL){
            Node* copyNode = temp -> next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }
            else copyNode->random = NULL;
            temp = temp->next->next;
        }
        return temp;
    }
public:
    Node* getCopy(Node* temp){
        Node* dNode = new Node(-1);
        Node* res = dNode;
        while(temp != NULL){
            res -> next = temp -> next;
            temp -> next = temp->next->next;
            res = res -> next;
            temp = temp -> next;
        }
        return dNode -> next;
    }
public:
    Node* copyRandomList(Node* head) {
        insertCopyNodes(head);
        connectRandomPointers(head);
        return getCopy(head);
    }
};