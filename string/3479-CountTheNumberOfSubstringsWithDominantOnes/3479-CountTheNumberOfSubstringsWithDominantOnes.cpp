// Last updated: 19/08/2026, 15:27:48
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int ans = 0;
//         for(int i=0; i<n; ++i){
//             for(int j=i; j<n; ++j){
//                 string str = s.substr(i,j-i+1);
//                 int c1 = 0,c0 = 0;
//                 for(int k=0; k<j-i+1; k++){
//                     if(str[k] == '1'){
//                         c1++;
//                     }else c0++;
//                 }
//                 if(c1 >= c0*c0)ans++;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int ans = 0;
//         for(int i=0; i<n; ++i){
//             int c1 = 0, c0 = 0;
//             for(int j=i; j<n; ++j){
//                 if(s[j] == '1')c1++;
//                 else c0++;
//                 if(c1 >= 1LL*c0*c0)ans++;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         vector<int> zero;
//         for(int i=0; i<n; ++i){
//             if(s[i] == '0')zero.push_back(i);
//         }
//         int ones = n - zero.size();
//         zero.push_back(n);
//         int res = 0;
//         int sid = 0;
//         for(int left = 0; left <n; left ++){
//             for(int id = sid; id < zero.size()-1; ++id){
//                 int cnt0 = id - sid + 1;
//                 if(cnt0 * cnt0 > ones)break;
//                 int p = zero[id], q = zero[id+1];
//                 int cnt1 = zero[id] - left -(id-sid);
//                 if(cnt1 >= cnt0*cnt0){
//                     res += q - p;
//                 }else{
//                     res += max(q-p-(cnt0 * cnt0 - cnt1), 0);
//                 }
//             }
//             if(s[left] == '0'){
//                 sid++;
//             }else{
//                 res += zero[sid] - left;
//                 ones--;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n + 1);
        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) {
                pre[i + 1] = i;
            } else {
                pre[i + 1] = pre[i];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt0 = s[i - 1] == '0';
            int j = i;
            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - pre[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1) {
                    res += min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
};