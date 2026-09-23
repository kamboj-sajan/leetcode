// Last updated: 24/09/2026, 00:48:18
class Solution {
public:
    using ll = long long;
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        ll sum1 = 0;
        ll sum2 = 0;
        for(int i=0; i<n; i++){
            if(i < n/2)sum1 += nums[i];
            else sum2 += nums[i];
        }
        int ans = 0;
        if(sum1 > sum2)ans++;
        for(int i=0; i<n-1; i++){
            sum1 -= nums[i];
            sum1 += (nums[n/2+i]);
            sum2 -= nums[n/2+i];
            sum2 += (nums[i]);
            if(sum1 > sum2)ans++;
        }
        return ans;
    }
};