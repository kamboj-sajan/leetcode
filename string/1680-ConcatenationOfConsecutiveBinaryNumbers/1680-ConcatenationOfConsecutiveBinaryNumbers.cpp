// Last updated: 25/09/2026, 01:10:48
class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        int bitLength = 0;

        for (int i = 1; i <= n; i++) {

            // if i is power of 2 -> new bit added
            if ((i & (i - 1)) == 0)
                bitLength++;

            // shift and add
            ans = ((ans << bitLength) + i) % MOD;
        }

        return ans;
    }
};