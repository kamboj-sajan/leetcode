// Last updated: 19/08/2026, 15:48:07
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        long long a = 6; // Type A (ABA)
        long long b = 6; // Type B (ABC)

        for (int i = 2; i <= n; i++) {
            long long na = (a * 3 + b * 2) % MOD;
            long long nb = (a * 2 + b * 2) % MOD;
            a = na;
            b = nb;
        }

        return (a + b) % MOD;
    }
};