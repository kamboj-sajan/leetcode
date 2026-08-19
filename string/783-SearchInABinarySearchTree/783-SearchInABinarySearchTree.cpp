// Last updated: 19/08/2026, 15:57:20
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
//     TreeNode* searchBST(TreeNode* root, int val) {
//         while(root != NULL && root->val != val){
//             root = val<root->val ? root->left : root->right;
//         }
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val==val){
            return root;
        }
        return val<root->val ? searchBST(root->left,val) : searchBST(root->right,val);
    }
};