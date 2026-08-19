// Last updated: 19/08/2026, 16:09:28
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
//     bool isValidBST(TreeNode* root) {
//         return isBST(root, LLONG_MIN, LLONG_MAX);
//     }

// private:
//     bool isBST(TreeNode* root, long long minVal, long long maxVal) {
//         if (!root) return true;
//         if (root->val <= minVal || root->val >= maxVal) return false;
//         return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
//     }
// };

class Solution {
public:
    bool validateBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if(root == nullptr) return true;

        if(minNode && minNode->val >= root->val) return false;
        if(maxNode && maxNode->val <= root->val) return false;

        return validateBST(root->left, minNode, root) && validateBST(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) {
        return validateBST(root, nullptr, nullptr);
    }
};