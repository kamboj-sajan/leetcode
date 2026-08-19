// Last updated: 19/08/2026, 15:20:26
// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int ans =0;
//         for(int i=0; i<n; ++i){
//             int cnt = 0;
//             for(int j=i; j<n; ++j){
//                 if(nums[j] == target)cnt++;
//                 if(cnt > (j-i+1)/2)ans++;
//             }
//         } 
//         return ans;
//     }
// };

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; ++i){
            int k = 0;
            for(int j=i; j<n; ++j){
                if(nums[j] == target)k++;
                int len = j-i+1;
                if(k * 2 > len)ans++;
            }
        }
        return ans;
    }
};