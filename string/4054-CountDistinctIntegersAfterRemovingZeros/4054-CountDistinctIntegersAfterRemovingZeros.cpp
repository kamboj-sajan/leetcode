// Last updated: 19/08/2026, 15:20:51
class Solution {
    string s;
    vector<vector<vector<long long>>> dp;
    long long f(int i, int less, int st){
        if(i == s.size()) return 1;
        long long &res = dp[i][less][st];
        if(res != -1) return res;
        res = 0;
        int lim = less ? 9 : s[i] - '0';
        for(int j = 0; j <= lim; j++){
            if(!st && j == 0){
                res += f(i+1, less || (j < lim), 0);
            } else if(j != 0){
                res += f(i+1, less || (j < lim), 1);
            }
        }
        return res;
    }

public:
    long long countDistinct(long long n){
        s = to_string(n);
        dp.assign(s.size(), vector<vector<long long>>(2, vector<long long>(2, -1)));
        return f(0, 0, 0) - 1;
    }
};