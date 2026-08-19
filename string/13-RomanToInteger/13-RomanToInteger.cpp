// Last updated: 19/08/2026, 16:13:55
// class Solution {
// public:
//     int romanToInt(string s) {
//         unordered_map<char,int> mpp;
//         int n = s.size();
//         mpp['I'] = 1;
//         mpp['X'] = 10;
//         mpp['V'] = 5;
//         mpp['L'] = 50;
//         mpp['C'] = 100;
//         mpp['D'] = 500;
//         mpp['M'] = 1000;
//         int ans = 0;
//         if(n==1)return mpp[s[0]];
//         for(int i=0; i<s.size()-1; i++){
//             if(mpp[s[i]] < mpp[s[i+1]]){
//                 ans += (mpp[s[i+1]] - mpp[s[i]]);
//                 i++;
//             }else{
//                 ans += mpp[s[i]];
//             }
//         }
//         if(mpp[s[n-2]] >= mpp[s[n-1]])ans += mpp[s[n-1]];
//         return ans;
//     }
// };

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int x = 0, y = 0;

            if (s[i] == 'I') x = 1;
            else if (s[i] == 'V') x = 5;
            else if (s[i] == 'X') x = 10;
            else if (s[i] == 'L') x = 50;
            else if (s[i] == 'C') x = 100;
            else if (s[i] == 'D') x = 500;
            else x = 1000;

            if (i + 1 < s.size()) {
                if (s[i+1] == 'I') y = 1;
                else if (s[i+1] == 'V') y = 5;
                else if (s[i+1] == 'X') y = 10;
                else if (s[i+1] == 'L') y = 50;
                else if (s[i+1] == 'C') y = 100;
                else if (s[i+1] == 'D') y = 500;
                else y = 1000;
            }

            if (x < y) ans -= x;
            else ans += x;
        }

        return ans;
    }
};