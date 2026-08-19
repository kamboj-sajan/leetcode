// Last updated: 19/08/2026, 15:15:05
class Solution {
public:
    using ll = long long;
    int maximumWidth(vector<int>& planks) {
       unordered_map<ll,ll> mpp;
        for(int i : planks)mpp[i]++;
        vector<pair<ll,ll>> vec(mpp.begin(),mpp.end());
        unordered_map<ll,ll> cnt;
        int n = vec.size();
        for(int i=0; i<n; i++){
            ll a = vec[i].first;
            ll b = vec[i].second;
            if(b>= 2){
                cnt[2*a] += b/2;
            }
            for(int j=i+1; j<n; j++){
                ll u = vec[j].first;
                ll v = vec[j].second;
                cnt[u+a] += min(b,v);
            }
        }
        int ans = 0;
        for(auto &p : mpp){
            ll temp = p.first;
            ans = max(ans,(int)(p.second + cnt[temp]));
        }
        for(auto &c : cnt){
            ll temp = c.first;
            ans = max(ans,(int)(c.second+mpp[temp]));
        }
        return ans;
    }
};