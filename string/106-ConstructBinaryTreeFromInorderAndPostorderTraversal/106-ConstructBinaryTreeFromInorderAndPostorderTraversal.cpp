// Last updated: 19/08/2026, 16:08:59
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
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         if(inorder.size() != postorder.size())
//         return NULL;
//         map<int,int> hm;
//         for(int i = 0; i<inorder.size(); ++i)
//         hm[inorder[i]] = i;
//         return buildtreepostorderin(inorder, 0, inorder.size()-1, postorder, 0, postorder.size() -1 , hm);
//     }
//     TreeNode* buildtreepostorderin(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int,int> &hm){
//         if(ps > pe || is > ie) return NULL;
//         TreeNode* root = new TreeNode(postorder[pe]);
//         int inRoot = hm[postorder[pe]];
//         int numsleft = inRoot - is;
//         root->left = buildtreepostorderin(inorder,is,inRoot-1,postorder,ps,ps+numsleft-1,hm);
//         root->right = buildtreepostorderin(inorder,inRoot+1,ie,postorder,ps+numsleft,pe-1,hm);
//         return root;
//     }
// };

class Solution {
public:
TreeNode* constructBaby(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend, unordered_map<int,int>& mpp){

    if(poststart>postend || instart>inend) return NULL;
    TreeNode* root=new TreeNode(postorder[postend]);
    int inroot=mpp[root->val];
    int numsright=inend-inroot;
    int numsleft=inroot-instart;

    root->right=constructBaby(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,mpp);
    root->left=constructBaby(postorder,poststart,postend-numsright-1,inorder,instart,inroot-1,mpp);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }

        TreeNode* root=constructBaby(postorder,0,n-1,inorder,0,n-1,mpp);
        return root;
    }
};
