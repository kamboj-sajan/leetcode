// Last updated: 19/08/2026, 15:17:24
// class Solution {
// public:
//     string mapWordWeights(vector<string>& words, vector<int>& weights) {
//         int n = words.size();
//         string s = "";
//         for(int i=0; i<n; ++i){
//             int sz = 0;
//             for(int j=0; j<words[i].size(); ++j){
//                 int c = words[i][j] - 'a';
//                 sz = (sz + weights[c])%26;
//             }
//             s += ('a' + (25-sz));
//         }
//         return s;
//     }
// };

// class Solution {
// public:
//     string mapWordWeights(vector<string>& words, vector<int>& weights) {
//         string ans;
//         for (string &word : words) {
//             int sum = 0;
//             for (char ch : word) {
//                 sum = (sum + weights[ch - 'a']) % 26;
//             }
//             ans += char('z' - sum);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int h = 0;
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            int weight = 0;
            for (int j = 0; j < words[i].size(); j++) {
                weight += weights[words[i][j] - 'a'];
            }
            result += 'z' - (weight%26);
        }
        return result;
    }
};