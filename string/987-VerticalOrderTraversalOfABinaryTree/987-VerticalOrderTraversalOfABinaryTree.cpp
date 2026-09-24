// Last updated: 25/09/2026, 01:18:02
// // class Solution {
// // public:
// //     vector<vector<int>> verticalTraversal(TreeNode* root) {
// //         vector<vector<int>> ans;
// //         if (root == NULL)
// //             return ans;
// //         // {column, row, node}
// //         queue<tuple<int, int, TreeNode*>> q;
// //         q.push({0, 0, root});
// //         // {column, row, value}
// //         priority_queue<
// //             tuple<int, int, int>,
// //             vector<tuple<int, int, int>>,
// //             greater<tuple<int, int, int>>
// //         > pq;
// //         while (!q.empty()) {
// //             int sz = q.size();
// //             for (int i = 0; i < sz; i++) {
// //                 auto it = q.front();
// //                 q.pop();
// //                 int col = get<0>(it);
// //                 int row = get<1>(it);
// //                 TreeNode* node = get<2>(it);
// //                 // Store {column, row, value}
// //                 pq.push({col, row, node->val});
// //                 if (node->left != NULL) {
// //                     q.push({
// //                         col - 1,
// //                         row + 1,
// //                         node->left
// //                     });
// //                 }
// //                 if (node->right != NULL) {
// //                     q.push({
// //                         col + 1,
// //                         row + 1,
// //                         node->right
// //                     });
// //                 }
// //             }
// //         }
// //         vector<int> temp;
// //         int prevCol = INT_MIN;
// //         while (!pq.empty()) {
// //             auto it = pq.top();
// //             pq.pop();
// //             int col = get<0>(it);
// //             int row = get<1>(it);
// //             int val = get<2>(it); 
// //             // Column changed
// //             if (col != prevCol) {
// //                 if (!temp.empty()) {
// //                     ans.push_back(temp);
// //                     temp.clear();
// //                 }
// //                 prevCol = col;
// //             }
// //             temp.push_back(val);
// //         }
// //         // Push last column
// //         if (!temp.empty()) {
// //             ans.push_back(temp);
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
//     void dfs(TreeNode* root,int col,int row,vector<tuple<int,int,int>>& nodes){
//         if(root==NULL) return;
//         nodes.push_back({col,row,root->val});
//         dfs(root->left,col-1,row+1,nodes);
//         dfs(root->right,col+1,row+1,nodes);
//     }
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<tuple<int,int,int>> nodes;
//         vector<vector<int>> ans;
//         dfs(root,0,0,nodes);
//         sort(nodes.begin(),nodes.end());
//         int prev=INT_MIN;
//         for(auto[col,row,value]:nodes){
//             if(col!=prev){
//                 prev=col;
//                 ans.push_back({});
//             }
//             ans.back().push_back(value);
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first , y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};