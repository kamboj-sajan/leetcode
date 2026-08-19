// Last updated: 19/08/2026, 16:14:05
// class Solution {
// public:
//     int myAtoi(string s) {
//         int n = s.size();
//         int i = 0;
//         bool b = true;
//         while(i < n && s[i] == ' '){
//             i++;
//         }
//         if(i < n && s[i] == '-'){
//             b = false;
//             i++;
//         }else if(i < n && s[i] == '+'){
//             i++;
//         }
//         long long ans = 0;

//         while(i < n && s[i] >= '0' && s[i] <= '9'){
//             int c = s[i] - '0';

//             ans = ans * 10 + c;

//             if(b && ans > INT_MAX){
//                 return INT_MAX;
//             }

//             if(!b && ans > (long long)INT_MAX + 1){
//                 return INT_MIN;
//             }

//             i++;
//         }

//         if(!b){
//             ans *= -1;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while (i < n && s[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        long long ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (sign == 1 && ans > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -ans < INT_MIN)
                return INT_MIN;
            i++;
        }
        return (int)(sign * ans);
    }
};