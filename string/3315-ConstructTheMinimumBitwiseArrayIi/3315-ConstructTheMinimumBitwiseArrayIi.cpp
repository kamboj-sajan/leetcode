// Last updated: 25/09/2026, 01:00:15
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans;
        for(int n : nums) {
            if(n != 2) ans.push_back(n - ((n + 1) & (-n - 1)) / 2);
            else ans.push_back(-1);
        }   
        return ans;
    }
};