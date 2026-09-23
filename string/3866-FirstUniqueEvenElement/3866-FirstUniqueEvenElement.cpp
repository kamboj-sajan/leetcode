// Last updated: 24/09/2026, 00:50:50
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
       unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); ++i){
            mpp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]%2 == 0 && mpp[nums[i]] == 1){
                return nums[i];
            }
        }
        return -1;
    }
};