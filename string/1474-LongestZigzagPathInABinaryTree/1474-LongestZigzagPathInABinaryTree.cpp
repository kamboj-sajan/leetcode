// Last updated: 19/08/2026, 15:48:52
// class Solution {
// public:
//     int ans = 0;
//     pair<int,int> dfs(TreeNode* root) {
//         if (!root) return {-1, -1};
//         auto left = dfs(root->left);
//         auto right = dfs(root->right);
//         int goLeft = left.second + 1;
//         int goRight = right.first + 1;
//         ans = max({ans, goLeft, goRight});
//         return {goLeft, goRight};
//     }
//     int longestZigZag(TreeNode* root) {
//         dfs(root);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxLen = 0;
//     void f(TreeNode* root, bool isLeft, int steps) {
//         if (!root) return;
//         maxLen = max(maxLen, steps);
//         if (isLeft) {
//             f(root->right, false, steps + 1);
//             f(root->left, true, 1);           
//         } else {
//             f(root->left, true, steps + 1);
//             f(root->right, false, 1);         
//         }
//     }
//     int longestZigZag(TreeNode* root) {
//         if (!root) return 0;
//         f(root->left, true, 1);
//         f(root->right, false, 1);
//         return maxLen;
//     }
// };

class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, bool left, int len) {
        if (!root) return;

        ans = max(ans, len);

        if (left) {
            dfs(root->left, false, len + 1);
            dfs(root->right, true, 1);
        } else {
            dfs(root->right, true, len + 1);
            dfs(root->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, false, 1);
        dfs(root->right, true, 1);
        return ans;
    }
};