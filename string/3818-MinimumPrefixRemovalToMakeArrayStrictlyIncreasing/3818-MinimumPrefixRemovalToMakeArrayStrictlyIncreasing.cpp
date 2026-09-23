// Last updated: 24/09/2026, 00:51:31
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
       int i = n-1;
        while(i > 0 && nums[i] > nums[i-1]){
            i--;
        }
        return i;
    }
};