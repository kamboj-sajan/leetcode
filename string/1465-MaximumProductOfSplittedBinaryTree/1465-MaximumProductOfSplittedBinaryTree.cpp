// Last updated: 19/08/2026, 15:48:56
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
//     using ll = long long;
//     ll Mod = 1e9 + 7;
//     ll totsum = 0;
//     ll best = 0;
//     ll getsum(TreeNode* root){
//         if(!root)return 0LL;
//         return root->val + getsum(root->left) + getsum(root->right);
//     }
//     ll dfs(TreeNode* root){
//         if(!root)return 0;
//         ll left = dfs(root->left);
//         ll right = dfs(root->right);
//         ll subsum = left + right + root->val;
//         best = max(best,subsum *(totsum - subsum));
//         return subsum;
//     }
//     int maxProduct(TreeNode* root) {
//         totsum = getsum(root);
//         dfs(root);
//         return best%Mod;
//     }
// };

class Solution {
public:
    using ll = long long;
    ll Mod = 1e9 + 7;
    ll tot = 0;
    ll ans = 0;
    ll subTreeSum(TreeNode* root){
        if(root == NULL)return 0;
        ll leftsum = subTreeSum(root->left);
        ll rightsum = subTreeSum(root->right);
        ans = max(ans,(leftsum * (tot - leftsum)));
        ans = max(ans,(rightsum * (tot-rightsum)));
        return leftsum + rightsum + root->val;
    }
    void totalsum(TreeNode* root){
        if(root == NULL)return;
        tot += root->val;
        totalsum(root->left);
        totalsum(root->right);
    }
    int maxProduct(TreeNode* root) {
        totalsum(root);
        subTreeSum(root);
        return ans % Mod;
    }
};