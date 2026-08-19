// Last updated: 19/08/2026, 15:53:12
// class Solution {
// public:
//     int f(vector<int> &arr,int k,int i){
//         int n = arr.size();
//         if(i>=n)return 0;
//         int temp = 0;
//         int cnt = 0;
//         int maxcost = INT_MIN;
//         for(int j=i; j<n; j++){
//             cnt++;
//             temp = max(temp,arr[j]);
//             if(cnt <= k){
//                 int cost = temp * cnt + f(arr,k,j+1);
//                 maxcost = max(cost,maxcost);
//             }else{
//                 break;
//             }
//         }
//         return maxcost;
//     }
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         return f(arr,k,0);
//     }
// };
class Solution{
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1; i>=0; i--){
            int len = 0; 
            int maxans = INT_MIN;
            int maxi = INT_MIN;
            for(int j=i; j<min(n,i+k); j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = maxi * len + dp[j+1];
                maxans = max(sum,maxans);
            }
            dp[i] = maxans;
        }
        return dp[0];
    }
};