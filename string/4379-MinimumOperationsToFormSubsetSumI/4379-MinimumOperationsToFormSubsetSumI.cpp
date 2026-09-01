// Last updated: 01/09/2026, 10:21:34
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<pair<int,int>>> vec;
    int f(int i,int t){
        if(t == 0)return 0;
        if(i == vec.size())return 1e9;
        if(dp[i][t] != -1)return dp[i][t];
        int ans = f(i+1,t);
        for(auto &p : vec[i]){
            if(p.first <= t){
                int r = f(i+1,t - p.first);
                if(r != 1e9){
                    ans = min(ans,p.second + r);
                }
            }
        }
        return dp[i][t] = ans;
    }
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        dp.assign(n,vector<int> (sum+1,-1));
        vec.resize(n);
        for(int i=0; i<n; i++){
            int a = nums[i];
            int b = a;
            int ct = 0;
            while(b <= sum){
                vec[i].push_back({b,ct});
                if(b > sum/2)break;
                b *= 2;
                ct++;
            }
            b = a;
            ct = 0;
            while(b > 0){
                vec[i].push_back({b,ct});
                b /= 2;
                ct++;
            }
        }
        int ans = f(0,sum);
        if(ans == 1e9)return -1;
        else return ans;
    }
};