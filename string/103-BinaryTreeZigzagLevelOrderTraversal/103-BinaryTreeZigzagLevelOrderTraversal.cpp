// Last updated: 19/08/2026, 16:09:06
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
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         if(root == NULL){
//             return result;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         bool lTOr= true;
//         while(!q.empty()){
//             int size = q.size();
//             vector<int> row(size);
//             for(int i = 0; i<size; i++){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 //find position to fill node's value
//                 int index = (lTOr) ? i : (size - 1 - i);
//                 row[index] = node->val;
//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                 }
//             }
//             //after this level
//             lTOr = !lTOr;
//             result.push_back(row);
//         }
//         return result;
        
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         if (root == nullptr)
//             return result;

//         queue<TreeNode*> q;
//         q.push(root);
//         bool leftToRight = true;

//         while (!q.empty()) {
//             int levelSize = q.size();
//             vector<int> currentLevel(levelSize);

//             for (int i = 0; i < levelSize; i++) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 int index = leftToRight ? i : levelSize - 1 - i;
//                 currentLevel[index] = node->val;
//                 if (node->left != nullptr) {
//                     q.push(node->left);
//                 }
//                 if (node->right != nullptr) {
//                     q.push(node->right);
//                 }
//             }
//             result.push_back(currentLevel);
//             leftToRight = !leftToRight;
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        deque<TreeNode*> dq;
        dq.push_back(root);
        bool reverse = false;

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                if (!reverse) {
                    TreeNode* node = dq.front(); dq.pop_front();
                    level.push_back(node->val);
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    TreeNode* node = dq.back(); dq.pop_back();
                    level.push_back(node->val);
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }

            res.push_back(level);
            reverse = !reverse;
        }

        return res;
    }
};