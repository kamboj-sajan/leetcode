// Last updated: 19/08/2026, 16:02:12
// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> arr = nums;
//         for(int i=0; i<n; ++i){
//             arr.push_back(nums[i]);
//         }
//         int maxi = INT_MIN;
//         for(int i=0; i<n; ++i){
//             int j = (n-i)%n;
//             int temp = 0;
//             int k = 0;
//             while(k <n){
//                 temp += (k*arr[j]);
//                 j++;
//                 k++;
//             }
//             maxi = max(maxi,temp);
//         }
//         return maxi;
//     }
// }; 

// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int n = nums.size();
//         long long sum = 0;
//         long long f0 = 0;
//         // Compute total sum and F(0)
//         for (int i = 0; i < n; i++) {
//             sum += nums[i];
//             f0 += 1LL * i * nums[i];
//         }
//         long long ans = f0;
//         long long curr = f0;

//         // Compute F(1) to F(n-1)
//         for (int k = 1; k < n; k++) {
//             curr = curr + sum - 1LL * n * nums[n - k];
//             ans = max(ans, curr);
//         }

//         return (int)ans;
//     }
// };

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int ret = 0;
        int sum = 0;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            ret += i*nums[i];
            sum += nums[i];
        }
        ans = ret;
        for(int i=0; i<nums.size(); i++)
        {
            ret += sum;
            ret -= (nums.size() * nums[nums.size()-1 - i]);
            ans = max(ans, ret);
        }
        return ans;
    }
};