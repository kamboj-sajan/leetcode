// Last updated: 19/08/2026, 15:58:26
// // class Solution {
// // public:
// //     int f(string &s){
// //         int cnt = 0;
// //         int n = s.size();
// //         for(char c : s){
// //             cnt += ((c - 'a')*(int)pow(26,n-1));
// //             n--;
// //         }
// //         return cnt;
// //     }
// //     bool ch(string &a,string&b){
// //         for(int i=0; i<a.size(); i++){
// //             if(a[i] != b[i])return false;
// //         }
// //         return true;
// //     }
// //     bool rabk(string &a,string &b){
// //         int n = a.size();
// //         int m = b.size();
// //         int as = f(a);
// //         int ts = 0;
// //         for(int i=0; i<m-n+1; i++){
// //             if(i == 0){
// //                 string temp = b.substr(0,n);
// //                 ts = f(temp);
// //                 if(as == ts){
// //                     if(ch(a,temp)){
// //                         return true;
// //                     }
// //                 }
// //             }else{
// //                 ts -= ((b[i-1]-'a')*pow(26,n-1));
// //                 ts *= 26;
// //                 ts += (b[i+n-1] - 'a');
// //                 string temp = b.substr(i,n);
// //                 if(as == ts){
// //                     if(ch(a,temp)){
// //                         return true;
// //                     }
// //                 }
// //             }
// //         }
// //         return false;
// //     }
// // public:
// //     int repeatedStringMatch(string a, string b) {
// //         int cnt = 1;
// //         while(a.size() < b.size()){
// //             a += a;
// //             cnt++;
// //         }
// //         if(rabk(b,a)){
// //             return cnt;
// //         }
// //         return -1;
// //     }
// // };

// class Solution {

// public:
//     long long f(string& s) {

//         long long cnt = 0;

//         long long mod = 1e9 + 7;

//         for (char c : s) {

//             cnt = (cnt * 26 + (c - 'a')) % mod;
//         }

//         return cnt;
//     }

//     bool ch(string& a, string& b) {

//         for (int i = 0; i < a.size(); i++) {

//             if (a[i] != b[i])
//                 return false;
//         }

//         return true;
//     }

//     bool rabk(string& a, string& b) {

//         int n = a.size();

//         int m = b.size();

//         long long mod = 1e9 + 7;

//         long long as = f(a);

//         long long ts = 0;

//         long long power = 1;

//         for (int i = 0; i < n - 1; i++) {

//             power = (power * 26) % mod;
//         }

//         for (int i = 0; i < m - n + 1; i++) {

//             if (i == 0) {

//                 string temp = b.substr(0, n);

//                 ts = f(temp);

//                 if (as == ts) {

//                     if (ch(a, temp)) {

//                         return true;
//                     }
//                 }

//             }

//             else {

//                 ts = (ts - ((b[i - 1] - 'a') * power) % mod + mod) % mod;

//                 ts = (ts * 26) % mod;

//                 ts = (ts + (b[i + n - 1] - 'a')) % mod;

//                 string temp = b.substr(i, n);

//                 if (as == ts) {

//                     if (ch(a, temp)) {

//                         return true;
//                     }
//                 }
//             }
//         }

//         return false;
//     }

// public:
//     int repeatedStringMatch(string a, string b) {

//         string original = a;

//         int cnt = 1;

//         while (a.size() < b.size()) {

//             a += original;

//             cnt++;
//         }

//         if (rabk(b, a)) {

//             return cnt;
//         }

//         a += original;

//         if (rabk(b, a)) {

//             return cnt + 1;
//         }

//         return -1;
//     }
// };

// class Solution {
// public:
//  const long long mod = (1LL << 32);
//  vector<long long> p;
//     int f(string &a,long sum,string &b){
//         int n = a.size();
//         int n1 = b.size();
//          if(n < n1)return -1;
//         int i = 0;
//         while(i < n-n1+1){
//             long s2 = 0;
//             for(int j = i; j<i+n1; ++j){
//                 s2 = (s2 + 1LL * a[j] * p[n1 - (j - i) - 1]) % mod;
//             }
//             if(s2 == sum){
//                 bool flag = true;
//                 for(int k=0; k<n1; k++){
//                     if(a[i+k] != b[k]){
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if(flag == true)return i;
//             }
//             i++;
//         }
//         return -1;
//     }
// public:
//     int repeatedStringMatch(string a, string b) {
//         int n = a.size();
//         int n1 = b.size();
//         long sum = 0;

