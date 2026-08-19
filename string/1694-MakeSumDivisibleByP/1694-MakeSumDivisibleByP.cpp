// Last updated: 19/08/2026, 15:38:56
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;
        int target = total % p;
        if (target == 0) return 0;
        unordered_map<int,int> last;
        last.reserve(min(p, n) + 1);
        last[0] = 0;
        int pref = 0;
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            pref = (pref + nums[i]) % p;
            int need = (pref - target) % p;
            if (need < 0) need += p;
            auto it = last.find(need);
            if (it != last.end()) ans = min(ans, i + 1 - it->second);
            last[pref] = i + 1;
        }
        if (ans > n - 1) return -1;
        return ans;
    }
};
