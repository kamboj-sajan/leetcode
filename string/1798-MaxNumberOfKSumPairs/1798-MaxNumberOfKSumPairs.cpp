// Last updated: 19/08/2026, 15:37:50
// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         unordered_map<int, int> mpp;
//         int cnt = 0;
//         for (int num : nums) {
//             int target = k - num;
//             if (mpp[target] > 0) {
//                 cnt++;
//                 mpp[target]--;
//             } else {
//                 mpp[num]++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0; i< nums.size();i++){
            int idx = k - nums[i];
            if(mp[idx] > 0){
                count++;
                mp[idx]--;
            }else{
                mp[nums[i]]++;
            }
        }
        return count;
    }
};