//         p.resize(n1 + 5, 1);
//         for (int i = 1; i <= n1; i++) {
//             p[i] = (p[i - 1] * 10) % mod;
//         }


//         for(int i=0; i<n1; ++i){
//             sum = (sum + b[i] * p[n1 - i - 1]) % mod;
//         }
//         int ans = -1;
//         int cnt = 1;
//         string org = a;
//         for(int i=0; i<n1 * 2 + n; ++i){
//             ans = f(a,sum,b);
//             if(ans != -1)return cnt;
//             cnt++;
//             a += org;
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//  const long long mod = (1LL << 32);
//  vector<long long> p;
//     int f(string &a,long sum,string &b){
//         int n = a.size();
//         int n1 = b.size();
//         if(n < n1)return -1;
//         long long s2 = 0;
//         for(int j=0; j<n1; j++){
//             s2 = (s2 + 1LL * a[j] * p[n1 - j - 1]) % mod;
//         }
//         if(s2 == sum){
//             if(a.substr(0,n1) == b)return 0;
//         }
//         for(int i=1; i<=n-n1; ++i){
//             s2 = (((s2 - 1LL * a[i-1] * p[n1 - 1]) % mod) + mod) % mod;
//             s2 = (s2 * 10 + a[i + n1 - 1]) % mod;
//             if(s2 == sum){
//                 if(a.substr(i,n1) == b)return i;
//             }
//         }
//         return -1;
//     }
// public:
//     int repeatedStringMatch(string a, string b) {
//         int n = a.size();
//         int n1 = b.size();
//         long sum = 0;

//         p.resize(n1 + 5, 1);
//         for (int i = 1; i <= n1; i++) {
//             p[i] = (p[i - 1] * 10) % mod;
//         }


//         for(int i=0; i<n1; ++i){
//             sum = (sum + b[i] * p[n1 - i - 1]) % mod;
//         }
//         int ans = -1;
//         int cnt = 1;
//         string org = a;
//         for(int i=0; i<n1 * 2 + n; ++i){
//             ans = f(a,sum,b);
//             if(ans != -1)return cnt;
//             cnt++;
//             a += org;
//         }
//         return -1;
//     }
// };


// class Solution {
// public:
//     const long long mod = (1LL << 32);
//     vector<long long> p;

//     // Rabin-Karp substring search with rolling hash
//     int f(string &a, long long sum, string &b) {
//         int n = a.size();
//         int n1 = b.size();
//         if (n < n1) return -1;

//         // Compute hash of first window
//         long long s2 = 0;
//         for (int j = 0; j < n1; j++) {
//             s2 = (s2 + 1LL * a[j] * p[n1 - j - 1]) % mod;
//         }

//         // Check first window
//         if (s2 == sum) {
//             if (a.substr(0, n1) == b) return 0;
//         }

//         // Slide window
//         for (int i = 1; i <= n - n1; i++) {
//             // Remove leftmost char, shift, add new char
//             s2 = ( ( (s2 - 1LL * a[i - 1] * p[n1 - 1]) % mod + mod ) % mod );
//             s2 = (s2 * 10 + a[i + n1 - 1]) % mod;

//             if (s2 == sum) {
//                 if (a.substr(i, n1) == b) return i;
//             }
//         }
//         return -1;
//     }

//     int repeatedStringMatch(string a, string b) {
//         int n = a.size();
//         int n1 = b.size();
//         long long sum = 0;

//         // Precompute powers of 10
//         p.resize(n1 + 5, 1);
//         for (int i = 1; i <= n1; i++) {
//             p[i] = (p[i - 1] * 10) % mod;
//         }

//         // Hash of b
//         for (int i = 0; i < n1; i++) {
//             sum = (sum + 1LL * b[i] * p[n1 - i - 1]) % mod;
//         }

//         string org = a;
//         int cnt = 1;
//         int maxRepeat = (n1 + n - 1) / n + 2;

//         for (int i = 0; i < maxRepeat; i++) {
//             if (f(a, sum, b) != -1) return cnt;
//             cnt++;
//             a += org;
//         }
//         return -1;
//     }
// };


// class Solution {
// public:
//     const long long mod = (1LL << 32);  // 2^32
//     const long long base = 131;         // hashing base
//     vector<long long> p;

