// Last updated: 19/08/2026, 16:09:26
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
// private:
//     TreeNode* first;
//     TreeNode* prev;
//     TreeNode* middle;
//     TreeNode* last;
// private:
//     void inorder(TreeNode* root){
//         if(root == NULL) return;
//         inorder(root->left);
//         if(prev != NULL && (root->val < prev->val))
//         {
//             //first violation mark as first and middle
//             if(first == NULL){
//                 first = prev;
//                 middle = root;
//             }
//             //second violation mark as last
//             else last = root;
//         }
//         // mark node as previous
//         prev = root;
//         inorder(root->right);
//     }
// public:
//     void recoverTree(TreeNode* root) {
//         first = middle = last = NULL;
//         prev = new TreeNode(INT_MIN);
//         inorder(root);
//         if(first && last) swap(first->val, last->val);
//         else if(first && middle)swap(first->val,middle->val);
//     }
// };


class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        helper(root);
        // Swap the values of the two wrong nodes
        swap(first->val, second->val);
    }

    void helper(TreeNode* node) {
        if (!node) return;

        helper(node->left);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }

        prev = node;

        helper(node->right);
    }
};