// Last updated: 01/09/2026, 10:21:35
class Solution {
public:
    using ll = long long;
    int mod = 1e9 + 7;
    ll ff(ll a, ll b){
        ll ans = 1;
        while(b > 0){
            if(b %2 == 1){
                ans = (ans*a)%mod;
            }
            a = (a*a)%mod;
            b = b/2;
        }
        return ans;
    }
public:
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            ll a = nums[i];
            int w = (nums[i]%10);
            ll d = floor(nums[i]/10);
            string st = to_string(d);
            string f = st.substr(0,w);
            string l = st.substr(w);
            ll f1 = stoll(f);
            ll l1 = stoll(l);
            ans = (ans + ff(f1,l1))%mod;
        }
        return ans;
    }
};