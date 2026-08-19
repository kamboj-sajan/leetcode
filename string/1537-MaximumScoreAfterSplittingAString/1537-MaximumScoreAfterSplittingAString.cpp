// Last updated: 19/08/2026, 15:48:03
// class Solution {
// public:
//     int maxScore(string s) {
//         int n = s.size();
//         vector<int> pre(n, 0), suf(n, 0);
//         // prefix: count of zeros
//         for(int i = 0; i < n; ++i){
//             pre[i] = (s[i] == '0');
//             if(i > 0) pre[i] += pre[i-1];
//         }
//         // suffix: count of ones
//         for(int i = n-1; i >= 0; --i){
//             suf[i] = (s[i] == '1');
//             if(i < n-1) suf[i] += suf[i+1];
//         }
//         int maxi = 0;
//         // split at i → left [0..i], right [i+1..n-1]
//         for(int i = 0; i < n-1; ++i){
//             maxi = max(maxi, pre[i] + suf[i+1]);
//         }

//         return maxi;
//     }
// };

// class Solution {
// public:
//     int maxScore(string s) {
//         int n = s.size();
//         int cnt0 = 0;
//         int cnt1 = 0;
//         for(int i=0; i<n; ++i){
//             if(s[i] == '1')cnt1++;
//         }
//         int maxi = 0;
//         for(int i=1; i<n; ++i){
//             if(s[i-1] == '0')cnt0++;
//             else cnt1--;
//             maxi = max(maxi,cnt0+cnt1);
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maxScore(string s) {
    int n = s.size();
    int zero = 0 , one = 0;
    if(s[0]=='0') zero++;
    // if(s[0]=='1') one++;
    for(int i =1;i<n;i++){
        if(s[i]=='1') one++;
     }
    int maxi = INT_MIN;
    maxi = max(maxi , zero + one);
    for(int i =1;i<n-1;i++){
        if(s[i]=='1'){
            one--;
            maxi = max(zero + one , maxi);
        }
        else{//means zero
            zero++;
            maxi = max(zero+one , maxi);
        }
    }
         // maxi = max(zero+one , maxi);
         return maxi;
    }
}; 