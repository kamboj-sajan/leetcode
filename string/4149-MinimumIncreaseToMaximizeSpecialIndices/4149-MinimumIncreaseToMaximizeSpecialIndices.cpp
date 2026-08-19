// Last updated: 19/08/2026, 15:18:55
class Solution {
public:
    using ll = long long;
    ll f(vector<int>& nums,int i){
        ll a= max(nums[i-1],nums[i+1]) + 1;
        return a > nums[i] ? a-nums[i] : 0;
    }
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if(n%2 == 1){
            ll ans = 0;
            for(int i=1; i<n-1; i+=2){
                ans += f(nums,i);
            }
            return ans;
        }
        else{
            ll c = 0;
            for(int i=2; i<n-1; i+=2){
                c += f(nums,i);
            }
            ll mc = c;
            for(int i=1; i<n-1; i+=2){
                c += f(nums,i);
                c -= f(nums,i+1);
                if(c < mc){
                    mc = c;
                }
            }
            return mc;
        }
    }
};