// Last updated: 19/08/2026, 15:16:56
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