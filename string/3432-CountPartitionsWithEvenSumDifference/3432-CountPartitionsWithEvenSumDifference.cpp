// Last updated: 25/09/2026, 00:59:23
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