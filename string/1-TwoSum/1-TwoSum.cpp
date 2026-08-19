// Last updated: 19/08/2026, 16:14:33
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more) != mpp.end()){
                // return Yes
                return {mpp[more] , i};
            }
            mpp[a] = i;
        }
        return {-1,-1};
    }
};