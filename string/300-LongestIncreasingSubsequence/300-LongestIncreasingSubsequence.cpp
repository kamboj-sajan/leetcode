// Last updated: 19/08/2026, 16:03:11
// class Solution {
// public:
//     int f(int i, int prev, vector<int> &a,int n){
//         if(i == n){
//             return 0;
//         }
//         int l = 0 + f(i+1,prev,a,n);
//         if(prev == -1 || a[i] > a[prev] ){l = max(l,1 + f(i+1,i,a,n));}
//         return l;
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         int prev = -1;
//         return f(0,prev,nums,n);
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1,vector<int> (n+1,0));
//         for(int ind=n-1; ind>=0; ind--){
//             for(int prev=ind-1; prev>=-1; prev--){
//                 int len = dp[ind+1][prev+1]; // prev +1 for 1 based indexing
//                 if(prev == -1 || nums[ind] > nums[prev]){
//                     len = max(len, 1+dp[ind+1][ind+1]);
//                 }
//                 dp[ind][prev+1] = len;
//             }
//         }
//         return dp[0][-1+1];
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> cur(n+1,0),next(n+1,0);
//         for(int ind=n-1; ind>=0; ind--){
//             for(int prev=ind-1; prev>=-1; prev--){
//                 int len = next[prev+1]; // prev +1 for 1 based indexing
//                 if(prev == -1 || nums[ind] > nums[prev]){
//                     len = max(len, 1+next[ind+1]);
//                 }
//                 cur[prev+1] = len;
//             }
//             next = cur;
//         }
//         return next[-1+1];
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,1);
//         int maxi = 0;
//         for(int i=0; i<n; i++){
//             for(int prev=0; prev<i; prev++){
//                 if(nums[prev] < nums[i]){
//                     dp[i] = max(dp[i],1+dp[prev]);
//                 }
//             }
//             maxi = max(maxi,dp[i]);
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};