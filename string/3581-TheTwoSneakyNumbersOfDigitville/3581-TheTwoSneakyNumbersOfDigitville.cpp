// Last updated: 19/08/2026, 15:27:25
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