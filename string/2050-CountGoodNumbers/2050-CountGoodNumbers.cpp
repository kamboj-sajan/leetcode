// Last updated: 19/08/2026, 15:35:03
// class Solution {
// public:
//     bool check(string &temp){
//         for (int j = 0; j < temp.size(); j++) {
//             if (j % 2 == 0) {  
//                 if (temp[j] != '0' && temp[j] != '2' && temp[j] != '4' && temp[j] != '6' && temp[j] != '8') {
//                     return false;  
//                 }
//             } else { 
//                 if (temp[j] != '2' && temp[j] != '3' && temp[j] != '5' && temp[j] != '7') {
//                     return false; 
//                 }
//             }
//         }
//         return true;
//     }
// public:
//     int f(vector<string> &str,long long ans){
//         for(int i=0; i<str.size(); i++){
//             if(check(str[i])){
//                 ans++;
//             }
//         }
//         return ans;
//     }
// public:
//     int countGoodNumbers(long long n) {
//         long long ans = 0;
//         vector<string> str;
//         long long total = (long long)(pow(10,n));
//         for(long i=0; i<=total-1; i++){
//            string num = to_string(i);
//            while(num.size() < n) num = "0" + num;
//            str.push_back(num);
//         }
//         return f(str,ans);
//     }
// };
// it cn handle atmost n = 18
//bcz of this long long total = (long long)(pow(10,n));
// for example pow(10,50) will give 10^50 outside of range of long long


// class Solution {
// public:
//     int countGoodNumbers(long long n) {
//         long long ans = 1;
//         int modu = 1e9 + 7;
// //int modu = pow(10, 9) + 8;
// // code gives tle after the 69 test case
//     for(int i = 0; i<n; i++){
//         if(i%2 == 0){
//             ans = (ans * 5) % modu;
//         }
//         else{
//             ans = (ans * 4) % modu;
//         }
//     } 
//     return ans;
//     }
// };

class Solution {
const long long mod = 1000000007;
public:
    long long power(long long x, long long y){
        if(y==0)return 1;
        long long ans = power(x,y/2);
        ans = (ans * ans) % mod;
        if (y % 2 == 1)ans = (ans * x) % mod;
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
       long long odd = n/2;
       long long even = n/2 + n%2;
       return (power(5,even)*power(4,odd))%mod;
    }
};
