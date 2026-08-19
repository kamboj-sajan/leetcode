// Last updated: 19/08/2026, 15:54:26
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
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int,map<int,multiset<int>>> nodes;
//         queue<pair<TreeNode* , pair<int,int>>> todo;
//         todo.push({root,{0,0}});
//         while(!todo.empty()){
//             auto p = todo.front();
//             todo.pop();
//             TreeNode* node = p.first;
//             int x = p.second.first , y = p.second.second;
//             nodes[x][y].insert(node->val);
//             if(node->left){
//                 todo.push({node->left,{x-1,y+1}});
//             }
//             if(node->right){
//                 todo.push({node->right,{x+1,y+1}});
//             }
//         }
//         vector<vector<int>> ans;
//         for(auto p : nodes){
//             vector<int> col;
//             for(auto q : p.second){
//                 col.insert(col.end(),q.second.begin(),q.second.end());
//             }
//             ans.push_back(col);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void dfs(TreeNode* v, int d, int w, map<int,multiset<pair<int,int>>> &mp ){
        if(v == NULL) return;
        mp[w].insert({d, v->val});
        dfs(v->left, d+1, w-1, mp);
        dfs(v->right, d+1, w+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>> mp;
        int d = 0; int w = 0;
        dfs(root, 0, 0, mp);
        vector<vector<int>> ans;
        for(auto [a, b] : mp){
            vector<int> col;
            for(auto [c, d]: b) col.push_back(d);
            ans.push_back(col);
        }
        return ans;
    }
};