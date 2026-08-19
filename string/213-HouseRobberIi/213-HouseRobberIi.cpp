// Last updated: 19/08/2026, 16:04:55
// class Solution {
// private:
//       int rob1(vector<int>& nums) {
//       int n = nums.size();
//        // vector<int> dp(n,-1);
//        // return f(n-1,nums,dp);
//        int prev = nums[0];
//        int prev2 = 0;
//        for(int i=1; i<n; i++){
//         int take = nums[i];
//         if(i>1)take += prev2;
//         int notTake = 0 + prev;
//        int cur = max(take,notTake);
//         prev2 = prev;
//         prev = cur;
//        }
//        return prev;
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp1,temp2;
//         if(n == 1)return nums[0];
//         for(int i=0; i<n; i++){
//             if(i != 0)temp1.push_back(nums[i]);
//             if(i != n-1)temp2.push_back(nums[i]);
//         }
//         return max(rob1(temp1),rob1(temp2));
//     }
// };



class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        int prev2 = 0;
        int prev1 = 0;
        int curr;
        for(int i=start; i<=end; i++){
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);
        int curr1, curr2;
        curr1 = helper(nums, 0, n-2);
        curr2 = helper(nums, 1, n-1);
        return max(curr1, curr2);
    }
};