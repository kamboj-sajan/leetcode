// Last updated: 19/08/2026, 16:13:37
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<vector <int>> ans;
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<n; i++){
//             if(i>0 && nums[i] == nums[i-1]) continue;
//             for(int j = i+1 ; j<n; j++){
//                 if(j != i+1 && nums[j] == nums[j-1]) continue;
//                 int k = j+1;
//                 int l = n-1;
//                 while(k < l){
//                     long long sum = nums[i];
//                     sum += nums[j];
//                     sum += nums[k];
//                     sum += nums[l];
//                     if(sum == target){
//                         vector<int> temp = {nums[i] , nums[j], nums[k], nums[l]};
//                         ans.push_back(temp);
//                         k++;
//                         l--;
//                         while(k<l && nums[k] == nums[k-1]) k++;
//                         while(k<l && nums[l] == nums[l+1]) l--;
//                     }else if(sum < target) k++;
//                     else l--;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());              // sort array for two-pointer
        int n = nums.size();
        vector<vector<int>> ans;
        for(int a = 0; a < n - 3; a++) {
            if(a > 0 && nums[a] == nums[a-1]) continue;   // skip duplicates for a
            long long min1 = (long long)nums[a] + nums[a+1] + nums[a+2] + nums[a+3];
            if(min1 > target) break;                      // min sum too big
            long long max1 = (long long)nums[a] + nums[n-1] + nums[n-2] + nums[n-3];
            if(max1 < target) continue;                   // max sum too small
            for(int b = a + 1; b < n - 2; b++) {
                if(b > a + 1 && nums[b] == nums[b-1]) continue;   // skip duplicates for b
                long long min2 = (long long)nums[a] + nums[b] + nums[b+1] + nums[b+2];
                if(min2 > target) break;                      // min sum too big
                long long max2 = (long long)nums[a] + nums[b] + nums[n-1] + nums[n-2];
                if(max2 < target) continue;                   // max sum too small
                int c = b + 1, d = n - 1;
                while(c < d) {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum == target) {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});  // found quadruplet
                        c++; d--;
                        while(c < d && nums[c] == nums[c-1]) c++;  // skip duplicates
                        while(c < d && nums[d] == nums[d+1]) d--;
                    }
                    else if(sum < target) c++;   // need bigger sum
                    else d--;                     // need smaller sum
                }
            }
        }
        return ans;
    }
};