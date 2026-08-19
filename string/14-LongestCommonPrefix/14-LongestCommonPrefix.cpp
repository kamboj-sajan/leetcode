// Last updated: 19/08/2026, 16:13:48
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int n = strs[0].size();
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < strs.size() - 1; j++) {
//                 if(i >= strs[j].size() || i >= strs[j + 1].size() ||
//                    strs[j][i] != strs[j + 1][i]) {
//                     return strs[0].substr(0, i);
//                 }
//             }
//         }
//         return strs[0];
//     }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(ans) != 0) {
                ans.pop_back();

                if (ans.empty()) {
                    return "";
                }
            }
        }
        return ans;
    }
};