// Last updated: 19/08/2026, 15:49:31
class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minimumDistance(string word) {
        int n = word.size();
        // dp[f1][f2]
        vector<vector<int>> dp(27, vector<int>(27, 1e9));
        dp[26][26] = 0; // 26 means unused
        
        for (char ch : word) {
            int cur = ch - 'A';
            vector<vector<int>> new_dp(27, vector<int>(27, 1e9));
            
            for (int f1 = 0; f1 <= 26; f1++) {
                for (int f2 = 0; f2 <= 26; f2++) {
                    if (dp[f1][f2] == 1e9) continue;
                    
                    // Move finger 1
                    int cost1 = dp[f1][f2] + dist(f1 == 26 ? -1 : f1, cur);
                    new_dp[cur][f2] = min(new_dp[cur][f2], cost1);
                    
                    // Move finger 2
                    int cost2 = dp[f1][f2] + dist(f2 == 26 ? -1 : f2, cur);
                    new_dp[f1][cur] = min(new_dp[f1][cur], cost2);
                }
            }
            
            dp = new_dp;
        }
        
        int ans = 1e9;
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                ans = min(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};