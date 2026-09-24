// Last updated: 25/09/2026, 01:05:42
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
    int ans = 0;
    pair<int,int> dfs(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        int avg = sum/cnt;
        if(avg == root->val)ans++;
        return {sum,cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};