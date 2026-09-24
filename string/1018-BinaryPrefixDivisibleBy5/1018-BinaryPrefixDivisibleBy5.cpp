// Last updated: 25/09/2026, 01:17:33
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int cur = 0;
        for(int bit : nums){
            cur = ((cur << 1) + bit) % 5;
            ans.push_back(cur == 0);
        }
        return ans;
    }
};