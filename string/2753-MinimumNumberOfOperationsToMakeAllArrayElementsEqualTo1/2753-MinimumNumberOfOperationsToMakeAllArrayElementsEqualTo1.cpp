// Last updated: 19/08/2026, 15:30:26
// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//        int n = nums.size();
//        bool a = true;
//        for(int i=0; i<n-1; ++i){
//         if(gcd(nums[i],nums[i+1]) == 1){
//             a = false;
//         }
//        }
//        if(a == true)return -1;
//        else return n;
//     }
// };wrong 661/1008

class Solution {
public:
    int minOperations(vector<int>& nums) {
       const int n = nums.size();
        int res = INT_MAX, cnt1 = 0;
        for (int i = 0; i < n; ++i)
            cnt1 += (nums[i] == 1);
        if (cnt1)
            return n - cnt1;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    res = min(res, j - i + n - 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};