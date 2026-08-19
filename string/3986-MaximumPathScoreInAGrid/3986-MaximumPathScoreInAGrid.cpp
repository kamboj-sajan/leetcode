// Last updated: 19/08/2026, 15:22:13
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> par(m,vector<pair<int,int>>(n));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 0)par[i][j] = {0,0};
                else if(grid[i][j] == 1)par[i][j] = {1,1};
                else par[i][j] = {1,2};
            }
        }
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        dp[0][0] = 0;
        for(int i=0; i<m; ++i){
            vector<vector<int>> nw(n,vector<int>(k+1,-1));
            for(int j=0; j<n; ++j){
                for(int l=0; l<=k; ++l){
                    if(dp[j][l] < 0)continue;
                    int costnw = l + par[i][j].first;
                    if(costnw > k)continue;
                    int scorenw = dp[j][l] + par[i][j].second;
                    nw[j][costnw] = max(nw[j][costnw],scorenw);
                }
                if(j > 0){
                    for(int l=0; l<=k; ++l){
                        if(nw[j-1][l] < 0)continue;
                        int costnw = l + par[i][j].first;
                        if(costnw > k)continue;
                        int scorenw = nw[j-1][l] + par[i][j].second;
                        nw[j][costnw] = max(nw[j][costnw],scorenw);
                    }
                }
            }
            dp = move(nw);
        }
        int ans = -1;
        for(int l=0; l<=k; ++l){
            ans = max(ans,dp[n-1][l]);
        }
        return ans;
    }
};