// Last updated: 19/08/2026, 15:31:08
// class Solution {
// public:
//     int bestClosingTime(string customers) {
//         int n = customers.size();
//         int ans = -1;
//         int p;
//         int minip = INT_MAX;
//         for(int i=0; i<n; ++i){
//             p = 0;
//             for(int j=0; j<n; ++j){
//                 if(j < i){
//                     if(customers[j] == 'N'){
//                         p++;
//                     }
//                 }
//                 else{
//                     if(customers[j] == 'Y')p++;
//                 }
//             }
//             if(p < minip){
//                     minip = p;
//                     ans = i;
//             }
//         }
//         p = 0;
//         for(int i=0; i<n; ++i){
//             if(customers[i] == 'N')p++;
//         }
//         if(p < minip)ans = n;
//         return ans;
//     }
// };

// class Solution {
// public:
//     int bestClosingTime(string customers) {
//         int n = customers.size();
//         int ans = n;
//         long long minip = 0;
//         for(int i=0; i<n; ++i){
//             if(customers[i] == 'N')minip++;
//         }
//         long long p = minip;
//         for(int i=n-1; i>=0; --i){
//             if(customers[i] == 'Y')p++;
//             else p--;
//             if(p <= minip){
//                 minip = p;
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int ans = n;

        // Penalty if we close at hour n
        long long minip = 0;
        for (char c : customers) {
            if (c == 'N') minip++;
        }

        long long p = minip;

        // Move closing time from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (customers[i] == 'Y') p++;  // Y becomes closed
            else p--;                      // N becomes closed

            if (p <= minip) {              // <= ensures earliest hour
                minip = p;
                ans = i;
            }
        }

        return ans;
    }
};
