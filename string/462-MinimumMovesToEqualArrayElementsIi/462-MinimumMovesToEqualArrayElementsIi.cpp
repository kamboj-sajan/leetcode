// Last updated: 19/08/2026, 16:01:10
// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         using ll = long long;
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         int md = nums[n/2];
//         int res = 0;
//         for(int i=0; i<n; ++i){
//             res += abs(nums[i] - md);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int median=nums[n/2],steps=0;
        for(int i=0;i<n;i++){
            steps+=abs(nums[i]-median);
        }
        return steps;
    }
};