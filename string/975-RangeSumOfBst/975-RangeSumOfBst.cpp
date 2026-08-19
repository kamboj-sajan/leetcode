// Last updated: 19/08/2026, 15:55:09
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
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         if(!root)return 0;
//         if(low <= root->val && root->val <= high){
//             sum += root->val;
//         }
//         if(root->left != NULL)rangeSumBST(root->left,low,high);
//         if(root->right != NULL)rangeSumBST(root->right,low,high);
//         return sum;
//     }
// };


class Solution {
public:
    vector<int> nums;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root->left);    
        nums.push_back(root->val);
        inorder(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;
        inorder(root);
        int ans = 0;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == low) flag = true;
            if(flag) ans+= nums[i];
            if(nums[i] == high) flag = false;
        }
        return ans;
    }
};