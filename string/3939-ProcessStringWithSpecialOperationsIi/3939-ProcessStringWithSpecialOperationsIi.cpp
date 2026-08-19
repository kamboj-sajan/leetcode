// Last updated: 19/08/2026, 15:23:25
// class Solution {
// public:
//     char processStr(string s, long long k) {
//        int n = s.size();
//         string ans = "";
//         for(char c : s){
//          if(c >= 'a' && c <= 'z'){
//             ans.push_back(c);
//          }
//          else if(c == '*'){
//             if(!ans.empty()) ans.pop_back();
//          }
//          else if(c=='#'){
//             ans+=ans;
//          }else if(c == '%'){
//             reverse(ans.begin(),ans.end());
//          }
//         }
//         if(k > ans.size()-1 || ans == "")return '.';
//         else return ans[k];  
//     }
// };

class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Step 1: compute final length
        for (char c : s) {
            if (c == '*') {
                len = max(0LL, len - 1);
            }
            else if (c == '#') {
                len *= 2;
            }
            else if (c != '%') {
                len++;
            }
        }

        // boundary check
        if (k >= len) return '.';

        // Step 2: backward simulation
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '*') {
                len++;
            }

            else if (c == '#') {
                long long half = len / 2;

                if (k >= half) {
                    k -= half;
                }

                len = half;
            }

            else if (c == '%') {
                k = len - 1 - k;
            }

            else {
                if (k == len - 1) {
                    return c;
                }
                len--;
            }
        }

        return '.';
    }
};