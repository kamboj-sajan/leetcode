// Last updated: 19/08/2026, 15:55:23
class Solution {
public: 
    int sumlessequal(vector<int>& nums, int goal){
        if(goal < 0)return 0;
        int l = 0 , r= 0;
        int cnt = 0;
        int sum = 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum = sum - nums[l];
               l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return (sumlessequal(nums, goal) - sumlessequal(nums, goal-1));
    }
};