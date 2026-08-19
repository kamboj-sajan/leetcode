// Last updated: 19/08/2026, 16:07:59
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int n = s.size();
//         string str;
//         for(int i=0; i<n; ++i){
//             if(s[i] >='A' && s[i] <= 'Z'){
//                 int a = s[i] - 'A';
//                 str += (a + 'a');
//             }else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'){
//                 str += s[i];
//             }
//         }
//         int k = str.size();
//         int i = 0;
//         int j = k - 1;
//         while(i < j){
//             if(str[i] != str[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string str = "";
//         for(char c: s){
//            if(isalnum(c)){
//             str+=tolower(c);
//            }
//         }
//         string str1 = str;
//         reverse(str1.begin(),str1.end());
//         return str==str1;       
        
//     }
// };

class Solution {
public:
    bool isPalindrome(string s) {
        if (s=="") return true;
        int n =  s.size();
        int left = 0;
        int right = n-1;

        while(left < right) {
            if(!isalnum(s[left])) {left++;continue;}
            if(!isalnum(s[right])) {right--;continue;}
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;

        }
        return true;}
};