// Last updated: 19/08/2026, 15:25:14
class Solution {
public:
    using ll = long long;
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<ll> ans(n,1e9);
        ans[0] = 0;
        for(auto &r : restrictions){
            ans[r[0]] = min(ans[r[0]],(ll)r[1]);
        }
        for(int i=1; i<n; ++i){
            ans[i] = min(ans[i],ans[i-1] + diff[i-1]);
        }
        for(int i=n-2; i>=0; --i){
            ans[i] = min(ans[i],ans[i+1]+ diff[i]);
        }
        ll res = 0;
        for(auto v : ans)res = max(res,v);
        return (int)res;
    }
};