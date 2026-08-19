// Last updated: 19/08/2026, 16:09:44
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
    vector<int> inorderTraversal(TreeNode* root) {
       /* stack<TreeNode*> st;
        TreeNode* Node = root;
        vector<int> Inorder;
        while(true){
            if(Node != NULL){
                st.push(Node);
                Node = Node -> left;
            }
            else{
                if(st.empty() == true)break;
                Node = st.top();
                st.pop();
                Inorder.push_back(Node -> val);
                Node = Node -> right;
            }
        }
        return Inorder;*/
        // morris inorder 
        vector<int> inorder;
        TreeNode *cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode *prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right  = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};