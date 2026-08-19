// Last updated: 19/08/2026, 16:09:02
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
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//       map<int,int> inmap;
//       for(int i=0; i<inorder.size(); i++){
//         inmap[inorder[i]] = i;
//       }  
//       TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder,0,inorder.size()-1,inmap);
//       return root;
//     }
//     TreeNode* buildTree(vector<int>& preorder , int prestart, int preEnd, vector<int>& inorder,int instart,int inEnd,map<int,int> &inmap){
//         if(prestart > preEnd || instart > inEnd) return NULL;
//         TreeNode* root = new TreeNode(preorder[prestart]);
//         int inRoot = inmap[root->val];
//         int numsleft = inRoot - instart;
//         root->left = buildTree(preorder,prestart+1,prestart+numsleft,inorder,instart,inRoot-1,inmap);
//         root->right = buildTree(preorder,prestart+numsleft+1,preEnd,inorder,inRoot+1,inEnd,inmap);
//         return root;
//     }
// };




// class Solution {
// public:

//     TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx){
//         if(start > end) return NULL;

//         int rootVal = preorder[idx];

//         for(int i = start; i <= end; i++){
//             if(inorder[i] == rootVal) break;
//         }
//         idx++;

//         TreeNode* root = new TreeNode(rootVal);
//         root->left = solve(preorder, inorder, start, i-1, idx);
//         root->right = solve(preorder, inorder, i+1, end, idx);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         int idx = 0;

//         return solve(preorder, inorder, 0, n-1, idx);
//     }
// };










class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end){
        if(start > end) return NULL;

        int rootVal = preorder[idx++];

        //find rootVal in inorder
        int i = mp[rootVal];
        // for(; i <= end; i++){
        //     if(inorder[i] == rootVal) break;
        // }

        TreeNode* root = new TreeNode(rootVal);

        root->left = solve(preorder, inorder, idx, start, i-1);
        root->right = solve(preorder, inorder, idx, i+1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, idx, 0, n-1);
    }
};