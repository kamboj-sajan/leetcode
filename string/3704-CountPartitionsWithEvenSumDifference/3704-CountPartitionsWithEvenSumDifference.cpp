// Last updated: 19/08/2026, 15:26:07
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; ++i){
            sum += nums[i];
        }
        if(sum%2 != 0)return 0;
        else return n-1;
    }
};