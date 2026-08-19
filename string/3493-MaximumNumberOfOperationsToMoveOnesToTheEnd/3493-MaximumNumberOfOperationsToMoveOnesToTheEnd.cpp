// Last updated: 19/08/2026, 15:27:35
// class Solution {
// public:
//     int maxOperations(string s) {
//         int n = s.size();
//         int i = 0;
//         int j = 1;
//         int ans = 0;
//         while(i<n){
//             if(s[i] == '1' && s[i+1] == '0'){
//                 ans += j;
//                 j++;
//                 i++;
//                 continue;
//             }
//             if(s[i] == '1' && s[i+1] == '1'){
//                 j++;
//                 i++;
//                 continue;
//             }
//             i++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxOperations(string s) {
//         int n = s.size();
//         int cnt = 0;
//         int cnt1 = (s[0] == '1');
//         for(int i = 1; i<n; ++i){
//             if(s[i] == '1')cnt1++;
//             else if(s[i-1] == '1')cnt += cnt1;
//         }
//         return cnt;
//     }
// };

// auto init = [](){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 'c';
// }();


class Solution {
public:
    long long maxOperations(const std::string& s) {
        long long result = 0, curr = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++curr;
            } else if (i + 1 == s.size() || s[i + 1] == '1') {
                result += curr;
            }
        }
        return result;
    }
};

