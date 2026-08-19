// Last updated: 19/08/2026, 16:12:55
// // class Solution {
// // public:
// //     int strStr(string haystack, string needle) {
// //         int n = haystack.size();
// //         for(int i=0; i<n; i++){
// //             for(int j=i; j<n; ++j){
// //                 string str = haystack.substr(i,j-i+1);
// //                 if(str == needle)return i;
// //             }
// //         }
// //         return -1;
// //     }
// // };

// // class Solution {
// // public:
// //     void computelps(string str,vector<int> &lps){
// //         int i = 1;
// //         int len = 0;
// //         lps[0] = 0;
// //         while(i < str.length()){
// //             if(str[i] == str[len]){
// //                 len++;
// //                 lps[i] = len;
// //                 i++;
// //             }else{
// //                 if(len != 0){
// //                     len = lps[len - 1];
// //                 }else{
// //                     lps[i] = 0;
// //                     i++;
// //                 }
// //             }
// //         }
// //         return;
// //     }
// //     int strStr(string haystack, string needle) {
// //         vector<int> lps(needle.length(),0);
// //         computelps(needle,lps);
// //         int i = 0;
// //         int j = 0;
// //         while(i < haystack.length()){
// //             if(haystack[i] == needle[j]){
// //                 i++;
// //                 j++;
// //                 if(j == needle.length())return i - j;
// //             }else{
// //                 if(j != 0){
// //                     j = lps[j - 1];
// //                 }else{
// //                     i++;
// //                 }
// //             }
// //         }
// //         return -1;
// //     }
// // };

// // class Solution {
// // public:
// //     int strStr(string haystack, string needle) {
// //        int len = needle.length();
// //        for(int i=0; i<haystack.size(); ++i){
// //         if(haystack[i] == needle[0]){
// //             if(haystack.substr(i,len) == needle){
// //                 return i;
// //             }
// //         }
// //        }
// //        return -1;
// //     }
// // };

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.size();
//         int m = needle.size();
//         vector<int> lps(m,0);
//         int pr = 0;
//         int suf = 1;
//         while(suf < m){
//             if(needle[pr] == needle[suf]){
//                 lps[suf] = pr +1;
//                 suf++;
//                 pr++;
//             }else{
//                 if(pr == 0){
//                     lps[suf] = 0;
//                     suf++;
//                 }else{
//                     pr = lps[pr-1];
//                 }
//             }
//         }
//         int i= 0;
//         int j = 0;
//         while(i < haystack.length()){
//             if(haystack[i] == needle[j]){
//                 i++;
//                 j++;
//                 if(j == needle.length())return i - j;
//             }else{
//                 if(j == 0){
//                     i++;
//                 }else{
//                     j = lps[j-1];
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m == 0)
            return 0;

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == m)
                return i;
        }

        return -1;
    }
};