// Last updated: 19/08/2026, 15:22:29
// class Solution {
// // public: 
// //     vector<int> g(vector<int> &strategy,int index,int k){
// //         vector<int> temp;
// //         int n = strategy.size();
// //         for(int i=0; i<strategy.size(); i++){
// //             if(i >= index && i <min(n,index + k/2)){
// //                 temp.push_back(0);
// //             }else if(i >= index+ k/2 && i < min(n,index + k)){
// //                 temp.push_back(1);
// //             }else temp.push_back(strategy[i]);
// //         }
// //         return temp;
// //     }
// // public:
// //     long long f(vector<int> &prices,vector<int> &strategy,int k){
// //          long long base = 0;
// //         for (int i = 0; i < prices.size(); i++) {
// //             base += 1LL * prices[i] * strategy[i];
// //         }
// //         long long maxa = base;
// //        for(int i=0; i+k<=prices.size(); ++i){
// //            vector<int> temp = g(strategy,i,k);
// //            long long sum = 0;
// //            for(int j = 0; j<prices.size(); j++){
// //                sum += prices[j]*temp[j];
// //            }
// //            maxa = max(maxa,sum);
// //        }
// //         return maxa;
// //     }

// public:
//     long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
//         // return f(prices,strategy,k);
//         int n = prices.size();
//         long long initial = 0;
//         for(int i=0; i<n; i++){
//             initial += 1LL*prices[i]*strategy[i];
//         }
//         vector<long long> org(n+1,0);
//         vector<long long> prc(n+1,0);
//          for (int i = 0; i < n; i++) {
//             org[i+1] = org[i] + 1LL * strategy[i] * prices[i];
//             prc[i+1] = prc[i] + prices[i];
//         }
//         long long bestd = 0;
//         for (int i = 0; i + k <= n; i++) {
//             int mid = i + k/2;
//             long long lose = org[mid] - org[i];
//             long long gain = (prc[i+k] - prc[mid]) - (org[i+k] - org[mid]);
//             long long delta = -lose + gain;
//             bestd = max(bestd, delta);
//         }
//         return initial + bestd;
//     }
// };

const int N=1e5+1;
long long sum[N];
class Solution {
public:
    static long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        const int n=prices.size(), k2=k/2;
        memset(sum, 0, sizeof(long long)*(n+1));
        for(int i=0; i<n; i++){
            sum[i+1]=sum[i]+1LL*strategy[i]*prices[i];
        }

        long long modify=reduce(prices.begin()+k/2, prices.begin()+k, 0LL);
        long long profit=max(sum[n], modify+sum[n]-sum[k]);

        for(int i=1; i+k<=n; i++){ 
            modify+=prices[i+k-1]-prices[i+k2-1];
            profit=max(profit, modify+sum[n]-sum[i+k]+sum[i]);
        }
        return profit;
    }
};
