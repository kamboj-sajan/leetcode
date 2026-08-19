// Last updated: 19/08/2026, 15:21:05
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0; i<n; ++i){
            unordered_map<int,int> f;
            int e1 = 0;
            int o1 = 0;
            for(int j=i; j<n; ++j){
               if(++f[nums[j]] == 1){
                   if(nums[j] %2 == 0)e1++;
                   else o1++;
               }
                if(e1 == o1)maxi = max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};