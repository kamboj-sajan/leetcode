// Last updated: 19/08/2026, 15:54:04
// class Solution {
// public:
//     int bitwiseComplement(int n) {
//         int mask = 0;
//         int temp = n;
//         if(n == 0)return 1;
//         // Create mask with same number of bits as n
//         while (temp > 0) {
//             mask = (mask << 1) | 1;
//             temp >>= 1;
//         }

//         return n ^ mask;
//     }
// };


// class Solution
// {
// public:
//     string int_2_bin(int n)
//     {
//         string rez = "";
//         while (n)
//         {
//             rez += (n % 2) + '0';
//             n /= 2;
//         }
//         reverse(rez.begin(), rez.end());
//         return rez;
//     }
//     string comlpe(string s)
//     {
//         string rez = "";
//         for (char ch : s)
//             if (ch == '0')
//                 rez += '1';
//             else
//                 rez += '0';
//         return rez;
//     }
//     int bin_2_int(string s)
//     {
//         int n = 0 ;
//         for(char c : s)
//             n = n*2 + c-'0';
//         return n;
//     }
//     int bitwiseComplement(int n)
//     {
//         if(n == 0)
//         return 1;
//         string s = int_2_bin(n);
//         s = comlpe(s);
//         return bin_2_int(s);
//     }
// };


// class Solution {
// public:
//     int bitwiseComplement(int n) {
//         if(n == 0)return 1;
//         int res = 0;
//         int cnt = 0;
//         while(n){
//             int r = n % 2;
//             res += (pow(2,cnt)*!r);
//             cnt++;
//             n = (n>>1); // n/2;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int bitwiseComplement(int n) {
//         if(n == 0)return 1;
//         int mask = 1;
//         while(mask < n){
//             mask = (mask << 1) | 1; // << left shift 011 becomes 110 or 001 becomes 010 then or with 1 ie 010 | 001 = 011
//         }
//         return mask ^ n;
//     }
// };

class Solution {
public:
    int bitwiseComplement(int n) {
        // kisi bhi number n mei floor(logbase2(n)) + 1 number of binary digits hotei hai
        if(n == 0)return 1;
        int bits = floor(log2(n)) + 1;
        int mask = (1 << bits) - 1; // 2^bits - 1
        return mask ^ n; 
    }
};