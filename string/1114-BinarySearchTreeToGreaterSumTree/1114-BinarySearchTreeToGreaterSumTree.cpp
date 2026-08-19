// Last updated: 19/08/2026, 15:53:31
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

//     TreeNode* bstToGst(TreeNode* root) {
//         if (!root) return nullptr;
//         // Visit right subtree first (greater values)
//         bstToGst(root->right);
//         // Update current node
//         sum += root->val;
//         root->val = sum;
//         // Visit left subtree
//         bstToGst(root->left);
//         return root;
//     }
// };

// class Solution {
// public:
//     TreeNode* bstToGst(TreeNode* root) {
//         int totalsum=0;
//         InorderTrav(root,totalsum);
//         Helper(root,totalsum);
//         return root;
//     }
//     void InorderTrav(TreeNode* root,int &totalsum)
//     {
//        if(!root) return ;
//        InorderTrav(root->left,totalsum);
//        totalsum=totalsum+root->val;
//        InorderTrav(root->right,totalsum);
//     }
//     void Helper(TreeNode* &root,int &totalsum)
//     {
//         if(!root) return ;
//         Helper(root->left,totalsum);
//         int rootval=root->val;
//         root->val=totalsum;
//         totalsum=totalsum-rootval;
//         Helper(root->right,totalsum);
//     }
// };


class Solution {
private:
    int sum = 0;

    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->right);  // Traverse the right subtree
            sum += root->val;  // Update the sum
            root->val = sum;  // Update the current node's value
            traverse(root->left);  // Traverse the left subtree
        }
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};