// Last updated: 19/08/2026, 16:00:25
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
//     int sum = 0;
//     TreeNode* convertBST(TreeNode* root) {
//         if(!root)return nullptr;
//         convertBST(root->right);
//         sum += root->val;
//         root->val = sum;
//         convertBST(root->left);
//         return root;
//     }
// };


class Solution {
public:
    int currSum = 0;
    void compute(TreeNode* root) {
        if(!root) return;
        compute(root->right);
        currSum+=root->val;
        root->val = currSum;
        compute(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        compute(root);
        return root;
    }
};