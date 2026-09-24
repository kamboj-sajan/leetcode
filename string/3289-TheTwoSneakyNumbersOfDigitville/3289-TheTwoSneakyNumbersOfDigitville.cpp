// Last updated: 25/09/2026, 01:00:29
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0; i<n; ++i){
            mpp[nums[i]]++;
        }
        for(auto &p : mpp){
            if(p.second != 1){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};