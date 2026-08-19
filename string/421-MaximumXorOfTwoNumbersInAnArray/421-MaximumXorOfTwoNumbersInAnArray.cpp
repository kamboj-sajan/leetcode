// Last updated: 19/08/2026, 16:01:44
// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         int maxa = INT_MIN;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=i; j<nums.size(); j++){
//                 int el = nums[i]^nums[j];
//                 maxa = max(maxa,el);
//             }
//         }
//         return maxa;
//     }
// };
struct Node{
    Node* links[2];
    bool containKey(int bit){
        return (links[bit] != NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
};
class Trie{
private: Node* root;
public:
   Trie(){
    root = new Node();
   }
public:
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
public:
    int getmax(int num){
        Node* node = root;
        int maxnum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(node->containKey(1-bit)){
                maxnum = maxnum | 1<<i;
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxnum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it : nums)trie.insert(it);
        int maxi = 0;
        for(auto &it : nums){
            maxi = max(maxi,trie.getmax(it));
        }
        return maxi;
    }
};