// Last updated: 19/08/2026, 15:18:41
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(k >= n)return 0;
        sort(nums.begin(),nums.end());
        long long sl = 0;
        long long lg = 0;
        for(int i=0; i<k; ++i){
            sl += nums[i];
        }
        for(int i=n-1; i>= n-k; --i){
            lg += nums[i];
        }
        return (int)(lg - sl);
    }
};