// Last updated: 19/08/2026, 16:00:01

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> prefixSumFreq;
//         prefixSumFreq[0] = 1;  // to handle sum == k from start
//         int sum = 0, count = 0;
        
//         for (int num : nums) {
//             sum += num;
//             if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
//                 count += prefixSumFreq[sum - k];
//             }
//             prefixSumFreq[sum]++;
//         }
        
//         return count;
//     }
// };
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int presum = 0 , cnt = 0;
        // O(N * logN)
        // O(N)
        for(int i = 0; i<nums.size(); i++){
            presum += nums[i];
            int remove = presum - k;
            cnt += mpp[remove];
            mpp[presum] += 1;
        }
        return cnt;
    }
};