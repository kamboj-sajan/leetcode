// Last updated: 19/08/2026, 16:09:49
// class Solution {
// public:
//     int f(string s,int i,vector<int> &dp){
//         int n = s.size();
//         if(i == n)return 1;
//         if(s[i] == '0')return 0;
//         if(dp[i] != -1)return dp[i];
//         int ans = f(s,i+1,dp);
//         if(i+1 < n){
//             int num = (s[i] - '0') * 10 + s[i+1] - '0';
//             if(num >= 10 && num <= 26){
//                 ans += f(s,i+2,dp);
//             }
//         }
//         return dp[i] = ans;
//     }
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n+1,-1);
//         return f(s,0,dp);
//     }
// };

// class Solution {
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n + 1, 0);
//         dp[n] = 1;
//         for (int i = n - 1; i >= 0; i--) {
//             if (s[i] == '0') continue;
//             dp[i] = dp[i + 1];
//             if (i + 1 < n) {
//                 int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
//                 if (num >= 10 && num <= 26)
//                     dp[i] += dp[i + 2];
//             }
//         }
//         return dp[0];
//     }
// };


// class Solution {
// public:
//     int numDecodings(string s) {
//         if(s.length()==0 || s[0]=='0'){
//             return 0;
//         }
//         int prevCount = 1; 
//         int prevToPrevCount = 1; 
//         for(int i=1;i<s.length();i++){
//             int currentCount = 0; 
//             if(s[i]!='0'){
//                 currentCount = prevCount;
//             }
//             int twoDigit = stoi(s.substr(i-1,2));
//             if(twoDigit>=10 && twoDigit<=26){
//                 currentCount+=prevToPrevCount;
//             }
//             prevToPrevCount = prevCount;
//             prevCount = currentCount; 
//         }
//         return prevCount; 
//     }
// }
// ;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int next1 = 1; // dp[n]
        int next2 = 0; // dp[n+1] (dummy)

        for (int i = n - 1; i >= 0; i--) {
            int curr = 0;

            if (s[i] != '0') {
                curr = next1;

                if (i + 1 < n) {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                    if (num >= 10 && num <= 26)
                        curr += next2;
                }
            }

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};