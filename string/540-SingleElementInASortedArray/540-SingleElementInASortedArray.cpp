// Last updated: 19/08/2026, 16:00:20
// // class Solution {
// // public:
// //     int singleNonDuplicate(vector<int>& nums) {
// //         int n = nums.size();
// //         if(n==1)return nums[0];
// //         if(nums[0] != nums[1])return nums[0];
// //         if(nums[n-1] != nums[n-2])return nums[n-1];
// //         int l = 1 , r = n-2;
// //         while(l <= r){
// //             int mid = l + (r-l)/2;
// //             if(nums[mid] != nums[mid+1] && nums[mid-1] != nums[mid])return nums[mid];
// //             if(((mid%2 == 1) && nums[mid - 1] == nums[mid]) || ((mid % 2 == 0) && nums[mid] == nums[mid + 1])){
// //                 l = mid + 1;
// //             }else r = mid -1 ;
// //         }
// //         return -1;
// //     }
// // };

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int s = 0,e = n-2;
//         int ans = n-1;
//         while(s<=e){
//             int mid = s + (e-s)/2;
//             if(mid%2 == 0 && nums[mid] == nums[mid+1] || mid%2 == 1 && nums[mid] == nums[mid-1]){
//                 s = mid+1;
//             }
//             else if(mid%2 == 1 && nums[mid] == nums[mid+1] || mid>0 && mid%2 == 0 && nums[mid] == nums[mid-1]){
//                 e = mid-1;
//             }
//             else {
//                 // cout<<mid<<endl;
//                 return nums[mid];
//             }
//         }
//         return nums[ans];
//     }
// };

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans ;
        if(n==1)return nums[0] ;
        for(int i = 0 ; i < n ; i++){
            if(i==0){
                if(nums[i] != nums[i+1]) ans = nums[i] ;
            }
            else if(i == n-1){
                if(nums[i] != nums[i-1]) ans = nums[i] ;
            }
            else{
                if(nums[i] != nums[i+1] && nums[i] != nums[i-1]) ans = nums[i] ;
            }
        }
        return ans ;
    }
};