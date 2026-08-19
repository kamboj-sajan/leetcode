// Last updated: 19/08/2026, 15:38:01
// class Solution {
// public:
//     vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> pre(n+1,0);
//        vector<int> res;
//        for(int i=0; i<n; ++i)pre[i+1] = pre[i] + nums[i];
//        for(int i=0; i<n; ++i){
//            int left = abs((nums[i]*(i+1)) - pre[i+1]);
//            int right = (pre[n] - pre[i+1]) - (nums[i]*(n- i - 1));
//            res.push_back(left+right);
//        }
//        return res;
//     }
// };

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // Boost I/O performance
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums) totalSum += x;
        vector<int> result(n);
        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            int rightSum = totalSum - leftSum - nums[i];
            // Simplified logic:
            // (nums[i] * count_left - leftSum) + (rightSum - nums[i] * count_right)
            result[i] = (i * nums[i] - leftSum) + (rightSum - (n - 1 - i) * nums[i]);
            leftSum += nums[i];
        }
        return result;
    }
};