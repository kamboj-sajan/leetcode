// Last updated: 19/08/2026, 16:01:03
// class Solution {
// public:
//     int ans = 0;
//     void f(int ind, vector<string>& strs, int m, int n, int temp, int one, int zero) {
//         if (zero > m || one > n) return;
//         ans = max(ans, temp);
//         if (ind >= strs.size()) return;
//         int t0 = 0, t1 = 0;
//         for (char c : strs[ind]) {
//             if (c == '1') t1++;
//             else t0++;
//         }
//         f(ind + 1, strs, m, n, temp + 1, one + t1, zero + t0);
//         f(ind + 1, strs, m, n, temp, one, zero);
//     }

//     int findMaxForm(vector<string>& strs, int m, int n) {
//         f(0, strs, m, n, 0, 0, 0);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int ans = 0;
//     void f(int ind, vector<string>& strs,int m,int n,int temp,int one,int zero,vector<vector<vector<int>>> &dp) {
//         if (zero > m || one > n) return; 
//         if (ind >= strs.size()) {
//             ans = max(ans, temp);
//             return;
//         }
//         if(dp[ind][zero][one] != -1 && dp[ind][zero][one] >= temp)return;
//         dp[ind][zero][one] = temp;
//         ans = max(ans,temp);
//         int t0 = 0, t1 = 0;
//         for (char c : strs[ind]) {
//             if (c == '1') t1++;
//             else t0++;
//         }
//         f(ind + 1, strs, m, n, temp + 1, one + t1, zero + t0,dp);
//         f(ind + 1, strs, m, n, temp, one, zero,dp);
//     }

//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
//         f(0, strs, m, n, 0, 0, 0,dp);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//         for(auto &s : strs){
//             int zeros = count(s.begin(),s.end(),'0');
//             int ones = s.size() - zeros;
//             for(int i=m; i>=zeros; --i){
//                 for(int j=n; j>=ones; --j){
//                     dp[i][j] = max(dp[i][j],dp[i-zeros][j-ones]+1);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };

class Solution {
public:
    int f(int idx, vector<vector<vector<int>>> &dp, vector<vector<int>> &v, int m, int n){
        if(idx==0){
            if(v[idx][0]<=m && v[idx][1]<=n) return 1;
            else return 0;
        }

        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        int nottake = f(idx-1, dp, v, m, n);
        int take = 0;
        if(v[idx][0]<=m && v[idx][1]<=n){
            take = 1 + f(idx-1, dp, v, m-v[idx][0], n-v[idx][1]);
        }
        return dp[idx][m][n] = max(nottake, take);
    }
    int solve(vector<vector<int>> &v, int m, int n){
        int len = v.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return f(len-1, dp, v, m, n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> v(len);
        for(int i=0; i<len; i++){
            int c0=0, c1=0;
            for(char c:strs[i]){
                if(c=='0') c0++;
                if(c=='1') c1++;
            }
            v[i].push_back(c0);
            v[i].push_back(c1);
        }
        return solve(v, m, n);
    }
};


