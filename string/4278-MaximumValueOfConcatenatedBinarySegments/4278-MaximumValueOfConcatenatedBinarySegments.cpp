// Last updated: 19/08/2026, 15:15:55
class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;
    ll power(ll base, ll exp) {
        ll res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    static bool compareSegments(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == 0 && b.second != 0) return true;
        if (b.second == 0 && a.second != 0) return false;

        if (a.first != b.first) return a.first > b.first;

        return a.second < b.second;
    }

public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<pair<int, int>> segments(n);
        for (int i = 0; i < n; i++) {
            segments[i] = {nums1[i], nums0[i]};
        }
        sort(segments.begin(), segments.end(), compareSegments);
        ll ans = 0;
        for (auto &seg : segments) {
            int ones = seg.first;
            int zeros = seg.second;
            int len = ones + zeros;
            ans = (ans * power(2, len)) % MOD;
            ll ones_val = (power(2, ones) - 1 + MOD) % MOD;
            ll val = (ones_val * power(2, zeros)) % MOD;

            ans = (ans + val) % MOD;
        }

        return (int)ans;
    }
};