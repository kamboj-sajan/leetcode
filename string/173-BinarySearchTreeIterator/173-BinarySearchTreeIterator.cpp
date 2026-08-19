// Last updated: 19/08/2026, 16:06:04
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
// class BSTIterator {
//     stack<TreeNode* > mystack;
// public:
//     BSTIterator(TreeNode* root) {
//         pushall(root);
//     }
    
//     int next() {
//         TreeNode* tmp = mystack.top();
//         mystack.pop();
//         pushall(tmp->right);
//         return tmp->val;
//     }
    
//     bool hasNext() {
//         return !mystack.empty();
//     }
// private: 
//     void pushall(TreeNode* node){
//         for(; node!=NULL; mystack.push(node),node = node->left);
//     }
// };

class BSTIterator {
public:
    vector<int> inorder;
    int i = 0;
    int n = 0;
    BSTIterator(TreeNode* root) {
        traverse(root);
    }

    void traverse(TreeNode* root){
        if(root == nullptr)return;
        traverse(root->left);
        inorder.push_back(root->val);
        n++;
        traverse(root->right);
    }
    
    int next() {
        if(i > n)return -1;
        return inorder[i++];
    }
    
    bool hasNext() {
        return i < n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */