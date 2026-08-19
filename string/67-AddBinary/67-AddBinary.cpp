// Last updated: 19/08/2026, 16:10:46
// class Solution {
// public:
//     string addBinary(string a, string b) {
//         long long a1 = 0, b1 = 0;
//         int p = 0;

       
//         for (int i = a.size() - 1; i >= 0; i--) {
//             a1 += (long long)(a[i] - '0') * (1LL << p);
//             p++;
//         }

        
//         p = 0;
//         for (int i = b.size() - 1; i >= 0; i--) {
//             b1 += (long long)(b[i] - '0') * (1LL << p);
//             p++;
//         }

//         long long c1 = a1 + b1;
//         if (c1 == 0) return "0";

//         string bin = "";
//         while (c1 > 0) {
//             bin = char((c1 % 2) + '0') + bin;
//             c1 /= 2;
//         }
//         return bin;
//     }
// }; 194/296 runtime error


class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int cr = 0;
        while(i>=0 || j>=0 || cr){
            int sum = cr;
            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }
            res = char(sum%2 + '0') + res;
            cr = sum/2;
        }
        return res;
    }
};



