// Last updated: 19/08/2026, 15:22:42
// class Solution {
// public:
//     int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
//         int mod = 1e9 + 7;
//         for(auto &it : queries){
//             int ind = it[0];
//             while(ind <= it[1]){
//                 nums[ind] = (1LL*nums[ind]*it[3])%mod;
//                 ind = ind + it[2];
//             }
//         }
//         int ans = 0;
//         for(int a : nums){
//             ans ^= a;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        // Process each query sequentially
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            
            // Step through the array with stride k
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        // Calculate the final XOR sum
        int result = 0;
        for (int val : nums) {
            result ^= val;
        }
        
        return result;
    }
};