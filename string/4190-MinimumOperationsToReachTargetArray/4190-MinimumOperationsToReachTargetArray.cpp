// Last updated: 19/08/2026, 15:17:47
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int left = n;
        int ans = 0;
        unordered_map<int,int> vis;
        for(int i=0; i<n; ++i){
            if(nums[i] != target[i]){
            if(vis.find(nums[i]) == vis.end()){
                 vis[nums[i]]++;
                 ans++;
            }
            }
        }
        return ans;
    }
};