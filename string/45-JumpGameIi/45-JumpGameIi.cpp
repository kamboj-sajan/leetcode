// Last updated: 19/08/2026, 16:12:01
// class Solution {
// public:
//     int f(int ind,vector<int> &nums,int cnt){
//         if(ind >= nums.size()-1)return cnt;
//         int mini = INT_MAX;
//         for(int i=1; i<=nums[ind]; i++){
//             if(ind + i < nums.size())
//             mini = min(mini,f(ind+i,nums,cnt+1));
//         }
//         return mini;
//     }
// public:
//     int jump(vector<int>& nums) {
//         return f(0,nums,0);
//     }
// };


// class Solution {
// public:
//     int f(int ind,vector<int> &nums,vector<int> &dp){
//         if(ind >= nums.size()-1)return 0;
//         if(dp[ind] != -1)return dp[ind];
//         int mini = INT_MAX;
//         for(int i=1; i<=nums[ind]; i++){
//             if(ind + i < nums.size()){
//             int next = f(ind+i,nums,dp);
//             if(next != INT_MAX) mini = min(mini,1 + next);
//             }
//         }
//         return dp[ind] = mini;
//     }
// public:
//     int jump(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         return f(0,nums,dp);
//     }
// };


class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int jumps = 0;
        while(r < n-1){
            int far = 0;
            for(int i=l; i<=r; ++i){
                far = max(i+nums[i],far);
            }
            jumps++;
            l = r+1;
            r = far;
        }
        return jumps;
    }
};
