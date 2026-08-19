// Last updated: 19/08/2026, 16:04:24
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
//     int kthSmallest(TreeNode* root, int k) {
//         int count = 0;
//         int ans;
//         TreeNode* curr = root;
        
//         while(curr){
//             if(curr->left == NULL){
//                 count++;
//                 if(count == k){
//                     ans = curr->val;
//                 }
                
//                 curr = curr->right;
//             }
//             else{
//                 TreeNode* prev = curr->left;
                
//                 while(prev->right && prev->right != curr){
//                     prev = prev->right;
//                 }
                
//                 if(prev->right == NULL){
//                     prev->right = curr;
//                     curr = curr->left;
//                 }
//                 else{
//                     count++;
//                     prev->right = NULL;
//                     if(count == k){
//                         ans = curr->val;
//                     }
//                     curr = curr->right;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
       void solve(TreeNode* root, int &cnt, int k,  TreeNode* &ans){
           if(root==NULL){
               return;
           }
        //  L  
         solve(root->left,cnt,k,ans);
        //    N
        cnt++;
        if(cnt==k){
            ans=root;
            return ;
        }
        // R
      solve(root->right,cnt,k,ans);

       }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        TreeNode* ans = NULL;
        solve(root,count,k,ans);
        return ans->val;
    }
};