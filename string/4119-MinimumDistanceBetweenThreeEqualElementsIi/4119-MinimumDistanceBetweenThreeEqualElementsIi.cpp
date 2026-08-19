// Last updated: 19/08/2026, 15:19:32
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
         int n = nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<n; ++i){
            mpp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &p : mpp){
            auto &v = p.second;
            if(v.size() < 3)continue;
            for(int i=0; i<v.size()-2; ++i){
                int d = 2 * (v[i+2] - v[i]);
                ans = min(ans,d);
            }
        }
        if(ans == INT_MAX){
            ans = -1;
        }
        return ans;
    }
};