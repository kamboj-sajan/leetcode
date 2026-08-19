// Last updated: 19/08/2026, 15:54:38
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         for(int i =0;i<n; ++i){
//             nums[i] *= nums[i];
//         }
//         sort(nums.begin(),nums.end());
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        vector<int> vec(n,0);
        for(int i=n-1; i>=0; --i){
            if(abs(nums[l]) > nums[r]){
                vec[i] = nums[l]*nums[l];
                l++;
            }else{
                vec[i] = nums[r]*nums[r];
                r--;
            }
        }
        return vec;
    }
};