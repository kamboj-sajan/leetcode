// Last updated: 19/08/2026, 15:53:56
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