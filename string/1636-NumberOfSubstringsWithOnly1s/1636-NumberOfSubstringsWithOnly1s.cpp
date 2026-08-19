// Last updated: 19/08/2026, 15:46:49
// class Solution {
// public:
//     int numSub(string s) {
//         int n = s.size();
//         long ans = 0;
//         for(int i=0; i<n; ++i){
//             for(int j=i; j<n; ++j){
//                 if(s[j] == '1')ans++;
//                 else break;
//             }
//         }
//         return (int)ans;
//     }
// };

// class Solution {
// public:
//     const long long mod = 1e9+7;
//     int numSub(string s) {
//         int n = s.size();
//         long long ans = 0;
//         int cnt = 0;
//         for(char c : s){
//             if(c == '0'){
//                 ans = (ans + (long long)cnt*(cnt+1)/2%mod);
//                 cnt = 0;
//             }
//             else cnt++;
//         }
//         ans = (ans + (long long)cnt*(cnt+1)/2%mod);
//         return ans;
//     }
// };

class Solution {
public:
    const int mod = 1000000007;

    long long count(long long len) {
        return len * (len + 1) / 2;
    }

    int numSub(string s) {
        long long len = 0, ans = 0;
        for (char c : s) {
            if (c == '1') len++;
            else {
                ans = (ans + count(len)) % mod;
                len = 0;
            }
        }
        if (len) ans = (ans + count(len)) % mod;
        return ans % mod;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();