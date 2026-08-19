// Last updated: 19/08/2026, 15:14:49
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long a = (1LL*nums[i] * nums[j])/pow(gcd(nums[i],nums[j]),2);
                ans = max(ans,a);
            }
        }
        return ans;
    }
};