// Last updated: 19/08/2026, 15:56:04
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     void markparents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_track, TreeNode* target){
//         queue<TreeNode*> queue;
//         queue.push(root);
//         while(!queue.empty()){
//             TreeNode* current = queue.front();
//             queue.pop();
//             if(current -> left){
//                 parent_track[current->left] = current;
//                 queue.push(current->left);
//             }
//             if(current->right){
//                 parent_track[current->right] = current;
//                 queue.push(current->right);
//             }
//         }
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         unordered_map<TreeNode* , TreeNode*> parent_track; // node->parent
//         markparents(root,parent_track,target);
//         unordered_map<TreeNode* , bool>visited;
//         queue<TreeNode*> queue;
//         queue.push(target);
//         visited[target]=true;
//         int curr_level=0;
//         while(!queue.empty()){/*dusra bfs k level tak jaane kei liye from target node and saath mai hashtable info use karo*/
//         int size = queue.size();
//         if(curr_level++ == k) break;//if(cur_level == k)break;
//                                     //cur_level++;
//         for(int i=0; i<size; i++){
//             TreeNode* current = queue.front(); queue.pop();
//             if(current->left && !visited[current->left]){
//                 queue.push(current->left);
//                 visited[current->left] = true;
//             }
//             if(current->right && !visited[current->right]){
//                 queue.push(current->right);
//                 visited[current->right] = true;
//             }
//             if(parent_track[current] && !visited[parent_track[current]]){
//                 queue.push(parent_track[current]);
//                 visited[parent_track[current]] = true;
//             }
//         }
//         }
//         vector<int> result;
//         while(!queue.empty()){
//             TreeNode* current = queue.front(); queue.pop();
//             result.push_back(current->val);
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
//         //parentNode
//         unordered_map<TreeNode*, TreeNode*>parentMap;

//         //fill the parent of each node is parent map
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             auto frnt = q.front();
//             q.pop();

//             if(frnt->left){
//                 parentMap[frnt->left] = frnt;
//                 q.push(frnt->left);
//             }
//             if(frnt->right){
//                 parentMap[frnt->right] = frnt;
//                 q.push(frnt->right);
//             }
//         }

//         //now start from the targetNode and calc dist to each node
//         // queue<TreeNode*>q;
//         q.push(target);

//         unordered_map<TreeNode*, bool>vis;
//         vis[target] = true;

//         //bfs for k levels from targetNode
//         int currLevel = 0;

//         while(!q.empty()){
//             int sz = q.size();
            
//             if(currLevel == k){
//                 break;
//             }
//             currLevel++;

//             while(sz--){
//                 auto frnt = q.front();
//                 q.pop();

//                 if(frnt->left && vis[frnt->left]==false){
//                     q.push(frnt->left);
//                     vis[frnt->left] = true;
//                 }
//                 if(frnt->right && vis[frnt->right]==false){
//                     q.push(frnt->right);
//                     vis[frnt->right] = true;
//                 }

//                 if(parentMap[frnt] && vis[parentMap[frnt]]==false){
//                     q.push(parentMap[frnt]);
//                     vis[parentMap[frnt]] = true;
//                 }
//             }
//         }

//         vector<int>ans;

//         while(!q.empty()){
//             ans.push_back(q.front()->val);
//             q.pop();
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> nodes;
//     void helper(TreeNode* node, int dif){
//         if (!node || dif<0) return;

//         if (dif==0) nodes.push_back(node->val);

//         helper(node->left, dif-1);
//         helper(node->right, dif-1);
//     }

//     pair<bool, int> dfs(TreeNode* root, TreeNode* target, int k){
//         if (!root) return {false, 0};
//         if (root==target){
//             helper(root, k);
//             return {true, 1};
//         }

//         pair<bool, int> pl = dfs(root->left, target,k);
//         pair<bool, int> pr = dfs(root->right, target,k);
        
//         if (pl.first){
//             int dis = pl.second;
//             if (dis==k){
//                 nodes.push_back(root->val);
//             }
//             else if (dis<k){
//                 helper(root->right, k-dis-1);
//             }
//         }
//         if (pr.first){
//             int dis = pr.second;
//             if (dis==k){
//                 nodes.push_back(root->val);
//             }
//             else if (dis<k){
//                 helper(root->left, k-dis-1);
//             }
//         }        

//         if (pl.first) return {pl.first, pl.second+1};
//         else if (pr.first) return {pr.first, pr.second+1};
//         else return {false, max(pl.second, pr.second)+1};
//     }

//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         dfs(root, target, k);
//         return nodes;
//     }
// };


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> Que;
        Que.push(root);
        while(!Que.empty()){
            TreeNode* node= Que.front();
            Que.pop();
            if(node->left){
                parent[node->left]=node;
                Que.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                Que.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markParent(root,parent);
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        queue<TreeNode*> Que;
        Que.push(target);
        int curr_Level=0;
        while(!Que.empty()){
            int size=Que.size();
            if(curr_Level++ ==k) break;
            for(int i=0;i<size;i++){
                TreeNode* node=Que.front();
                Que.pop();
                if(node->left  && !visited[node->left]){
                    Que.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    Que.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] && !visited[parent[node]]){
                     Que.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
        }
        vector<int> ans;
        while(!Que.empty()){
            TreeNode* temp = Que.front();
            Que.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};