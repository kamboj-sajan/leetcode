// Last updated: 19/08/2026, 16:06:24
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        if(nums[0] > nums[1])return 0;
    if(nums[n-1] > nums[n-2])return n-1;
        int l = 1, r = n-2;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] > nums[m-1] && nums[m] > nums[m+1])return m;
            else if(nums[m] > nums[m-1])l = m+1;
            else if(nums[m] > nums[m+1])r = m-1;
            else l = m+1;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//          int n = nums.size();
//         if(n == 1) return 0;
//         if(nums[0] > nums[1]) return 0;
//         if(nums[n-1] > nums[n-2]) return n-1;
//         int low = 1, high = n-2;
//         while(low <= high){
//             int mid = (low+high)/2;
//             if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
//                 return mid;
//             }
//             else if(nums[mid] > nums[mid-1]) low = mid + 1;
//             else high = mid - 1;
//         }
//         return -1;
//     }
// };