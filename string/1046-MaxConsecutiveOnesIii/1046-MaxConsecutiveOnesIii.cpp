// Last updated: 19/08/2026, 15:54:17
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int ans = INT_MIN;
//         int c0 = 0;
//         int i = 0;
//         int j = 0;
//         int n = nums.size();
//         while(j < n){
//            if(nums[j] == 0){
//             c0++;
//             if(c0 > k){
//                 while(c0 != k){
//                     if(nums[i] == 0)c0--;
//                     i++;
//                 }
//             }
//             ans = max(ans,j-i+1);
//            }else{
//             ans = max(ans,j-i+1);
//            }
//            j++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0,l = 0,r = 0,zeros = 0,len=0;
        while(r<nums.size()){//O(n)
            if(nums[r]==0) zeros++;
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            len = r-l+1;
            maxLen = max(len,maxLen);
            r++;
        }
        return maxLen;
    }
};