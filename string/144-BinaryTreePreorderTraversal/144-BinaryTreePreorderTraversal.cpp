// Last updated: 19/08/2026, 16:07:05
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
//     vector<int> preorderTraversal(TreeNode* root) {
//        /* vector<int> preorder;
//         if(root == NULL)return preorder;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             root = st.top();
//             st.pop();
//             preorder.push_back(root -> val);
//             if(root -> right != NULL){
//                 st.push(root->right);
//             }
//             if(root->left != NULL){
//                 st.push(root->left);
//             }
//         }
//         return preorder;*/
//          // morris preorder 
//         vector<int> preorder;
//         TreeNode *cur = root;
//         while(cur != NULL){
//             if(cur->left == NULL){
//                 preorder.push_back(cur->val);
//                 cur = cur->right;
//             }
//             else{
//                 TreeNode *prev = cur->left;
//                 while(prev->right && prev->right != cur){
//                     prev = prev->right;
//                 }
//                 if(prev->right == NULL){
//                     prev->right  = cur;
//                     preorder.push_back(cur->val);
//                     cur = cur->left;
//                 }
//                 else{
//                     prev->right = NULL;
//                     cur = cur->right;
//                 }
//             }
//         }
//         return preorder;
//     }
// };


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    nodes.push_back(root -> val);
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};