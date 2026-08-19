// Last updated: 19/08/2026, 15:57:26
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // primes up to 32
        unordered_set<int> prime = 
        {2,3,5,7,11,13,17,19,23,29,31};

        int ans = 0;

        for (int i = left; i <= right; i++) {
            if (prime.count(__builtin_popcount(i)))
                ans++;
        }
        return ans;
    }
};