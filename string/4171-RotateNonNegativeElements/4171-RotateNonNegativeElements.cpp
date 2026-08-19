// Last updated: 19/08/2026, 15:18:21
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> non;
        for(int i=0; i<n; ++i){
            if(nums[i] >= 0)non.push_back(nums[i]);
        }
        if(non.size() == 0)return nums;
        k %= non.size();
        reverse(non.begin(), non.begin() + k);
        reverse(non.begin() + k, non.end());
        reverse(non.begin(), non.end());
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                nums[i] = non[idx++];
            }
        }
        return nums;
    }
};