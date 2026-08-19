// Last updated: 19/08/2026, 16:03:05
class Solution {
public:
    int maxCoins(vector<int>& nums) {
         int c = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(c+2,vector<int> (c+2,0));
        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if(i>j)continue;
                int maxi = INT_MIN;
                for(int ind=i; ind<=j; ind++){
                    int cost =  nums[i - 1] * nums[ind] * nums[j + 1]+dp[i][ind-1] + dp[ind+1][j];
                    maxi = max(maxi,cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][c];
    }
};