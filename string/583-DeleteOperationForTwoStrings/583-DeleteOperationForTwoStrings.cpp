// Last updated: 19/08/2026, 15:59:47
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        for(int j=0; j<=m; j++)prev[j] = 0;       for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1])cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int p = longestCommonSubsequence(word1,word2);
        return (n+m-(2*p));
    }
};