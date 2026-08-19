// Last updated: 19/08/2026, 16:03:31
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> f(n+1,0);
//         for(int i=0; i<n; ++i)f[nums[i]]++;
//         for(int i=0; i<=n; ++i){
//             if(f[i] == 0)return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < n; i++)
        {
            if (i != nums[i]) {
                return i;
            }
        }
        return n;
    }
};