// Last updated: 19/08/2026, 15:31:44
// class Solution {
// public:
//     int longestNiceSubarray(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         for(int i=0; i<n; ++i){
//             int mask = 0;
//             for(int j=i; j<n; ++j){
//                 if((mask & nums[j]) != 0){
//                     break;
//                 }
//                 ans = max(ans,j-i+1);
//                 mask |= nums[j];
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int longestNiceSubarray(vector<int>& nums) {
//         int n = nums.size();
//         int l = 0;
//         int r = 0;
//         int ans = 1;
//         int mask = 0;
//         while(r < n){
//             while((mask & nums[r]) != 0){
//                 mask ^= nums[l];
//                 l++;
//             }
//             mask |= nums[r];
//             ans = max(ans, r - l + 1);
//             r++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int count=0;
        int cur_count=0;
        int sum=0;
        int j=0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(!(sum & nums[i])){
                sum+=nums[i];
                cur_count++;
            }
            else{
                count=max(count,cur_count);
                while(sum & nums[i]){
                    cur_count--;
                    sum-=nums[j];
                    j++;
                }
                sum+=nums[i];
                cur_count++;
            }
        }
        count=max(count,cur_count);
        return count;
    }
};