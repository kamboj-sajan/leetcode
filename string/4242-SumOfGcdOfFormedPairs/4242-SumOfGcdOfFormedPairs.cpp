// Last updated: 19/08/2026, 15:17:14
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> vec;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); ++i){
            maxi = max(maxi,nums[i]);
            int el = gcd(nums[i],maxi);
            vec.push_back(el);
        }
        sort(vec.begin(),vec.end());
        long long ans = 0;
        int n = vec.size();
        for(int i=0; i<n/2; ++i){
            long long pe = gcd(vec[i],vec[n-i-1]);
            ans += pe;
        }
        return ans;
    }
};