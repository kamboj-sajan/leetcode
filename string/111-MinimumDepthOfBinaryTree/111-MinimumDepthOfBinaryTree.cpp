// Last updated: 19/08/2026, 16:08:44
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
//     int ans = INT_MAX;
//     void dfs(TreeNode* root,int dpt){
//         if(!root)return;
//         if(!root->left && !root->right && dpt < ans){
//             ans = dpt;
//         }
//         dfs(root->left,dpt+1);
//         dfs(root->right,dpt+1);
//     }
// public:
//     int minDepth(TreeNode* root) {
//         dfs(root,1);
//         return ans == INT_MAX ? 0 : ans;
//     }
// };

class Solution {
public:
    int minD(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        else if (root->left == nullptr)
            return 1 + minD(root->right);
        else if (root->right == nullptr)
            return 1 + minD(root->left);
        else
            return 1 + min(minD(root->left), minD(root->right));
    }

    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        return minD(root);
    }
};