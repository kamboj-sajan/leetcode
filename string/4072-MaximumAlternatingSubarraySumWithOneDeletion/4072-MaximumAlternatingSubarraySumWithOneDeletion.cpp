// Last updated: 11/10/2026, 07:58:56
class Solution {
public:
    using ll = long long;
    long long maxAlternatingSum(vector<int>& nums) {
       ll n = -1e9;
       vector<ll> vec(4,n);
        ll ans = n;
        for(ll a : nums){
            vector<ll> temp(4,n);
            temp[1] = a;
            if(vec[1] != n)temp[0] = max(temp[0],vec[1] - a);
            if(vec[0] != n)temp[1] = max(temp[1],vec[0] + a);
            temp[2] = max(temp[2],vec[1]);
            temp[3] = max(temp[3],vec[0]);
            if(vec[3] != n)temp[2] = max(temp[2],vec[3]+a);
            if(vec[2] != n)temp[3] = max(temp[3],vec[2]-a);
            vec= temp;
            ans = max({ans,vec[0],vec[1],vec[2],vec[3]});
        }
        return ans;
    }
};