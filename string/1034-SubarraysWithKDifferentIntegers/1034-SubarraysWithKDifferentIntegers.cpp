// Last updated: 19/08/2026, 15:54:23
class Solution {
public:
    int subarraylek(vector<int>& nums, int k){
        int l = 0, r = 0;
        int cnt = 0;
        map<int,int> mpp;
        while(r < nums.size()){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0)mpp.erase(nums[l]);
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = subarraylek(nums,k) - subarraylek(nums,k-1);
        return a;
    }
};