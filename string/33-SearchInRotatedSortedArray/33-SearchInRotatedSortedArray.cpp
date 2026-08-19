// Last updated: 19/08/2026, 16:12:41
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    h = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(nums[mid] <= target && target <= nums[h]){
                    l = mid+1;
                }else{
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};