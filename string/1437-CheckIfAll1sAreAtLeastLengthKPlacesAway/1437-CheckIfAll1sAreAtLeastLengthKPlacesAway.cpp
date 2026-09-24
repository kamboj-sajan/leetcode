// Last updated: 25/09/2026, 01:12:54
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int l = 0;
        int a = 0;
        for(int j=0; j<nums.size(); ++j){
            if(nums[j] == 1){
                a = j;
                break;
            }
        }
        for(int i=a+1; i<nums.size(); ++i){
            if(nums[i] == 1){
                if(l < k){
                    return false;
                }
                else l = 0;
            }else{
                l++;
            }
        }
        return true;
    }
};