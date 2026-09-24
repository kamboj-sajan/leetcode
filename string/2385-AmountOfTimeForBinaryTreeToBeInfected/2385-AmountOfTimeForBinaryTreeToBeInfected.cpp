// Last updated: 25/09/2026, 01:05:16
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//         TreeNode* node;
//         int v;
//         void markParent(TreeNode* root,
//                     unordered_map<TreeNode*, TreeNode*>& par) {

//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty()) {
//             TreeNode* it = q.front();
//             q.pop();
//             if(it->val == v)node = it;
//             if(it->left) {
//                 par[it->left] = it;
//                 q.push(it->left);
//             }

//             if(it->right) {
//                 par[it->right] = it;
//                 q.push(it->right);
//             }
//         }
//     }
// public:
//     int amountOfTime(TreeNode* root, int start) {
//         v = start;
//         if(root == NULL)return 0;
//         unordered_map<TreeNode*,TreeNode*> par;
//         markParent(root,par);
//         if(root==NULL)return 0;
//         unordered_map<TreeNode*,bool> vis;
//         queue<TreeNode*> q;
//         q.push(node);
//         int ans = 0;
//         vis[node] = true;
//         while(!q.empty()){
//             int sz = q.size();
//             bool inf = false;
//             for(int i=0; i<sz; i++){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if(node->left && !vis[node->left]){
//                     q.push(node->left);
//                     vis[node->left] = true;
//                     inf = true;
//                 }
//                 if(node->right && !vis[node->right]){
//                     q.push(node->right);
//                     vis[node->right] = true;
//                     inf = true;
//                 }
//                 if(par[node] && !vis[par[node]]){
//                     q.push(par[node]);
//                     vis[par[node]] = true;
//                     inf = true;
//                 }
//             }
//             if(inf)ans++;
//         }
//         return ans;
//     }
// };


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

    int hgt( TreeNode* root){
        if(!root) return 0 ; 
        return 1 + max(hgt(root->left) , hgt(root->right)) ; 
    }

    int time(TreeNode* root , int target , int& ans){
        if(!root) return 0 ;

        if(root->val == target){
            ans = max(ans , hgt(root)-1) ;
            return -1 ;
        } 

        int left = time(root->left , target ,ans) ; 
        int right = time(root->right , target , ans) ; 

        if( left >= 0 && right >= 0 ){
            return 1 + max(left , right ) ;
        } 
        if(left < 0){
            ans = max(ans , abs(left) + abs(right)) ;
            return left-1 ;
        }
        else{
            ans = max(ans , abs(left) + abs(right)) ;
            return right-1 ;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        int ans = 0 ; 
        time(root , start , ans) ; 

        return ans ; 
    }
};