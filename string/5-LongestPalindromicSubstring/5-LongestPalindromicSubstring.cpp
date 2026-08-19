// Last updated: 19/08/2026, 16:14:19
// // // // class Solution {
// // // // public:
// // // //     bool f(string &s){
// // // //         int n = s.size();
// // // //         for(int i=0; i<n/2; i++){
// // // //             if(s[i] != s[n-i-1])return false;
// // // //         }
// // // //         return true;
// // // //     }
// // // // public:
// // // //     string longestPalindrome(string s) {
// // // //         int n = s.size();
// // // //         string ans = "";
// // // //         for(int i=0; i<n; i++){
// // // //             for(int j=i; j<n; j++){
// // // //                 string d = s.substr(i,j-i+1);
// // // //                 if(f(d) && d.size() > ans.size())ans = drrrrrrrr;
// // // //             }
// // // //         }
// // // //         return ans;
// // // //     }
// // // // };

// // // class Solution {
// // // public:
// // //     string ans = "";
// // //     void g(int l,string &s,int r){
// // //         while(l >= 0 && r < s.size() && s[l] == s[r]){
// // //             if(r-l+1 > ans.size()){
// // //                 ans = s.substr(l,r-l+1);
// // //             }
// // //             l--;
// // //             r++;
// // //         }        
// // //     }

// // // public:
// // //     string longestPalindrome(string s) {
// // //        int n = s.size();
// // //        for(int i=0; i<n; i++){
// // //         g(i,s,i);//odd
// // //         g(i,s,i+1);//even
// // //        }
// // //        return ans;
// // //     }
// // // };

// // class Solution {
// // public:
// //     int expand(string& s, int left, int right) {
// //         while (left >= 0 && right < s.length() && s[left] == s[right]) {
// //             left--;
// //             right++;
// //         } return right - left - 1;
// //     }
// //     string longestPalindrome(string s) {
// //         int start = 0;
// //         int maxLen = 0;
// //         for (int i = 0; i < s.length(); i++) {
// //             int len1 = expand(s, i, i);
// //             int len2 = expand(s, i, i + 1);
// //             int len = max(len1, len2);
// //             if (len > maxLen) {
// //                 maxLen = len;
// //                 start = i - (len - 1) / 2;
// //             }
// //         }
// //         return s.substr(start, maxLen);
// //     }
// // };

// // class Solution {
// // public:
//     // bool palindrome(string temp) {
//     //     int n = temp.size();
//     //     for (int i = 0; i < n / 2; ++i) {
//     //         if (temp[i] != temp[n - i - 1]) return false;
//     //     }
//     //     return true;
//     // }

// //     string longestPalindrome(string s) {
// //         if (s.size() <= 1) return s;
// //         string ans = s.substr(0, 1); // start with first char as a palindrome
// //         int i = 0;
// //         int j = s.size() - 1;

// //         while (i <= j) { // allow equal indices for single-char check
// //             string temp = s.substr(i, j - i + 1);
// //             if (palindrome(temp) && temp.size() > ans.size()) {
// //                 ans = temp;
// //             }
// //             // Instead of moving both ends, move only one pointer at a time
// //             if (j - i > 1) {
// //                 j--;
// //             } else {
// //                 i++;
// //                 j = s.size() - 1;
// //             }
// //         }
// //         return ans;
// //     }
// // }; tle

// // class Solution {
// // public:
// //     bool palindrome(string temp) {
// //         int left = 0, right = temp.size() - 1;
// //     while (left < right) {
// //         if (temp[left] != temp[right]) return false;
// //         left++;
// //         right--;
// //     }
// //     return true;
// //     }

// //     string longestPalindrome(string s) {
// //         if (s.size() <= 1) return s;
// //         string ans = s.substr(0, 1); // start with first char as a palindrome
// //         int i = 0;
// //         int j = s.size() - 1;

// //         while (i <= j) { // allow equal indices for single-char check
// //             string temp = s.substr(i, j - i + 1);
// //             if (palindrome(temp) && temp.size() > ans.size()) {
// //                 ans = temp;
// //             }
// //             // Instead of moving both ends, move only one pointer at a time
// //             if (j - i > 1) {
// //                 j--;
// //             } else {
// //                 i++;
// //                 j = s.size() - 1;
// //             }
// //         }
// //         return ans;
        
// //     }
// // }; tle
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if(s.length() <= 1){
//             return s;
//         }
//         int max_len = 1;
//         int start = 0;
//         int end = 0;
//         vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
//         for(int i=0; i<s.length(); ++i){
//             dp[i][i] = true;
//             for(int j=0; j<i; ++j){
//                 if(s[j] == s[i] && (i - j <= 2 || dp[j+1][i-1])){
//                     dp[j][i] = true;
//                     if(i - j + 1 > max_len){
//                         max_len = i - j + 1;
//                         start = j;
//                         end = i;
//                     }
//                 }
//             }
//         } 
//         return s.substr(start,end - start + 1);
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, len = 1;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    start = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    start = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, len);
    }
};