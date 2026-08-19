// Last updated: 19/08/2026, 15:57:12
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
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//      if(root == NULL)return new TreeNode(val);
//      TreeNode *cur = root;
//      while(true){
//         if(cur->val <= val){
//             if(cur->right != NULL) cur = cur->right;
//             else{
//                 cur->right = new TreeNode(val);
//                 break;
//             }
//         }else{
//             if(cur->left != NULL)cur = cur->left;
//             else{
//                 cur->left = new TreeNode(val);
//                 break;
//             }
//         }
//      }  
//      return root; 
//     }
// };

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* curr = root;

        while (true) {
            if (val < curr->val) {
                if (curr->left) curr = curr->left;
                else break;
            }
            else {
                if (curr->right) curr = curr->right;
                else break;
            }
        }

        if (val < curr->val) curr->left = new TreeNode(val);
        else curr->right = new TreeNode(val);

        return root;
    }
};