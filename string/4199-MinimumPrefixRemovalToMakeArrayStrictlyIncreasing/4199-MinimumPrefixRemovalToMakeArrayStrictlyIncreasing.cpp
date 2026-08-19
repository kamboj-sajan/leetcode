// Last updated: 19/08/2026, 15:17:41
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