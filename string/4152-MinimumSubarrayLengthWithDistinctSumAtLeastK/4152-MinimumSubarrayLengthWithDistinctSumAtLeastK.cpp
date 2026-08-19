// Last updated: 19/08/2026, 15:18:51
class Solution {
public:
    using ll = long long;
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        ll sum = 0;
        ll left =0;
        ll ans = INT_MAX;
        for(int i =0; i<n; ++i){
            mpp[nums[i]]++;
            if(mpp[nums[i]] == 1){
                sum += nums[i];
            }
            while(sum >= k){
                ans = min(ans,i-left+1);
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0){
                    sum -= nums[left];
                }
                left++;
            }
        }
        if(ans == INT_MAX)return -1;
        else return ans;
    }
};