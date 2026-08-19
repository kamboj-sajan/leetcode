// Last updated: 19/08/2026, 15:29:33
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int mnfr = max(0,n-2*limit);
        int mxfr = min(n,limit);
        int ans = 0;
        for(int i=mnfr; i<=mxfr; ++i){
            int N = n-i;
            int mnch2 = max(0,N - limit);
            int mxch2 = min(N,limit);
            ans += mxch2 - mnch2 + 1;
        }
        return ans;
    }
};