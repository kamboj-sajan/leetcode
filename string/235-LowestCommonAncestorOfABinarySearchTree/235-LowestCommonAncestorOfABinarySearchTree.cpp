// Last updated: 19/08/2026, 16:04:07
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//          while (root){
//         if (root->val > p->val && root->val > q->val)
//             root = root->left;
//         else if (root->val < q->val && root->val < p->val)
//             root = root->right;
//         else return root;
//          }
//     return NULL;
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(root->val>p->val && root->val<q->val){
            return root;
        }
        else{
            return root;
        }
    }
};