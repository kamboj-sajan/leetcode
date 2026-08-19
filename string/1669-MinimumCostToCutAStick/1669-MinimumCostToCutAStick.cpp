// Last updated: 19/08/2026, 15:46:23
// class Solution {
// public:
//     int minCost(int n, vector<int>& cuts) {
//         vector<int> prev(n+1,0);
//         for(int i=0; i<n; i++){
//             prev[i] = i*cuts[0];
//         }
//         for(int i=1; i<n; i++){
//             for(int N=0; N<=n; N++){
//                 int notTake = prev[N];
//                 int take = INT_MAX;
//                 int rodlength = i+1;
//                 if(rodlength <= N)take = cuts[i] + prev[N-rodlength];
//                 prev[N] = min(take,notTake);
//             }
//         }
//         return prev[n];
//     }
// };

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int> (c+2,0));
        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if(i>j)continue;
                int mini = INT_MAX;
                for(int ind=i; ind<=j; ind++){
                    int cost = cuts[j+1]-cuts[i-1]+dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};