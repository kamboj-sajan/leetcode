// Last updated: 19/08/2026, 15:29:47
// class Solution {
// public:
//     string maximumOddBinaryNumber(string s) {
//         int n = s.size();
//         int cnt0 = 0;
//         int cnt1 = 0;
//         for(int i=0; i<n; ++i){
//             if(s[i]== '0')cnt0++;
//             else cnt1++;
//         }
//         string ans = "";
//         while(cnt1 > 1){
//             ans += '1';
//             cnt1--;
//         }
//         while(cnt0 >0){
//             ans += '0';
//             cnt0--;
//         }
//         ans += '1';
//         return ans;
//     }
// };

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        for(auto c: s){
            if(c=='1'){
                ones++;
            }
        }

        int zeros= s.length()- ones;

        string ans="";
        ans.append(ones-1, '1');
        ans.append(zeros, '0');
        ans.push_back('1');

        return ans;
    }
};