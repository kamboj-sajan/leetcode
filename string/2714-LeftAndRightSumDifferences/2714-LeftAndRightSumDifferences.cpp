// Last updated: 19/08/2026, 15:30:39
// class Solution {
// public:
//     vector<int> leftRightDifference(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> l(n,0);
//         vector<int> r(n,0);
//         for(int i=0; i<n-1; ++i){
//             l[i+1] = l[i] + nums[i];
//         }
//         for(int i=n-1; i>=1; i--){
//             r[i-1] = r[i] + nums[i];
//             l[i] = abs(l[i] - r[i]);
//         }
//         l[0] = abs(l[0] - r[0]);
//         return l;
//     }
// };

// class Solution {
// public:
//     vector<int> leftRightDifference(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>pre(n, 0);
//         int p = nums[0];
//         for(int i=1; i<n; i++){
//             pre[i] = p;
//             p += nums[i];
//         }
//         vector<int>suf(n, 0);
//         p = nums[n-1];
//         for(int i=n-2; i>=0; i--){
//             suf[i] = p;
//             p += nums[i];
//         }
//         for(int i=0; i<n; i++){
//             pre[i] = pre[i] - suf[i];
//             if(pre[i]<0) pre[i] *= -1;
//         }
//         return pre;
//     }
// };

// class Solution {
// public:
//     vector<int> leftRightDifference(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);

//         int total = 0;
//         for (int x : nums) total += x;

//         int left = 0;

//         for (int i = 0; i < n; i++) {
//             total -= nums[i];      // total now = rightSum[i]
//             ans[i] = abs(left - total);
//             left += nums[i];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        // 1. Calculate the total sum of the array
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }

        vector<int> answer(n);
        int leftSum = 0;

        // 2. Traverse the array and dynamically compute leftSum and rightSum
        for (int i = 0; i < n; ++i) {
            // rightSum = total sum - left sum - current element
            int rightSum = totalSum - leftSum - nums[i];

            // Compute the absolute difference
            answer[i] = abs(leftSum - rightSum);

            // Update leftSum for the next index
            leftSum += nums[i];
        }

        return answer;
    }
};