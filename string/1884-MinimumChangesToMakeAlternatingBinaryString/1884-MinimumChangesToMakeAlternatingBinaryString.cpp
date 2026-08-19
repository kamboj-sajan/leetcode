// Last updated: 19/08/2026, 15:36:48
// class Solution {
// public:
//     int minOperations(string s) {
//         int cnt0 = 0, cnt1 = 0;
//         for(int i=0; i<s.size(); ++i){
//             char exp0 = (i%2 == 0) ? '0' : '1';
//             char exp1 = (i%2 == 0) ? '1' : '0';
//             if(s[i] != exp0)cnt0++;
//             if(s[i] != exp1)cnt1++;
//         }
//         return min(cnt0,cnt1);
//     }
// };

// class Solution {
// public:
//     int minOperations(string s) {
//         int diff = 0;
//         for(int i = 0; i < s.size(); i++)
//             diff += (s[i] != (i % 2 ? '1' : '0'));
//         return min(diff, (int)s.size() - diff);
//     }
// };

class Solution {
public:
    int minOperations(string s) {
        int start0=0;
        int start1=0;  

        for(int i = 0; i < s.length(); i++) {
            
            if(i % 2 == 0) {
                if(s[i] != '0'){
                     start0++;
                }
                if(s[i] != '1') {
                    start1++;
                }
            }
            else {
                if(s[i] != '1'){
                    start0++;
                } 
                if(s[i] != '0') {
                    start1++;
                }
            }
        }
        return min(start0,start1);
    }
};