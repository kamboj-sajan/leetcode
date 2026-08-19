// Last updated: 19/08/2026, 15:27:09
// class Solution {
// public:
//     vector<int> minBitwiseArray(vector<int>& nums) {
//         int n = nums.size();
//         bool a;
//         vector<int> ans;
//         for(int i=0; i<n; ++i){
//             a = true;
//             for(int j=1; j<=nums[i]; ++j){
//                 if((j | (j+1)) == nums[i]){
//                     ans.push_back(j);
//                     a = false;
//                     break;
//                 }
//             }
//             if(a == true)ans.push_back(-1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            int v = 1;
            bool found = false;
            while (v < x) {
                if ( ( v | (v+1) ) == x ) {
                    ans.push_back(v);
                    found = true;
                    break;
                }
                ++v;
            }
            if (!found) ans.push_back(-1);
        }
        return ans;
    }
};