// Last updated: 19/08/2026, 16:06:41
// // class Solution {
// // public:
// //     int findMin(vector<int>& nums) {
// //         int n = nums.size();
// //         int l = 0;
// //         int r = n-1;
// //         int ans = INT_MAX;
// //         while(l <= r){
// //             int mid = l + (r-l)/2;
// //             if(nums[l] == nums[mid] && nums[mid] == nums[r]){
// //                 ans = min(ans,nums[l]);
// //                 l++;
// //                 r--;
// //                 continue;
// //             }
// //             if(nums[l] <= nums[mid]){
// //                 ans = min(ans,nums[l]);
// //                 l = mid+1;
// //             }else{
// //                 ans = min(ans,nums[mid]);
// //                 r = mid-1;
// //             }
// //         }
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int st = 0;
//         int end = nums.size() - 1;
//         while (st < end) {
//             int mid = st + (end - st) / 2;
//             if (nums[mid] > nums[end]) {
//                 st = mid + 1;
//             } else if (nums[mid] < nums[end]) {

//                 end = mid;
//             }

//             else {
//                 end--;
//             }
//         }
//         return nums[st];
//     }
// };

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1, ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid] <ans) ans=nums[mid];
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};