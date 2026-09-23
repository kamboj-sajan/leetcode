// Last updated: 24/09/2026, 00:48:58
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
       if(n == 1)return s;
        using ll = long long;
        ll hf = n/2;
        ll ans = 1LL*s + m + (hf - 1) * 1LL * (m-1);
        return ans;
    }
};