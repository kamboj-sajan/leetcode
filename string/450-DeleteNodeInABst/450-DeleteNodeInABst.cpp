// Last updated: 19/08/2026, 16:01:33
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
 /*
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root == NULL){
        return NULL;
       } 
       if(root->val == key){
        return helper(root);
       }
       TreeNode *dummy = root;
       while(root != NULL){
        if(root->val > key){
            if(root->left != NULL && root->left->val == key){
                root->left = helper(root->left);
                break;
            }else{
                root = root->left;
            }
        }else{
            if(root->right != NULL && root->right->val == key){
                root->right = helper(root->right);
                break;
            }else{
                root = root->right;
            }
        }
       }
       return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        TreeNode* rightchild = root->right;
        TreeNode* lastright = findlastright(root->left);
        lastright->right = rightchild;
        return root->left;
    }
    TreeNode* findlastright(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findlastright(root->right);
    }
};
*/
class Solution {
public:
    TreeNode* findMax(TreeNode* root) {
        while (root->right) root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // node found
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else {
                TreeNode* pred = findMax(root->left);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        return root;
    }
};