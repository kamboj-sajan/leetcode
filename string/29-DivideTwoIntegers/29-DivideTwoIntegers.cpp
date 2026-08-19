// Last updated: 19/08/2026, 16:12:49
class Solution {
public:
      int divide(int dividend, int divisor) {
    //     if(dividend == divisor)return 1;
    //     bool sign = true;
    //     if(dividend >= 0 && divisor < 0)sign = false;
    //     else if(dividend <= 0 && divisor > 0)sign = false;
    //     long n = abs(dividend);
    //     long d = abs(divisor);
    //     divisor = abs(divisor);
    //     long ans = 0;
    //     while(n >= d){
    //         int cnt = 0;
    //         while(n >= (d << (cnt+1))){
    //             cnt++;
    //         }
    //         ans += 1<<cnt;
    //         n = n - (d*(1<<cnt));
    //     }
    //     if(ans == (1<<31) && sign){
    //         return INT_MAX;
    //     }
    //     if(ans == (1<<31) && !sign){
    //         return INT_MIN;
    //     }
    //     return sign ? ans : -ans;
    if(dividend == divisor) return 1;
        
        // Handle overflow cases explicitly
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        bool sign = (dividend < 0) == (divisor < 0);  // True if both are the same sign
        
        // Convert both dividend and divisor to long long to prevent overflow
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        
        while (n >= d) {
            long long temp = d, cnt = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                cnt <<= 1;
            }
            n -= temp;
            ans += cnt;
        }
        
        ans = sign ? ans : -ans;
        
        // Clamp the result within the 32-bit integer range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        
        return ans;
    }
};