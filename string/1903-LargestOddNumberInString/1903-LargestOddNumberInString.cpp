// Last updated: 25/09/2026, 01:08:47
// class Solution {
// public:
//     string largestOddNumber(string num) {
//       string ans = "";
//       int n = num.size();
//       for(int i=n-1; i>=0; i--){
//         if((num[i] - '0')%2 != 0){
//             ans = num.substr(0,i+1);
//             break;
//         }
//       }
//       return ans;
//     }
// };

class Solution {
public:
    string largestOddNumber(string num) {
      int n = num.size();
      for(int i=n-1; i>=0; i--){
        if((num[i] - '0')%2 != 0){
            return num.substr(0,i+1);
        }
      }
      return "";
    }
};