//     // Rabin-Karp substring search with rolling hash
//     int f(string &a, long long sum, string &b) {
//         int n = a.size();
//         int n1 = b.size();
//         if (n < n1) return -1;

//         // Compute hash of first window
//         long long s2 = 0;
//         for (int j = 0; j < n1; j++) {
//             s2 = (s2 * base + a[j]) % mod;
//         }

//         // Check first window
//         if (s2 == sum) {
//             bool flag = true;
//             for (int k = 0; k < n1; k++) {
//                 if (a[k] != b[k]) { flag = false; break; }
//             }
//             if (flag) return 0;
//         }

//         // Precompute base^(n1-1)
//         long long highestPow = p[n1 - 1];

//         // Slide window
//         for (int i = 1; i <= n - n1; i++) {
//             // Remove leftmost char and add new char
//             s2 = ( (s2 - 1LL * a[i - 1] * highestPow) % mod + mod ) % mod;
//             s2 = (s2 * base + a[i + n1 - 1]) % mod;

//             if (s2 == sum) {
//                 bool flag = true;
//                 for (int k = 0; k < n1; k++) {
//                     if (a[i + k] != b[k]) { flag = false; break; }
//                 }
//                 if (flag) return i;
//             }
//         }
//         return -1;
//     }

//     int repeatedStringMatch(string a, string b) {
//         int n = a.size();
//         int n1 = b.size();
//         long long sum = 0;

//         // Precompute powers of base
//         p.resize(n1 + 5, 1);
//         for (int i = 1; i <= n1; i++) {
//             p[i] = (p[i - 1] * base) % mod;
//         }

//         // Hash of b
//         for (int i = 0; i < n1; i++) {
//             sum = (sum * base + b[i]) % mod;
//         }

//         string org = a;
//         int cnt = 1;
//         int maxRepeat = (n1 + n - 1) / n + 2;

//         for (int i = 0; i < maxRepeat; i++) {
//             if (f(a, sum, b) != -1) return cnt;
//             cnt++;
//             a += org;
//         }
//         return -1;
//     }
// };


// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//        string s = "";
//        int n = b.size()/a.size();
//        int cnt = n;
//        while(cnt--){
//         s = s + a;
//        }
//        if(s.find(b) != std::string::npos){
//         return n;
//        }
//        s = s + a;
//        if(s.find(b) != std::string::npos){
//         return n + 1;
//        }
//        s = s + a;
//        if(s.find(b) != std::string::npos){
//         return n + 2;
//        }
//        return -1;
//     }
// };

// class Solution {
// public:
//     void computelps(string str,vector<int> &lps){
//         int i = 1;
//         int len = 0;
//         lps[0] = 0;
//         while(i < str.length()){
//             if(str[i] == str[len]){
//                 len++;
//                 lps[i] = len;
//                 i++;
//             }else{
//                 if(len != 0){
//                     len = lps[len - 1];
//                 }else{
//                     lps[i] = 0;
//                     i++;
//                 }
//             }
//         }
//         return;
//     }

//     bool kmp(string str,string pat){
//         vector<int> lps(pat.length());
//         computelps(pat,lps);
//         int i = 0;
//         int j = 0;
//         while(i < str.length()){
//             if(str[i] == pat[j]){
//                 i++;
//                 j++;
//                 if(j == pat.length())return true;
//             }else{
//                 if(j != 0){
//                     j = lps[j-1];
//                 }else{
//                     i++;
//                 }
//             }
//         }
//         return false;
//     }
//     int repeatedStringMatch(string a, string b) {
//        string s = "";
//        int n = b.size()/a.size();
//        int cnt = n;
//        while(cnt--){
//         s = s + a;
//        }
//        if(kmp(s,b)){
//         return n;
//        }
//        s = s + a;
//        if(kmp(s,b)){
//         return n + 1;
//        }
//        s = s + a;
//        if(kmp(s,b)){
//         return n + 2;
//        }
//        return -1;
//     }
// };

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
       string s = "";
       int cnt = 0;
       while(s.size() < b.size()){
        s += a;
        cnt++;
       }
       if(s.find(b) != string::npos){
        return cnt;
       }
       s += a;
       cnt++;
       if(s.find(b) != string::npos){
        return cnt;
       }
       return -1;
    }
};


