// Last updated: 19/08/2026, 15:37:16
// struct Node{
//     Node* links[2];
//     bool containKey(int bit){
//         return (links[bit] != NULL);
//     }
//     Node* get(int bit){
//         return links[bit];
//     }
//     void put(int bit,Node* node){
//         links[bit] = node;
//     }

//     ~Node() {
//         delete links[0];
//         delete links[1];
//     }
// };
// class Trie{
// private: Node* root;
// public:
//    Trie(){
//     root = new Node();
//    }
//      ~Trie() {
//         delete root;
//     }
//      bool isEmpty() {
//     return (root->links[0] == nullptr && root->links[1] == nullptr);
// }
// public:
//     void insert(int num){
//         Node* node = root;
//         for(int i=31; i>=0; i--){
//             int bit = (num>>i) & 1;
//             if(!node->containKey(bit)){
//                 node->put(bit,new Node());
//             }
//             node = node->get(bit);
//         }
//     }
// public:
//     int getmax(int num){
//         Node* node = root;
//         int maxnum = 0;
//         for(int i=31; i>=0; i--){
//             int bit = (num>>i) & 1;
//             if(node->containKey(1-bit)){
//                 maxnum = maxnum | 1<<i;
//                 node = node->get(1-bit);
//             }
//             else{
//                 node = node->get(bit);
//             }
//         }
//         return maxnum;
//     }
//     void clear() {
//         delete root;
//         root = new Node();
//     }
// };
// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<int> ans;
//         Trie trie;
//         for(int i=0; i<queries.size(); i++){
//             trie.clear();
//             for(auto it : nums){
//                 if(it <= queries[i][1]){
//                 trie.insert(it);
//                 }
//             }
//             if(trie.isEmpty())ans.push_back(-1);
//             else ans.push_back(trie.getmax(queries[i][0]));

//         }
//         return ans;
//     }
// };tle

// struct Node{
//     Node* links[2];
//     bool containKey(int bit){
//         return (links[bit] != NULL);
//     }
//     Node* get(int bit){
//         return links[bit];
//     }
//     void put(int bit,Node* node){
//         links[bit] = node;
//     }
// };
// class Trie{
// private: Node* root;
// public:
//    Trie(){
//     root = new Node();
//    }
// public:
//     void insert(int num){
//         Node* node = root;
//         for(int i=31; i>=0; i--){
//             int bit = (num>>i) & 1;
//             if(!node->containKey(bit)){
//                 node->put(bit,new Node());
//             }
//             node = node->get(bit);
//         }
//     }
// public:
//     int getmax(int num){
//         Node* node = root;
//         int maxnum = 0;
//         for(int i=31; i>=0; i--){
//             int bit = (num>>i) & 1;
//             if(node->containKey(1-bit)){
//                 maxnum = maxnum | 1<<i;
//                 node = node->get(1-bit);
//             }
//             else{
//                 node = node->get(bit);
//             }
//         }
//         return maxnum;
//     }
// };
// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//        sort(nums.begin(),nums.end());
//        vector<pair<int,pair<int,int>>> oQ;
//        int q = queries.size();
//        for(int i=0; i<q; i++){
//         oQ.push_back({queries[i][1],{queries[i][0],i}});
//        }
//        sort(oQ.begin(),oQ.end());
//        vector<int> ans(q,0);
//        int ind = 0;
//        int n = nums.size();
//        Trie trie;
//        for(int i=0; i<q; i++){
//         int ai = oQ[i].first;
//         int xi = oQ[i].second.first;
//         int qind = oQ[i].second.second;
//         while(ind < n && nums[ind] <= ai){
//             trie.insert(nums[ind]);
//             ind++;
//         }
//         if(ind == 0)ans[qind] = -1;
//         else ans[qind] = trie.getmax(xi);
//        }
//        return ans;
//     }
// };


// if we use struct instead of vector for storing queries
struct Node {
    Node* links[2];
    Node() { links[0] = links[1] = nullptr; } 

    bool containKey(int bit) { return (links[bit] != nullptr); }
    Node* get(int bit) { return links[bit]; }
    void put(int bit, Node* node) { links[bit] = node; }
};

class Trie {
private:
    Node* root;
public:
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getmax(int num) {
        Node* node = root;
        int maxnum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containKey(1 - bit)) {
                maxnum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxnum;
    }
};


struct Query {
    int ai;  
    int xi;   
    int idx;  
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        int q = queries.size();
        vector<Query> oQ(q);
        for (int i = 0; i < q; i++) {
            oQ[i] = {queries[i][1], queries[i][0], i};
        }

        
        sort(oQ.begin(), oQ.end(), [](const Query& a, const Query& b) {
            return a.ai < b.ai;
        });

        vector<int> ans(q, 0);
        int ind = 0, n = nums.size();
        Trie trie;

       
        for (int i = 0; i < q; i++) {
            while (ind < n && nums[ind] <= oQ[i].ai) {
                trie.insert(nums[ind]);
                ind++;
            }
            if (ind == 0) ans[oQ[i].idx] = -1;
            else ans[oQ[i].idx] = trie.getmax(oQ[i].xi);
        }
        return ans;
    }
};