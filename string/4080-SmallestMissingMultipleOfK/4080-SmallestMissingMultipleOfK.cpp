// Last updated: 19/08/2026, 15:20:20
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        for (long long i = 1; ; ++i) {
            long long el = 1LL * k * i;
            if (!st.count((int)el)) {
                return el;
            }
        }
        return -1; 
    }
};