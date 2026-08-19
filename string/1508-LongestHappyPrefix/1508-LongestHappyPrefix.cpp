// Last updated: 19/08/2026, 15:48:26
// class Solution {
// public:
//     string longestPrefix(string s) {
//         int n = s.size();
//         vector<int> lps(n,0);
//         lps[0] = 0;
//         int i = 0;
//         int j = 1;
//         while(j < n){
//             if(s[i] == s[j]){
//                 lps[j] = i+1;
//                 i++;
//                 j++;
//             }else{
//                 if(i != 0){
//                   i = lps[i-1];
//                 }else{
//                     lps[j] = 0;
//                     j++;
//                 }
//             } 
//         }
//         return s.substr(0,lps[n-1]);
//     }
// };

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0); // longest prefix-suffix array

        int len = 0, i = 1;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len > 0){
                    len = lps[len - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return s.substr(0, lps[n - 1]);
    }
};