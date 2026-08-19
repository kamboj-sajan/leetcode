// Last updated: 19/08/2026, 15:31:30
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
//     void dfs(TreeNode* left,TreeNode* right,int level){
//         if(!left || !right)return;
//         if(level %2 == 1){
//             swap(left->val,right->val);
//         }
//         dfs(left->left,right->right,level+1);
//         dfs(left->right,right->left,level+1);
//     }
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         if(!root)return root;
//         dfs(root->left,root->right,1);
//         return root;
//     }
// };


class Solution {
public:

    void solve(TreeNode* l,TreeNode* r,int level){
        if(l==NULL||r==NULL)
           return;

        if(level%2==1){
            int temp=l->val;
            l->val=r->val;
            r->val=temp;
        }

        solve(l->left,r->right,level+1);
        solve(l->right,r->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left,root->right,1);
        return root;
        
    }
};