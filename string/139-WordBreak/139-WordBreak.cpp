// Last updated: 19/08/2026, 16:07:16
// class Solution {
// public:
//     bool f(int ind,string s,vector<string>& wordDict,vector<int> &dp){
//         if(ind >= s.size())return true;
//         if(dp[ind] != -1)return dp[ind];
        // for(int i=ind; i<s.size(); i++){
        //     string temp = s.substr(ind,i - ind +1 );
        //     for(string it : wordDict){
        //         if(temp == it){
        //             if(f(i+1,s,wordDict,dp))return dp[ind] = true;
        //         }
        //     }
        // }
        // return dp[ind] = false;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.size();
//         vector<int> dp(n,-1);
//         return f(0,s,wordDict,dp);
//     }
// };

// class Solution{
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.size();
//         vector<int> dp(n+1,0);
//         dp[n] = 1;
//         for(int i=n-1; i>=0; i--){
//             string temp = "";
//         for(int j=i; j<s.size(); j++){
//             temp += s[j];
//             for(string it : wordDict){
//                 if(temp == it){
//                     if(dp[j+1])dp[i] = 1;
//                 }
//             }
//         }
//         }
//         return dp[0];
//     }
// };

class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,0);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            string temp = "";
        for(int j=i; j<s.size(); j++){
            temp += s[j];
            if (dict.count(temp) && dp[j + 1]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};