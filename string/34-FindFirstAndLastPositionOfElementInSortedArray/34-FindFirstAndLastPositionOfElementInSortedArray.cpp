// Last updated: 19/08/2026, 16:12:38
// class Solution {
// public:
//     int firstPos(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;
//         int ans = -1;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;

//             if (nums[mid] == target) {
//                 ans = mid;
//                 r = mid - 1;       // keep searching left
//             }
//             else if (nums[mid] < target)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }

//         return ans;
//     }

//     int lastPos(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;
//         int ans = -1;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;

//             if (nums[mid] == target) {
//                 ans = mid;
//                 l = mid + 1;       // keep searching right
//             }
//             else if (nums[mid] < target)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }

//         return ans;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         return {firstPos(nums, target), lastPos(nums, target)};
//     }
// };

class Solution {
public:
  int lowerbound(vector<int> nums, int x){
    int n = nums.size();
    int low = 0 , high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        //maybe an answer
        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
  }

public:
int upperbound(vector<int> &arr,  int x){
    int n = arr.size();
    int low = 0 , high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
} 
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerbound(nums , target);
        if(lb == n || nums[lb] != target) return {-1 , -1};
        return {lb , upperbound(nums, target) - 1};
    }
};