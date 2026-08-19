// Last updated: 19/08/2026, 15:20:30
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
       unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); ++i){
            mpp[nums[i]]++;
        }
        int ans = 0;
        for(auto &a : mpp){
            if(a.second%k == 0){
                ans += (a.first * a.second);
            }
        }
        return ans;
    }
};