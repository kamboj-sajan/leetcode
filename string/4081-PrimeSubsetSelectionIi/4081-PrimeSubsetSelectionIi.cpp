// Last updated: 13/10/2026, 10:47:21
class Solution {
    using ll = long long;
    int f(int i,int a,vector<int> &vec,vector<vector<int>> &dp){
        if(a == 0)return 0;
        if(i == vec.size() || a < 0)return 1e9;
        if(dp[i][a] != -1)return dp[i][a];
        int nxt = f(i+1,a,vec,dp);
        int tk = 1e9;
        if(vec[i] <= a){
            int c = f(i+1,a - vec[i],vec,dp);
            if(c != 1e9)tk = c+1;
        }
        return dp[i][a] = min(nxt,tk);
    }
public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> vec;
        vector<int> ans;
        vector<bool> b(n+1,false);
        for(int i=2; i<=n; i++){
            if(b[i])continue;
            vec.push_back(i);
            for(ll j =1LL*i*i; j<=n; j+= i){
                b[j] = true;
            }
        }
        ll t = 0;
        for(int i=0; i<vec.size(); i++){
            t += vec[i];
        }
        int a = (int)min<ll>(t,s);
        if(a < 2)return ans;
        vector<vector<int>> dp(vec.size()+1,vector<int> (a+1,-1));
        int maxi = a;
        while(maxi > 0 && f(0,maxi,vec,dp) == 1e9){
            maxi--;
        }
        if(maxi == 0)return ans;
        int rm =maxi;
        int d = f(0,maxi,vec,dp);
        for(int i=0; i<vec.size() && rm>0; i++){
            if(vec[i] <= rm && f(i+1,rm-vec[i],vec,dp) == d-1){
                ans.push_back(vec[i]);
                rm -= vec[i];
                d--;
            }
        }
        return ans;
    }
};