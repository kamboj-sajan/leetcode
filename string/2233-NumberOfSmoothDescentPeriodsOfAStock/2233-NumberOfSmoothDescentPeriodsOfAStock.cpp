// Last updated: 19/08/2026, 15:33:13
// class Solution {
// public:
//     long long getDescentPeriods(vector<int>& prices) {
//         long long ans = 1;
//         long long len = 1;
//         for(int i=1; i<prices.size(); ++i){
//             if(prices[i-1] - 1 == prices[i]){
//                 len++;
//             }else{
//                 len = 1;
//             }
//             ans += len;
//         }
//         return ans;
//     }
// };


// brute force 
// class Solution {
// public:
//     long long getDescentPeriods(vector<int>& prices) {
//         long long ans = 0;
//         int n = prices.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 bool valid = true;

//                 for (int k = i; k < j; k++) {
//                     if (prices[k] - prices[k + 1] != 1) {
//                         valid = false;
//                         break;
//                     }
//                 }

//                 if (valid)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };

// better

// class Solution {
// public:
//     long long getDescentPeriods(vector<int>& prices) {
//         long long ans = 0;
//         int n = prices.size();

//         for (int i = 0; i < n; i++) {
//             ans++;  // single-day subarray

//             for (int j = i + 1; j < n; j++) {
//                 if (prices[j - 1] - prices[j] == 1) {
//                     ans++;
//                 } else {
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

//optimal

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long len = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && prices[i - 1] - prices[i] == 1) {
                len++;        // extend current descent
            } else {
                len = 1;      // start new descent
            }
            ans += len;
        }
        return ans;
    }
};