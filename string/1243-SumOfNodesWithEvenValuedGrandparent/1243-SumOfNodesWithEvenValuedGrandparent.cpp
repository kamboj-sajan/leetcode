// Last updated: 19/08/2026, 15:52:08
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
//     int ans = 0;
//     void dfs(TreeNode* root,TreeNode* parent,TreeNode* grandparent){
//        if(!root)return;
//        if(grandparent && grandparent->val %2 == 0){
//         ans += root->val;
//        }
//        dfs(root->left,root,parent);
//        dfs(root->right,root,parent);
//     }
// public:
//     int sumEvenGrandparent(TreeNode* root) {
//         dfs(root,nullptr,nullptr);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int sumEvenGrandparent(TreeNode* root) {
//     int sum=0;
//         if(root==NULL) return 0;
//         if(root->val%2==0){
//             if(root->left!=NULL && root->left->left!=NULL){
//                 sum+=root->left->left->val;
//             }
//             if(root->left!=NULL && root->left->right!=NULL){
//                 sum+=root->left->right->val;
//             }
//             if(root->right!=NULL && root->right->right!=NULL){
//                sum+=root->right->right->val;
//             }
//             if(root->right!=NULL && root->right->left!=NULL){
//                 sum+=root->right->left->val;
//             }
//         }
//         sum+=sumEvenGrandparent(root->right);
//         sum+=sumEvenGrandparent(root->left);
//         return sum;  
//     }
// };


class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->val % 2 == 0) {
            add(root, 0);
        }
        dfs(root->left);
        dfs(root->right);
    }
    void add(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        if (depth == 2) {
            ans += root->val;
            return;
        }
        add(root->left, depth + 1);
        add(root->right, depth + 1);
    }

    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return ans;
    }
};