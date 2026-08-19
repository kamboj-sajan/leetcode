// Last updated: 19/08/2026, 16:04:22
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n == 0)return false;
//         if(n == 1)return true;
//         while(n%2 == 0)n /= 2;
//         return (n == 1);
//     }
// };

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==1)return true;
        if (n==0)return false;
        if (n%2==0)return isPowerOfTwo(n/2);
        return false;
    }
};