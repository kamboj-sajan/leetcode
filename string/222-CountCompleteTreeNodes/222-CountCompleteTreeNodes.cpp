// Last updated: 19/08/2026, 16:04:39
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
//     void inorder(TreeNode* root,int &cnt){
//         if(root == NULL)return;
//         cnt++;
//         inorder(root->left,cnt);
//         inorder(root->right,cnt);
//     }
// public:
//     int countNodes(TreeNode* root) {
//         int cnt = 0;
//         inorder(root,cnt);
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int findLeftHeight(TreeNode* node){
//         int h = 0;
//         while(node){
//             h++;
//             node = node->left;
//         }
//         return h;
//     }
//     int findRightHeight(TreeNode* node){
//         int h = 0;
//         while(node){
//             h++;
//             node = node->right;
//         }
//         return h;
//     }
// public:
//     int countNodes(TreeNode* root) {
//         if(root == NULL)return 0;
//         int lh = findLeftHeight(root);
//         int rh = findRightHeight(root);
//         if(lh == rh)return (1<<lh)-1;
//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }
// };

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        if(lh==rh){
            return (1<<lh)+countNodes(root->right);
        }
        else{
            return (1<<rh)+countNodes(root->left);
        }
    }
    int height(TreeNode* root){
        int height=0;
        while(root!=nullptr){
            height++;
            root=root->left;
        }
        return height;
    }
};