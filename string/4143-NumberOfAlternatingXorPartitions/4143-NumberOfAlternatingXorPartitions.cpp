// Last updated: 19/08/2026, 15:18:59
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> pr(n+1,0);
        for(int i=0; i<n; ++i){
            pr[i+1] = pr[i] ^ nums[i];
        }
        unordered_map<int,int> mpp1,mpp2;
        vector<int> dp1(n+1,0);
        vector<int> dp2(n+1,0);
        dp2[0] = 1;
        mpp2[pr[0]] = 1;
        for(int i=1; i<=n; ++i){
            int a = pr[i]^target1;
            int b = pr[i]^target2;
            if(mpp2.find(a) != mpp2.end()){
                dp1[i] = (dp1[i]+mpp2[a])%mod;
            }
            if(mpp1.find(b) != mpp1.end()){
                dp2[i] = (dp2[i]+mpp1[b])%mod;
            }
            mpp1[pr[i]] = (mpp1[pr[i]]+dp1[i])%mod;
            mpp2[pr[i]] = (mpp2[pr[i]]+dp2[i])%mod;
        }
        return (dp1[n]+dp2[n])%mod;
    }
};