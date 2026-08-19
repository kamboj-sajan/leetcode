// Last updated: 19/08/2026, 15:28:33
// // // class Solution {
// // // public:
// // //     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
// // //         int n = arr1.size();
// // //         int m = arr2.size();
// // //         int ans = 0;
// // //         for(int i = 0; i < n; i++){
// // //             string a = to_string(arr1[i]);
// // //             for(int j = 0; j < m; j++){
// // //                 string b = to_string(arr2[j]);
// // //                 int cnt = 0;
// // //                 for(int k = 0; k < min(a.size(), b.size()); k++){
// // //                     if(a[k] == b[k]){
// // //                         cnt++;
// // //                         ans = max(ans, cnt);
// // //                     }else{
// // //                         break;
// // //                     }
// // //                 }
// // //             }
// // //         }
// // //         return ans;
// // //     }
// // // };

// // class Solution {
// // public:
// //     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
// //         int n = arr1.size();
// //         int m = arr2.size();
// //         int ans = 0;
// //         unordered_map<string,int> mpp;
// //         unordered_map<string,int> mpp2;
// //         for(int i=0; i<n; i++){
// //             string a = to_string(arr1[i]);
// //             for(int j=0; j<a.size(); j++){
// //                 mpp[a.substr(0,j+1)]++;
// //             }
// //         }
// //         for(int i=0; i<m; i++){
// //             string a = to_string(arr2[i]);
// //             for(int j=0; j<a.size(); j++){
// //                 mpp2[a.substr(0,j+1)]++;
// //             }
// //         }
// //         for(auto &p : mpp){
// //             if(mpp2.find(p.first) != mpp2.end()){
// //                 ans = max(ans,(int)p.first.size());
// //             }
// //         }
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int ans = 0;
//         unordered_set<string> st;
//         for(int i = 0; i < arr1.size(); i++){
//             string a = to_string(arr1[i]);

//             for(int j = 0; j < a.size(); j++){
//                 st.insert(a.substr(0, j + 1));
//             }
//         }
//         for(int i = 0; i < arr2.size(); i++){
//             string a = to_string(arr2[i]);

//             for(int j = 0; j < a.size(); j++){
//                 string temp = a.substr(0, j + 1);

//                 if(st.find(temp) != st.end()){
//                     ans = max(ans, (int)temp.size());
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    struct TrieNode {
        TrieNode* children[10] = {NULL};
    };
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < arr1.size(); i++){
            string s = to_string(arr1[i]);
            TrieNode* cur = root;
            for(int j = 0; j < s.length(); j++){
                if(cur->children[s[j] - '0'] == NULL){
                    cur->children[s[j] - '0'] = new TrieNode();
                    cur = cur->children[s[j] - '0'];
                }else{
                    cur = cur->children[s[j] - '0'];
                }
            }
        }
        int longest = 0;
        for(int i = 0; i < arr2.size(); i++){
            string s = to_string(arr2[i]);
            TrieNode* cur = root;
            int path = 0;
            for(int j = 0; j < s.length(); j++){
                if(cur->children[s[j] - '0'] != NULL){
                    cur = cur->children[s[j] - '0'];
                    path++;
                }else{
                    break;
                }
            }
            if(path > longest) longest = path;
        }

        return longest;
    }
};