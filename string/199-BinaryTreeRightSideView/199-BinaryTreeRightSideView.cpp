// Last updated: 19/08/2026, 16:05:25
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
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         recursion(root , 0 , ans);
//         return ans;
//     }
//     void recursion(TreeNode* root, int level, vector<int>& ans){
//         if(root == NULL) return;
//         if(ans.size() == level)ans.push_back(root -> val);
//         recursion(root->right, level + 1 , ans);
//         recursion(root->left , level + 1 , ans);
//     }
// };

// class Solution {
//     void computeRightSideView(TreeNode* root, int lvl, vector<int>&ans){
//         if(root==nullptr) return;

//         if(lvl == ans.size()) ans.push_back(root->val);
//         computeRightSideView(root->right, lvl+1, ans);
//         computeRightSideView(root->left, lvl+1, ans);
//     }
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int>ans;
//         if(root==nullptr) return ans;
//         computeRightSideView(root, 0, ans);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            // process one level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                // if its the last node at this level
                // record it
                if (i == size - 1) result.push_back(node->val);
                // now add children to queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};