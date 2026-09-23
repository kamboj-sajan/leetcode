// Last updated: 24/09/2026, 00:49:35
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int l = max(1,n-k);
        int r = n+k;
        int sum = 0;
        for(int i=l; i<=r; ++i){
            if(abs(n-i) <=k){
                if((n&i) == 0)sum += i;
            }
        }
        return sum;
    }
};