// Last updated: 24/09/2026, 00:50:54
class Solution {
public:
    using ll = long long;
    long long countCommas(long long n) {
        ll ans = 0;
        ll cma = 1;
        ll st = 1000;
        while(st <= n){
            ll end = st * 1000 -1;
            if(end > n)end = n;
            ans += (end - st + 1)*cma;
            st *= 1000;
            cma++;
        } 
        return ans;
    }
};