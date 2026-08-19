// Last updated: 19/08/2026, 16:11:43
class Solution {
public:
    double myPow(double x, int n) {
        // int m = n;
        // n = abs(n);
        // double ans = 1;
        // while(n > 0){
        //     if(n % 2 == 1){
        //         ans = ans * x;
        //         n = n - 1;
        //     }
        //     else{
        //         n = n / 2;
        //         x = x * x;
        //     }
        //     if(m < 0)ans = 1/ans;
        // }
        // return ans;
         long long N = n;  
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1;
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x;
            }
            x *= x;
            N /= 2;
        }
        
        return ans;
    }
};