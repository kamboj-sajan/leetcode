// Last updated: 25/09/2026, 01:08:50
// class Solution {
// public:
//     bool makeEqual(vector<string>& words) {
//         int n = words.size();
//         unordered_map<char,int> mpp;
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<words[i].size(); ++j){
//                 mpp[words[i][j]]++;
//             }
//         }
//         for(auto &p : mpp){
//             if(p.second%n != 0)return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int freq[26]{};
        for (auto &i: words) {
            for (auto &j: i) {
                freq[j - 'a']++;
            }
        }
        int n = words.size();
        for (int i = 0; i < 26; i++) {
            if (freq[i] % n) return false;
        }
        return true;
    }
};