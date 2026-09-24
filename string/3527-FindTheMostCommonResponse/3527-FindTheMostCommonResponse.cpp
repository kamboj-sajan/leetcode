// Last updated: 25/09/2026, 00:59:22
// // class Solution {
// // public:
// //     string findCommonResponse(vector<vector<string>>& responses) {
// //         int n = responses.size();
// //         vector<vector<string>> t;
// //         for(int i=0; i<n; i++){
// //             vector<string> temp;
// //             for(int j=0; j<responses[i].size(); j++){
// //                 if(find(temp.begin(),temp.end(),responses[i][j]) == temp.end()){
// //                     temp.push_back(responses[i][j]);
// //                 }
// //             }
// //             t.push_back(temp);
// //         }
// //         unordered_map<string,int> mpp;
// //         int maxi = INT_MIN;
// //         string ans = "";
// //         for(int i=0; i<n; i++){
// //             for(string &s : t[i]){
// //                 mpp[s]++;
// //                 if(mpp[s] > maxi){
// //                     maxi = mpp[s];
// //                     ans = s;
// //                 }else if(mpp[s] == maxi){
// //                     if(s < ans){
// //                         ans = s;
// //                     }
// //                 }
// //             }
// //         }
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     string findCommonResponse(vector<vector<string>>& responses) {
//         unordered_map<string, int> mpp;
//         int maxi = 0;
//         string ans = "";
//         for (auto &row : responses) {
//             unordered_set<string> seen;
//             for (auto &s : row) {
//                 if (seen.insert(s).second) {
//                     mpp[s]++;
//                     if (mpp[s] > maxi) {
//                         maxi = mpp[s];
//                         ans = s;
//                     }
//                     else if (mpp[s] == maxi && s < ans) {
//                         ans = s;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

const int N = 26, M = 1000;
string s = "";
int f = 0;

struct Trie {
    Trie* next[N];
    int count = 0;

    Trie() { fill(next, next + N, nullptr); }

    void Insert(string& word) {
        Trie* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->next[i])
                node->next[i] = new Trie();
            node = node->next[i];
        }

        int k = ++node->count;
        if (k > f) {
            s = word;
            f = k;
        } else if (k == f && word < s) {
            s = word;
        }
    }
};

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        const int n = responses.size();
        f = 0, s = "";
        Trie t;

        for (int i = 0; i < n; ++i) {
            vector<string>& w = responses[i];
            sort(w.begin(), w.end());
            const int wz = w.size();
            t.Insert(w[0]);

            for (int j = 1; j < wz; ++j)
                if (w[j] != w[j - 1])
                    t.Insert(w[j]);
        }

        return s;
    }
}; // trie karo