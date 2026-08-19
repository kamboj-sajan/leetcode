// Last updated: 19/08/2026, 15:26:24
// class Solution {
// public:
//     bool f(int i){
//         while(i > 0){
//             if(i % 2 == 0)return false;
//             i /= 2;
//         }
//         return true;
//     }
//     int smallestNumber(int n) {
//         for(int i=n; i<=INT_MAX; ++i){
//             if(f(i)) return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int smallestNumber(int n) {
        while(1)
        {
            int a=n;
            while(a!=0)
            {
                int rem=a%2;
                if(rem==0) break;
                a/=2;
            }
            if(a==0) return n;
            n++;
        }
    }
};