// Last updated: 19/08/2026, 15:58:56
// class Solution {
// public:
//     int f(int i,int prv,vector<vector<int>> &pairs,vector<vector<int>> &dp){
//         if(i == pairs.size()){
//             return 0;
//         }
//         if(dp[i][prv+1] != -1)return dp[i][prv];
//         int len = 0 + f(i+1,prv,pairs,dp);
//         if(prv == -1 || pairs[prv][1] < pairs[i][0]){
//             len = 1 + f(i+1,i,pairs,dp);
//         }
//         return dp[i][prv+1] = len;
//     }
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(),pairs.end());
//         int n = pairs.size();
//         vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
//         return f(0,-1,pairs,dp);
//     }
// };

// class Solution {
// public:
//     int f(int i, int prv, vector<vector<int>>& pairs,
//         vector<vector<int>>& dp) {
//         if (i == pairs.size()) return 0;
//         if (dp[i][prv + 1] != -1)
//             return dp[i][prv + 1];
//         int notTake = f(i + 1, prv, pairs, dp);
//         int take = 0;
//         if (prv == -1 || pairs[prv][1] < pairs[i][0]) {
//             take = 1 + f(i + 1, i, pairs, dp);
//         }
//         return dp[i][prv + 1] = max(take, notTake);
//     }

//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end());

//         int n = pairs.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));

//         return f(0, -1, pairs, dp);
//     }
// };



// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end(),[](auto &a ,auto &b){
//             return a[1]<b[1];
//         });
//         int n = pairs.size();
//         int prv = INT_MIN;
//         int cnt = 0;
//         for(int i=0; i<n; ++i){
//             if(pairs[i][0] > prv){
//                 cnt++;
//                 prv = pairs[i][1];
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
            });

        int count = 0;
        int lastEnd = INT_MIN;

        for (auto& pair : pairs) {
            if (lastEnd < pair[0]) {
                count++;
                lastEnd = pair[1];
            }
        }

        return count;
    }
};