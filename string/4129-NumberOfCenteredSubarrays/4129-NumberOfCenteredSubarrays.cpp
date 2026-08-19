// Last updated: 19/08/2026, 15:19:17
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int ans = 0;
        for(int i=0; i<n; ++i){
            int sum = 0;
            mpp.clear();
            for(int j=i; j<n; ++j){
                if(i ==j){
                    ans++;
                    mpp[nums[i]]++;
                    sum += nums[i];
                    continue;
                }else{
                    mpp[nums[j]]++;
                    sum += nums[j];
                    if(mpp.find(sum) != mpp.end())ans++;
                }
            }
        }
        return ans;
    }
};