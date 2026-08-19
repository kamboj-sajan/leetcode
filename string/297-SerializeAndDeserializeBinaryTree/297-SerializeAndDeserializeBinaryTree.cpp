// Last updated: 19/08/2026, 16:03:16
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if (!root) return "#";

//         string s;
//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             TreeNode* curNode = q.front();
//             q.pop();

//             if (curNode == NULL) {
//                 s.append("#,");
//             } else {
//                 s.append(to_string(curNode->val) + ",");
//                 q.push(curNode->left);
//                 q.push(curNode->right);
//             }
//         }
//         return s;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if (data.empty() || data[0] == '#') return NULL;

//         stringstream s(data);
//         string str;

//         getline(s, str, ',');
//         TreeNode* root = new TreeNode(stoi(str));
//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             TreeNode* node = q.front();
//             q.pop();

//             // Left child
//             if (!getline(s, str, ',')) break;
//             if (str == "#") {
//                 node->left = NULL;
//             } else {
//                 TreeNode* leftNode = new TreeNode(stoi(str));
//                 node->left = leftNode;
//                 q.push(leftNode);
//             }

//             // Right child
//             if (!getline(s, str, ',')) break;
//             if (str == "#") {
//                 node->right = NULL;
//             } else {
//                 TreeNode* rightNode = new TreeNode(stoi(str));
//                 node->right = rightNode;
//                 q.push(rightNode);
//             }
//         }

//         return root;
//     }
// };


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s= "";
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL) s.append("#,");
            else s.append(to_string(cur->val)+',');
            if(cur!=NULL){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#") node->left=NULL;
            else{
                TreeNode* lefti=new TreeNode(stoi(str));
                node->left=lefti;
                q.push(lefti);
            }
            getline(s,str,',');
            if(str=="#") node->right==NULL;
            else {
                TreeNode* righti=new TreeNode(stoi(str));
                node->right=righti;
                q.push(righti);
            }
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));