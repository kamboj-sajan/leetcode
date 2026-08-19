// Last updated: 19/08/2026, 15:53:18
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
//     vector<int> sum={INT_MIN};
//     void dfs(TreeNode* Node, int level=1){
//         if (Node==NULL) return;
//         if (sum.size()==level) sum.push_back(Node->val);
//         else sum[level]+=Node->val;
//         dfs(Node->left, level+1);
//         dfs(Node->right, level+1);
//     }
//     int maxLevelSum(TreeNode* root) {
//         dfs(root);
//         return max_element(sum.begin(), sum.end())-sum.begin();
        
//     }
// };

// class Solution {
// public:    
//     int maxLevelSum(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         int l = 1;
//         int ans = 1;
//         int sum = root->val;
//         while(!q.empty()){
//             int temp = 0;
//             int sz = q.size();
//             for(int i=0; i<sz; ++i){
//                 auto node = q.front();
//                 q.pop();
//                 if(node->left != NULL)q.push(node->left);
//                 if(node->right != NULL)q.push(node->right);
//                 temp += node->val;
//             }
//             if(temp > sum){
//                 ans = l;
//                 sum = temp;
//             }
//             l++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         int level = 1;
//         int ans = 1;
//         int maxSum = root->val;
//         while (!q.empty()) {
//             int sz = q.size();   // FIX 1
//             int currSum = 0;
//             for (int i = 0; i < sz; ++i) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 currSum += node->val;
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//             if (currSum > maxSum) {   // FIX 2
//                 maxSum = currSum;
//                 ans = level;
//             }
//             level++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     map<int,int> mpp;
//     void dfs(TreeNode* root,int curlevel){
//         if(!root)return;
//         mpp[curlevel] += root->val;
//         dfs(root->left,curlevel+1);
//         dfs(root->right,curlevel+1);
//     }
// public:
//     int maxLevelSum(TreeNode* root) {
//         mpp.clear();
//         dfs(root,1);
//         int maxsum = INT_MIN;
//         int res = 0;
//         for(auto it : mpp){
//             int level = it.first;
//             int sum = it.second;
//             if(sum > maxsum){
//                 maxsum = sum;
//                 res = level;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level = 1 ;
        int levelModified = 0; 
        int levelSum = INT_MIN ;
        queue<TreeNode*> q ;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            levelModified++ ; 
            int sum = 0  ; 
            while(size--){
                TreeNode* frontNode = q.front();
                sum = sum + frontNode->val;
                q.pop();

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            if(sum>levelSum){
                levelSum = sum ; 
                level = levelModified ; 
            }
        }
        return level ; 
        
    }
};