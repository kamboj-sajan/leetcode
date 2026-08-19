// Last updated: 19/08/2026, 15:15:16
class Solution {
public:
    using ll = long long;
    bool f(ll st,vector<int> &mon,vector<ll> &b){
        ll temp = st;
        for(int i=0; i<mon.size(); i++){
            if(temp + b[i] < mon[i])return false;
            temp -= mon[i];
            if(temp < 0)temp = 0;
        }
        return true;
    }
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
       int n = monsters.size();
        vector<ll> d(n+1,0);
        for(auto &b : boosts){
            d[b[0]] += b[2];
            if(b[1] + 1 < n){
                d[b[1] + 1] -= b[2];
            }
        }
        vector<ll> arr(n);
        ll temp = 0;
        for(int i=0; i<n; i++){
            temp += d[i];
            arr[i] = temp;
        }
        ll r = 0;
        for(int i : monsters)r += i;
        ll l = 0;
        ll ans = r;
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(f(mid,monsters,arr)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};