// Last updated: 19/08/2026, 16:04:49
// class Solution {
// public:
//     string shortestPalindrome(string s) {
//        int n = s.size();
//         int i = 0;
//         int j = n-1;
//         while(i < j){
//             if(s[i] != s[j]){
//                 if(i == 0){
//                     s.insert(s.begin(),s[j]);
//                     i++;
//                     continue;
//                 }else{
//                     s.insert(s.begin()+i,s[j]);
//                     i++;
//                     continue;
//                 }
//             }
//             i++;
//             j--;
//         }
//         return s;
//     }
// }; wrong 53/126

// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         int n = s.size();
//         string orig = s;
//         string str = s;
//         reverse(s.begin(),s.end());
//         str += "*" + s;

//         // kmp
//         vector<int> lps(2*n+1,0);
//         int i = 0;
//         int j = 1;
//         lps[0] = 0;
//         while(j < str.size()){
//             if(str[i] == str[j]){
//                 lps[j] = i+1;
//                 i++;
//                 j++;
//             }else{
//                 if(i != 0){
//                     i = lps[i-1];
//                 }else{
//                     lps[j] = 0;
//                     j++;
//                 }
//             }
//         }
//         int diff = n - lps[2*n];
//         orig = s.substr(0,diff) + orig;
//         return orig;
//     }
// };

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string t=s+"#"+rev;
        vector<int> lps(t.size(),0);
        for(int i=1;i<t.size();i++){
            int j=lps[i-1];
            while(j>0 && t[i]!=t[j]) j=lps[j-1];
            if(t[i]==t[j]) j++;
            lps[i]=j;
        }
        int palLen=lps.back();
        return rev.substr(0,rev.size()-palLen)+s;
    }
};