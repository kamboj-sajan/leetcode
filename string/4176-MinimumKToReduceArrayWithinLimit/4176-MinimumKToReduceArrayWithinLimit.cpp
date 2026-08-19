// Last updated: 19/08/2026, 15:18:17
class Solution {
public:
    bool f(int k,vector<int> &nums){
        long long b = 0;
        for(auto a : nums){
            b += (a + k-1)/k;
            if(b > 1LL*k*k)return false;
        }
        return true;
    }
public:
    int minimumK(vector<int>& nums) {
        int l =1;
        int r = 1e5;
        int ans = r;
        while(l <= r){
            int mid = l + (r -l) /2;
            if(f(mid,nums)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};