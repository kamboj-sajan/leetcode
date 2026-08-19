// Last updated: 19/08/2026, 15:54:49
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> mpp;
//         for(int i=0; i<n; ++i){
//             mpp[nums[i]]++;
//         }
//         for(auto it : mpp){
//             if(it.second == n/2)return it.first;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};