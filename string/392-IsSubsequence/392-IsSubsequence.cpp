// Last updated: 19/08/2026, 16:02:16
// class Solution {
// public:
//     bool f(int i, int j, string &s, string &t) {
//         if (i == s.size()) return true;
//         if (j == t.size()) return false;
//         if (s[i] == t[j]) {
//             return f(i + 1, j + 1, s, t);
//         }
//         return f(i, j + 1, s, t);
//     }

//     bool isSubsequence(string s, string t) {
//         return f(0, 0, s, t);
//     }
// };

// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int i  = 0 ,j = 0;
//         while(i < s.size() && j < t.size()){
//             if(s[i] == t[j]){
//                 i++;
//                 j++;
//             }else j++;
//         }
//         return (i == s.size())?true: false;
//     }
// };

class Solution {
public:
    vector<vector<int>> dp;

    bool f(int i, int j, string &s, string &t) {
        if (i == s.size()) return true;
        if (j == t.size()) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = f(i + 1, j + 1, s, t);
        }

        return dp[i][j] = f(i, j + 1, s, t);
    }

    bool isSubsequence(string s, string t) {
        dp.assign(s.size(), vector<int>(t.size(), -1));
        return f(0, 0, s, t);
    }
};