// Last updated: 19/08/2026, 15:58:48
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
//  class BSTIterator {
//     stack<TreeNode* > mystack;
//     // reverse->true -> before
//     // reverse->false -> next
//     bool reverse = true;
// public:
//     BSTIterator(TreeNode* root , bool isReverse) {
//         reverse = isReverse;
//         pushall(root);
//     }
//     // @retuen whether we have a next smallest number
//     int next() {
//         TreeNode* tmp = mystack.top();
//         mystack.pop();
//         if(!reverse)pushall(tmp->right);
//         else pushall(tmp->left);
//         return tmp->val;
//     }
    
//     bool hasNext() {
//         return !mystack.empty();
//     }
// private: 
//     void pushall(TreeNode* node){
//        for(;node != NULL;){
//         mystack.push(node);
//         if(reverse == true){
//             node = node->right;
//         }else{
//             node = node->left;
//         }
//        }
//     }
// };
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         if(!root) return false;
//         // next
//         BSTIterator l(root,false);
//         // before
//         BSTIterator r(root,true);
//         int i = l.next();
//         int j = r.next(); // r.before()
//         while(i<j){
//             if(i + j == k)return true;
//             else if(i + j < k)i = l.next();
//             else j = r.next();
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     vector<int> ans;
//     bool solve(int k) {
//         int i = 0;
//         int j = ans.size() - 1;

//         while (i < j) {
//             int sum = ans[i] + ans[j];

//             if (sum == k)
//                 return true;
//             else if (sum < k)
//                 i++;
//             else
//                 j--;
//         }
//         return false;
//     }

//     void treeToVector(TreeNode* root) {
//         if (!root) {
//             return ;
//         }
//         treeToVector(root->left);
//         ans.push_back(root->val);
//         treeToVector(root->right);
//     }
//     bool findTarget(TreeNode* root, int k) {
//         treeToVector(root);
//         return solve(k);
//     }
// };


// class Solution {
//     stack<TreeNode*> st1, st2;

//     void push1(TreeNode* root) {
//         while (root) {
//             st1.push(root);
//             root = root->left;
//         }
//     }

//     void push2(TreeNode* root) {
//         while (root) {
//             st2.push(root);
//             root = root->right;
//         }
//     }

// public:
//     bool findTarget(TreeNode* root, int k) {
//         if (!root) return false;

//         push1(root);
//         push2(root);

//         while (!st1.empty() && !st2.empty()) {
//             TreeNode* a = st1.top();
//             TreeNode* b = st2.top();

//             if (a == b) break;

//             int sum = a->val + b->val;

//             if (sum == k) return true;

//             if (sum < k) {
//                 st1.pop();
//                 push1(a->right);
//             } else {
//                 st2.pop();
//                 push2(b->left);
//             }
//         }

//         return false;
//     }
// };


class Solution {
    unordered_map<int, int> mp;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        if(findTarget(root->left, k)) return true;;
        if(mp.find(k-root->val) != mp.end()) return true;
        mp[root->val] = 1;
        if(findTarget(root->right, k)) return true;

        return false;
    }
};