// Last updated: 19/08/2026, 16:09:21
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     bool isMirror(TreeNode* a, TreeNode* b){
//         if(a == NULL && b == NULL)return true;
//         if(a == NULL || b == NULL)return false;
//         if(a->val != b->val)return false;
//         return isMirror(a->left,b->right) && isMirror(a->right,b->left);
//     }
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL)return true;
//         return isMirror(root->left,root->right);
//     }
// };


class Solution {
public:

    // bool isMirror(TreeNode* n1, TreeNode* n2) {
    //     if (n1 == NULL && n2 == NULL) {
    //         return true;
    //     }
    //     if (n1 == NULL || n1 == NULL) {
    //         return false;
    //     }
    //     return n1->val == n2-> val && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    // }
    // bool isSymmetric(TreeNode* root) {
    //     return isMirror(root->left, root->right);
    // }

    // bool isSymmetric(TreeNode* root) {
    //     if (root == NULL) {
    //         return true;
    //     }

    //     queue<TreeNode*> myQueue;

    //     myQueue.push(root->left);
    //     myQueue.push(root->right);

    //     while (!myQueue.empty()) {
    //         TreeNode* left = myQueue.front();
    //         myQueue.pop();
    //         TreeNode* right = myQueue.front();
    //         myQueue.pop();

    //         if (left == NULL && right == NULL) {
    //             return true;
    //         }
    //         if (left == NULL || right == NULL) {
    //             return false;
    //         }
    //         if (left->val != right->val) {
    //             return false;
    //         }
    //         myQueue.push(left->left);
    //         myQueue.push(right->right);
    //         myQueue.push(left->right);
    //         myQueue.push(right->left);
    //     }

    //     return true;
    // }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            TreeNode* q = st.top(); st.pop();
            TreeNode* p = st.top(); st.pop();
            if(!p && !q) continue;
            if(!p || !q || p->val != q->val) return false;
            st.push(p->left);
            st.push(q->right);
            st.push(p->right);
            st.push(q->left);
        }
        return true;
    }
};