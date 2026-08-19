// Last updated: 19/08/2026, 16:12:23
// class Solution {
// public:
//     string countAndSay(int n) {
//         string ans = "1";
//         for (int k = 2; k <= n; k++) {
//             string temp = "";
//             for (int i = 0; i < ans.size(); ) {
//                 int j = i;
//                 while (j < ans.size() && ans[j] == ans[i]) {
//                     j++;
//                 }
//                 int cnt = j - i;
//                 temp += to_string(cnt);
//                 temp += ans[i];
//                 i = j;
//             }
//             ans = temp;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string countAndSay(int n) {
        if(n<=0) return "";
        string cur = "1";

        for(int i = 1;i<n;++i){
            string next_seq = "";
            int count =1;
        
        for(int j=0;j<cur.length();++j){
            if(j+1<cur.length()&&cur[j]==cur[j+1]){
                count++;
            }else{
                next_seq+=to_string(count)+cur[j];
                count=1;
            }
        }     
        cur=next_seq;
      }
      return cur;
    }
};