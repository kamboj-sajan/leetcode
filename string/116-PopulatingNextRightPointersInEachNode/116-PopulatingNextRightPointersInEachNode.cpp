// Last updated: 13/10/2026, 11:00:08
// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };
// */

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(!root)return root;
//         queue<Node*> q;
//         q.push(root);
//         while(!q.empty()){
//             int sz = q.size();
//             for(int i=0; i<sz; i++){
//                 Node* node = q.front();
//                 q.pop();
//                 if(i == sz-1){
//                     node->next = NULL;
//                 }else{
//                     node->next = q.front();
//                 }
//                 if(node->left)q.push(node->left);
//                 if(node->right)q.push(node->right);
//             }
//         }
//         return root;
//     }
// };

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {  // O(n) T.C.
        if(root == NULL || root->left == NULL){
            return root ;
        }
        queue<Node*> q;
        q.push(root) ;
        q.push(NULL) ;

        Node* prev = NULL ;

        while(q.size() > 0){
            Node* curr = q.front() ;
            q.pop() ;

            if(curr == NULL){
             if(q.size() == 0){
                break ;
             }

             q.push (NULL) ;

            } else {
                if(curr->left != NULL) {
                    q.push(curr->left) ;
                }

                if(curr->right != NULL){
                    q.push(curr->right) ;
                }

                if(prev != NULL){
                    prev->next = curr ;
                }
            }
            prev = curr ;
        }
        return root ;

    }
};