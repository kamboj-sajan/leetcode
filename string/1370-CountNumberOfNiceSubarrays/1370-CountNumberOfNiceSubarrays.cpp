// Last updated: 19/08/2026, 15:50:20
class Solution {
public: 
    int sumlessequal(vector<int>& nums, int goal){
        if(goal < 0)return 0;
        int l = 0 , r= 0;
        int cnt = 0;
        int sum = 0;
        while(r < nums.size()){
            sum += (nums[r]%2);
            while(sum > goal){
                sum = sum - (nums[l]%2);
               l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (sumlessequal(nums,k) - sumlessequal(nums,k-1));
    }
};