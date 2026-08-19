// Last updated: 19/08/2026, 16:08:05
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
//     int maxPathSum(TreeNode* root) {
//         int maxi = INT_MIN;
//         maxpath2(root,maxi);
//         return maxi;
//     }
//     int maxpath2(TreeNode* node, int& maxi){
//         if(node == NULL)return 0;
//         int left = max(0,maxpath2(node->left,maxi));
//         int right= max(0,maxpath2(node->right,maxi));
//         maxi = max(maxi,left+right+node->val);
//         return max(left,right)+node->val;
//     }
// };

class Solution {
public:
    int helper(TreeNode* root, int &maxSum)
    {
        if(root == nullptr) return 0;

        int leftMaxSum = max(0, helper(root -> left, maxSum)); 
        int rightMaxSum = max(0, helper(root -> right, maxSum));

        maxSum = max(maxSum, leftMaxSum + rightMaxSum + root -> val);

        return max(leftMaxSum, rightMaxSum) + root -> val; 
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
};