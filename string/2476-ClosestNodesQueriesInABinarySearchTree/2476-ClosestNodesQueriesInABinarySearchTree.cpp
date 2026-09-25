// Last updated: 26/09/2026, 03:20:50
// // /**
// //  * Definition for a binary tree node.
// //  * struct TreeNode {
// //  *     int val;
// //  *     TreeNode *left;
// //  *     TreeNode *right;
// //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// //  * };
// //  */
// // class Solution {
// // public: 
// //     int cl(TreeNode* root,int key){
// //         int c = -1;
// //         while(root){
// //             if(root->val == key)return key;
// //             if(root->val < key){
// //                 root = root->right;
// //             }else{
// //                 c = root->val;
// //                 root = root->left;
// //             }
// //         }
// //         return c;
// //     }
// //     int fl(TreeNode* root,int key){
// //         int f = -1;
// //         while(root){
// //             if(root->val == key){
// //                 return key;
// //             }
// //             if(root->val > key)root = root->left;
// //             else{
// //                 f = root->val;
// //                 root = root->right;
// //             }
// //         }
// //         return f;
// //     }
// // public:
// //     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
// //         int n = queries.size();
// //         vector<vector<int>> ans;
// //         for(int i=0; i<n; i++){
// //             int c = cl(root,queries[i]);
// //             int f = fl(root,queries[i]);
// //             ans.push_back({f,c});
// //         }
// //         return ans;
// //     }
// // };

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
//     // Morris Inorder Traversal
//     // Gives BST elements in sorted order
//     void f(vector<int>& vec, TreeNode* root) {

//         TreeNode* cur = root;

//         while(cur) {

//             if(cur->left == NULL) {

//                 vec.push_back(cur->val);
//                 cur = cur->right;

//             } else {

//                 TreeNode* prev = cur->left;

//                 while(prev->right && prev->right != cur) {
//                     prev = prev->right;
//                 }

//                 if(prev->right == NULL) {

//                     // Create thread
//                     prev->right = cur;
//                     cur = cur->left;

//                 } else {

//                     // Remove thread
//                     prev->right = NULL;

//                     vec.push_back(cur->val);
//                     cur = cur->right;
//                 }
//             }
//         }
//     }

//     // Ceiling: smallest element >= key
//     int cl(vector<int>& vec, int key) {

//         int l = 0;
//         int h = vec.size() - 1;

//         int ans = -1;

//         while(l <= h) {

//             int mid = l + (h - l) / 2;

//             if(vec[mid] == key) {
//                 return key;
//             }

//             if(vec[mid] < key) {
//                 l = mid + 1;
//             } 
//             else {
//                 ans = vec[mid];
//                 h = mid - 1;
//             }
//         }

//         return ans;
//     }

//     // Floor: largest element <= key
//     int fl(vector<int>& vec, int key) {

//         int l = 0;
//         int h = vec.size() - 1;

//         int ans = -1;

//         while(l <= h) {

//             int mid = l + (h - l) / 2;

//             if(vec[mid] == key) {
//                 return key;
//             }

//             if(vec[mid] > key) {
//                 h = mid - 1;
//             } 
//             else {
//                 ans = vec[mid];
//                 l = mid + 1;
//             }
//         }

//         return ans;
//     }

//     vector<vector<int>> closestNodes(
//         TreeNode* root,
//         vector<int>& queries
//     ) {

//         vector<int> vec;

//         // Sorted inorder traversal
//         f(vec, root);

//         vector<vector<int>> ans;

//         for(int key : queries) {

//             int floor = fl(vec, key);
//             int ceil = cl(vec, key);

//             ans.push_back({floor, ceil});
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
    void bst(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }
        bst(root->left,arr);
        arr.push_back(root->val);
        bst(root->right,arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>arr;
        bst(root,arr);
        vector<vector<int>>res;
        for(int i=0; i<queries.size();i++){
            int ceil;
            int floor;
            int x=queries[i];
            auto it =lower_bound(arr.begin(),arr.end(),x);
            if(it!=arr.end()){
                ceil=*it;
            }
            else{
                ceil=-1;
            }
            if(it!=arr.end() && *it==x){
                floor=x;
            }
            else if(it!=arr.begin()){
                it--;
                floor=*it;
            }
            else{
                floor=-1;
            }
            res.push_back({floor,ceil});
        }
        return res;
    }
};