// Last updated: 28/09/2026, 10:05:16
// // class Solution {
// // public:
// //     vector<int> productExceptSelf(vector<int>& nums) {
// //         int n = nums.size();
// //         vector<int> pre(n);
// //         vector<int> suf(n);
// //         pre[0] = nums[0];
// //         suf[nums.size()-1] = nums[nums.size()-1];
// //         for(int i=1; i<nums.size(); i++){
// //             pre[i] = pre[i-1]*nums[i];
// //         }
// //         for(int i=nums.size()-2; i>=0; i--){
// //             suf[i] = suf[i+1]*nums[i];
// //         }
// //         vector<int> ans(n);
// //         ans[0] = suf[1];
// //         ans[n-1] = pre[n-2];
// //         for(int i=1; i<n-1; i++){
// //             ans[i] = pre[i-1]*suf[i+1];
// //         }
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         int prefix = 1;
//         vector<int> ans(n ,1);
//         for(int i=0; i<n; i++){
//             ans[i] = prefix;
//             prefix *= nums[i];   
//         }
//         int suffix = 1;
//         for(int i= n-1; i>=0; i--){
//             ans[i] *= suffix;
//             suffix *= nums[i];
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Store prefix products in ans
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Multiply by suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};