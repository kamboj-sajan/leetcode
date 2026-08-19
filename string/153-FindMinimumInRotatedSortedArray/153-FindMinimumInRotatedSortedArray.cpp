// Last updated: 19/08/2026, 16:06:43
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//      int mini = INT_MAX;
//      int n = nums.size();
//      int l = 0;
//      int r = n-1;
//      while(l <= r){
//         int mid = l + (r-l)/2;
//         if(nums[l] <= nums[mid]){
//             mini = min(nums[l],mini);
//             l = mid+1;
//         }else{
//             mini = min(nums[mid],mini);
//             r = mid-1;
//         }
//      }
//      return mini;   
//     }
// };

class Solution {
public:
    int findMin(vector<int>& nums) {
         /*
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[low] <= arr[mid]){
                ans = min(ans , arr[low]);
                low = mid + 1;
            }
            else{
                high = mid - 1;
                ans = min(ans, arr[mid]);
            }
        }
        return ans;
        */
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            //search space is already sorted
            //then always arr[low] will be smaller
            // in that search space
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            } 
            if(nums[low] <= nums[mid]){
                ans = min(ans , nums[low]);
                low = mid + 1;
            }
            else{
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
            
        }
        return ans;
    }
};