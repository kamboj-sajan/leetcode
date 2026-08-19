// Last updated: 19/08/2026, 15:17:02
class Solution {
public:
    using ll = long long;
    long long countCommas(long long n) {
        ll ans = 0;
        ll first = 1000;
        int cm = 1;
        while(first <= n){
            ll last = first * 1000 -1;
            ans += (min(n,last) - first + 1)*cm;
            first *= 1000;
            cm++;
        }
        return ans;
    }
};