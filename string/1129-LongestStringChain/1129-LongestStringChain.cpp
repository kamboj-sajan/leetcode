// Last updated: 19/08/2026, 15:53:10
// class Solution {
// private:
//     bool checkPossible(string &s1, string &s2){
//         if(s1.size() != s2.size() + 1)return false;
//         int first = 0;
//         int second = 0;
//         while(first < s1.size()){
//             if(s1[first]  == s2[second]){
//                 first++;
//                 second++;
//             }
//             else{
//                 first++;
//             }
//         }
//         if(first == s1.size() && second == s2.size())return true;
//         return false;
//     }
// public:
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(),words.end(),[](string &a, string &b){
//             return a.size() < b.size();
//         });
//         int n = words.size();
//         vector<int> dp(n,1);
//         int maxi = 1;
//         for(int i=0;i<n;i++){
//             for(int prev=0;prev<i; prev++){
//                 if(checkPossible(words[i],words[prev]) && 1+dp[prev] > dp[i]){
//                     dp[i] = 1 + dp[prev];
//                 }
//             }
//             if(dp[i] > maxi){
//                 maxi = dp[i];
//             }
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> a(17);
        for(int i = 0; i < n; ++i)
            a[words[i].size()].push_back(i);
        vector<int> dp(n, 1);
        auto fun = [](string& s1, string& s2) -> bool {
            int n = s1.size(), m = s2.size(), i = 0, j = 0;
            bool f = 0;
            while(i < n && j < m) {
                if(s1[i] == s2[j]) {
                    ++i;
                    ++j;
                }
                else if(f)
                    return 0;
                else {
                    f = 1;
                    ++j;
                }
            }
            return 1;
        };
        int ans = 1;
        for(int i = 2; i < 17; ++i) {
            for(int id1: a[i]) {
                for(int id2: a[i - 1]) {
                    if(dp[id1] < dp[id2] + 1 && fun(words[id2], words[id1]))
                        dp[id1] = dp[id2] + 1;
                }
                ans = max(ans, dp[id1]);
            }
        }
        return ans;
    }
};