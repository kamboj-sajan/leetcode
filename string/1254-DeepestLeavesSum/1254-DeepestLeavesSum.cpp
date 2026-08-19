// Last updated: 19/08/2026, 15:52:00
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
//     map<int,int> mpp;
//     void dfs(TreeNode* root,int level){
//         if(!root)return;
//         mpp[level] += root->val;
//         dfs(root->left,level+1);
//         dfs(root->right,level+1);
//     }
//     int deepestLeavesSum(TreeNode* root) {
//         dfs(root,1);
//         int ans = root->val;
//         int l = 1;
//         for(auto it: mpp){
//             if(it.first > l){
//                 l = it.first;
//                 ans = it.second;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int ans = 0;
    int maxm = 0;
    int lv =0;
    void dfs(TreeNode* root){
        if(!root)return;
        lv++;
        if(!root->left && !root->right){
            if(lv > maxm){
                maxm = lv;
                ans = root->val;
            }else if(lv == maxm){
                ans += root->val;
            }
        }
        dfs(root->left);
        dfs(root->right);
        lv--;
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};