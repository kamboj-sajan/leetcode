// Last updated: 19/08/2026, 15:30:12
// class Solution {
// public:
//     bool isGood(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> mpp;
//         for(int i : nums)mpp[i]++;
//         int maxi = *max_element(nums.begin(),nums.end());
//         for(auto &a : mpp){
//             if(a.first == maxi){
//                 if(a.second != 2)return false;
//             }
//             else{
//                 if(a.second != 1)return false;
//             }
//         }
//         if(n != maxi+1)return false;
//         return true;
//     }
// };

// class Solution {
// public:
//     bool isGood(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         for(int i = 0; i < n - 1; ++i){

//             if(nums[i] != i + 1){
//                 return false;
//             }
//         }
//         if(nums[n - 1] != n - 1){
//             return false;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxi = nums.back();

        // Size must be n = maxi + 1
        if(n != maxi + 1) return false;

        // Check first n-1 elements
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] != i + 1) return false;
        }

        // Last two elements must be equal to maxi
        return nums[n - 1] == maxi && nums[n - 2] == maxi;
    }
};