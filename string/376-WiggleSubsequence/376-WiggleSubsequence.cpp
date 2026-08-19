// Last updated: 19/08/2026, 16:02:27
// class Solution {
// public:
//     vector<vector<vector<int>>> dp;
//     int f(int i,int prv,int sign,vector<int> &nums){
//        int n = nums.size();
//        if(i == n)return 0;
//        if (dp[i][prv + 1][sign] != -1)return dp[i][prv + 1][sign];
//        int nottake = f(i+1,prv,sign,nums);
//        int take = 0;
//        if(prv == -1){
//         take = 1 + f(i+1,i,0,nums);
//        }else{
//         int diff = nums[i] - nums[prv];
//         if(sign == 0){
//             if(diff > 0){
//                 take = 1 + f(i+1,i,2,nums);
//             }else if(diff < 0){
//                 take = 1 + f(i+1,i,1,nums);
//             }
//         }else if(sign == 1){//need positive
//             if(diff > 0){
//                 take = 1 + f(i+1,i,2,nums);
//             }
//         }else{// need neg
//             if(diff < 0){
//                 take = 1 + f(i+1,i,1,nums);
//             }
//         }
//        }
//        return dp[i][prv+1][sign] = max(take,nottake);
//     }
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         dp.assign(n+1,vector<vector<int>> (n+1,vector<int> (3,-1)));
//         return f(0,-1,0,nums);
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> dp;
//     int f(int i,int up,vector<int> &nums){
//       if(dp[i][up] != -1)return dp[i][up];
//       int ans = 1;
//        for (int j = 0; j < i; j++) {
//             if (up && nums[i] > nums[j])
//                 ans = max(ans, 1 + f(j, 0, nums));
//             if (!up && nums[i] < nums[j])
//                 ans = max(ans, 1 + f(j, 1, nums));
//         }
//         return dp[i][up] = ans;
//     }
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         dp.assign(n,vector<int> (2,-1));
//         int ans = 1;
//         for(int i=0; i<n; ++i){
//             ans = max(ans,f(i,0,nums));
//             ans = max(ans,f(i,1,nums));
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        int up = 1, down = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            }
            else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }

        return max(up, down);
    }
};