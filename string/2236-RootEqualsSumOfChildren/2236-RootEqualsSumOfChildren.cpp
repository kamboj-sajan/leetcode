// Last updated: 25/09/2026, 01:05:32
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool checkTree(TreeNode* root) {
//       if(root == NULL)return true;
//       int sum = 0;
//       if(root->left)sum += root->left->val;
//       if(root->right)sum += root->right->val;
//       if(root->val == sum)return true;
//       else return false;
//       if(checkTree(root->left)&&checkTree(root->right))return true;
//       return false;
//     }
// };

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
class Solution {
public:
    bool checkTree(TreeNode* root) {

        
        if(root->val == root->left->val + root->right->val) return true;

        return false;
        
    }
};