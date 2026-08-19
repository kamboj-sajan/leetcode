// Last updated: 19/08/2026, 15:48:34
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* dfs(TreeNode* root, int target){
//         if (!root) return NULL;
//         if (root->val == target)
//             return root;
//         TreeNode* left = dfs(root->left, target);
//         if (left) return left;
//         return dfs(root->right, target);
//     }
// public:
//     TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
//         return dfs(cloned,target->val);
//     }
// };

class Solution {
public:
    TreeNode *ans = nullptr;
    void answer(TreeNode* o,TreeNode* c,TreeNode* t)
    {
        if(o == nullptr) return;
        if(o == t)
        {
            ans = c;
            return;
        }
        answer(o -> left,c -> left,t);
        answer(o -> right,c -> right,t);
    }
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        answer(o,c,t);
        return ans;
    }
};