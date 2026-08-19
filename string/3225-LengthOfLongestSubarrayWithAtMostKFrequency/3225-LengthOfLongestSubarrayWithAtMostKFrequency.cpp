// Last updated: 19/08/2026, 15:29:18
// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int,int> mpp;
//         int l = 0;
//         int ans = 0;
//         for(int r = 0; r < n; r++) {
//             mpp[nums[r]]++;
//             while(mpp[nums[r]] > k) {
//                 mpp[nums[l]]--;
//                 l++;
//             }
//             ans = max(ans, r - l + 1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> counter;

        int result = 0, lo = 0, hi = 0;
        while (hi < nums.size()) {
            auto& c = counter[nums[hi]];
            if (c < k) {
                result = max(result, (hi + 1) - lo);
                c++;
            } else {
                c++;
                int out = nums[lo];
                counter[out]--;
                lo++;
                while (out != nums[hi]) {
                    out = nums[lo];
                    counter[out]--;
                    lo++;
                }
            }
            hi++;
        }
        return result;
    }
};