// Last updated: 19/08/2026, 16:08:37
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
//     void flatten(TreeNode* root) {
//         TreeNode *cur = root;
//         while(cur != NULL){
//             if(cur->left != NULL){
//                 TreeNode *prev = cur->left;
//                 while(prev->right){
//                     prev = prev->right;
//                 }
//                 prev->right = cur->right;
//                 cur->right = cur->left;
//                 cur->left = NULL;
//             }
//             cur = cur->right;
//         }
//     }
// };

// ✅ Approach 1: Extra Space
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if (!root) return;
//         vector<TreeNode*> nodes;
//         preorder(root, nodes);
//         for (int i = 0; i < nodes.size() - 1; i++) {
//             nodes[i]->left = nullptr;
//             nodes[i]->right = nodes[i + 1];
//         }
//     }
//     void preorder(TreeNode* node, vector<TreeNode*>& nodes) {
//         if (!node) return;
//         nodes.push_back(node);
//         preorder(node->left, nodes);
//         preorder(node->right, nodes);
//     }
// };

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(root == NULL)return;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode* cur = st.top();
//             st.pop();
//             if(cur->right)st.push(cur->right);
//             if(cur->left)st.push(cur->left);
//             if(!st.empty()){
//                 cur->right = st.top();
//                 cur->left = NULL;
//             }
//         }
//     }
// };


class Solution {
public:
    TreeNode* getLastNode(TreeNode *root){
        if(!root)
            return NULL;
        TreeNode *last=NULL;
        while(root){
            last=root;
            root=root->right;
        }
        return last;
    }
    TreeNode* flattenLL(TreeNode *root){
        if(!root)
            return NULL;
        TreeNode* left=flattenLL(root->left);
        TreeNode* right=flattenLL(root->right);
        
        root->left=NULL;
        TreeNode *temp;
        if(left){
            root->right=left;
            temp=getLastNode(left);
            temp->right=right;
        }
        else
            root->right=right;  
        
        return root;

    }
    void flatten(TreeNode* root) {
        flattenLL(root);
    }
};