// Last updated: 19/08/2026, 16:03:43
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
//     void dfs(TreeNode* node,string path,vector<string> &ans){
//         if(!node)return;
//         path += to_string(node->val);
//         if(node->left == NULL && !node->right){
//             ans.push_back(path);
//             return;
//         }
//         path += "->";
//         dfs(node->left,path,ans);
//         dfs(node->right,path,ans);
//     }
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> ans;
//         dfs(root,"",ans);
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         string arrow="->";
//         vector<string> path;
//         string node="";
//         traversal(root,node,path);
//         return path;
//     }
//     void traversal(TreeNode* root,string node,vector<string>& path){
//         if(root==nullptr){      //check for no root
//             return;
//         }
//        //if root->add it 
//         node+=to_string(root->val);   
        
//         if(root->left==NULL && root->right==NULL){    //if leaf node->return the path
//             path.push_back(node);
//             return;
//         }
//         node+="->";   //here because the if block check for leaf node. There should not be arrows after leaf node.
//         traversal(root->left,node,path);
//         traversal(root->right,node,path);

//     }
// };

// class Solution {
// public:
//     void findPath(TreeNode* node, vector<string>& ans, string temp) {
//         temp += to_string(node->val);  // Add the current node value to the path
//         if (node->left) findPath(node->left, ans, temp + "->");  // Traverse left
//         if (node->right) findPath(node->right, ans, temp + "->"); // Traverse right
//         if (!node->left && !node->right) ans.push_back(temp);  // Add path if leaf node
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> ans;
//         if (root) findPath(root, ans, "");  // Start traversal from the root
//         return ans;
//     }
// };

class Solution {
    public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        dfs(root, path, result);
        return result;
    }
    void dfs(TreeNode* node, vector<int>& path, vector<string>& result) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            string pathStr;
            for (int i = 0; i < path.size(); ++i) {
                pathStr += to_string(path[i]);
                if (i < path.size() - 1) {
                    pathStr += "->";
                }
            }
            result.push_back(pathStr);
        } else {
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }
        path.pop_back();
    }

};