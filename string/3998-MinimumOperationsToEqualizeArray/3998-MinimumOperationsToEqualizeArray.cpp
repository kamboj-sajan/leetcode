// Last updated: 19/08/2026, 15:21:58
class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flag = true;
        for(int i=0; i<nums.size()-1; ++i){
            if(nums[i] != nums[i+1]){
                flag = false;
                break;
            }
        }
        if(flag)return 0;
        else return 1;
    }
};