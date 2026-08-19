// Last updated: 19/08/2026, 16:01:22
class Solution {
public:
    int minMoves(vector<int>& nums) {
        using ll = long long;
        
        ll mn = *min_element(nums.begin(), nums.end());
        ll res = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            res += (nums[i] - mn);
        }
        
        return (int)res;
    }
};