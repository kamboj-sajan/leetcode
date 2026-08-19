// Last updated: 19/08/2026, 15:24:13
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9+7;
        int n = nums.size();    
        unordered_map<long long, long long> right;
        for (int x : nums) {
            right[x]++;
        }
        unordered_map<long long, long long> left;
        long long ans = 0;

        for (int j = 0; j < n; ++j) {
            long long x = nums[j];
            right[x]--;
            long long need = 2 * x;
            long long cntLeft  = left.count(need)  ? left[need]  : 0;
            long long cntRight = right.count(need) ? right[need] : 0;
            long long add = (cntLeft % MOD) * (cntRight % MOD) % MOD;
            ans = (ans + add) % MOD;
            left[x]++;
        }

        return static_cast<int>(ans % MOD);
    }
};
