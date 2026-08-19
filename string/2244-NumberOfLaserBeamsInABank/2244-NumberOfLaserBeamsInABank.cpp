// Last updated: 19/08/2026, 15:33:03
// class Solution {
// public:
//     int numberOfBeams(vector<string>& bank) {
//         int ans = 0;
//         int prevel = 0;
//         int n = bank.size();
//         int m = bank[0].size();
//         for(int i=0; i<n; ++i){
//             int el = 0;
//             for(int j=0; j<m; ++j){
//                 if(bank[i][j] == '1'){
//                     el++;
//                 }
//             }
//             if(prevel == 0){
//                 prevel = el;
//                 continue;
//             }
//             if(el == 0){
//                 continue;
//             }else{
//                 ans += (prevel * el);
//                 prevel = el; 
//             }
//         }
//        return ans;
//     }
// };

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0;
        int prev = 0;
        int ans = 0;
        for(int i=0; i<bank.size(); ++i){
            cnt = 0;
            for(char c : bank[i]){
                if(c == '1'){
                    cnt++;
                }
            }
            if(cnt > 0){
                ans += cnt * prev;
                prev = cnt;
            }
        }
        return ans;
    }
};