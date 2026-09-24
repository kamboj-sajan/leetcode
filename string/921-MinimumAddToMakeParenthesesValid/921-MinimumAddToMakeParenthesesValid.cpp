// Last updated: 25/09/2026, 01:18:50
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         int cnt1 = 0;
//         int ans = 0;
//         for(char c : s){
//             if(c == '('){
//                 cnt1++;
//                 ans++;
//             }else{
//                 if(cnt1 ==0)ans++;
//                 else{
//                     cnt1--;
//                     ans--;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minAddToMakeValid(string s) {
        int op=0,cl=0,ans=0;
        for(char x:s){
            if(x=='(') op++;
            else cl++;
            if(cl>op){
                ans++;
                op++;
            }
        }
        return ans+op-cl;
    }
};