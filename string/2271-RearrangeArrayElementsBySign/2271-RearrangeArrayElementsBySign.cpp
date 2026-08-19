// Last updated: 19/08/2026, 15:32:41
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n,0);
//         int posindex = 0 , negindex = 1;
//         for(int i= 0; i<n; i++){
//             if(nums[i] < 0 ){
//                 ans[negindex] = nums[i];
//                 negindex += 2;
//             }else{
//                 ans[posindex] = nums[i];
//                 posindex += 2;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr(nums.size());
        int pos = 0, neg = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                arr[pos] = nums[i];
                pos += 2; 
            } else {
                arr[neg] = nums[i];
                neg += 2; 
            }
        }
        return arr;
    }
};