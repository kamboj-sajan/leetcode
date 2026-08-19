// Last updated: 19/08/2026, 15:51:34
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
    void inorder(TreeNode* root, vector<int>& vals) {
    if (!root) return;
    inorder(root->left, vals);
    vals.push_back(root->val);
    inorder(root->right, vals);
}
    TreeNode* build(int l, int r, vector<int>& vals) {
    if (l > r) return nullptr;
    
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(vals[mid]);
    
    root->left = build(l, mid - 1, vals);
    root->right = build(mid + 1, r, vals);
    
    return root;
}

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return build(0, vals.size() - 1, vals);
    }
};