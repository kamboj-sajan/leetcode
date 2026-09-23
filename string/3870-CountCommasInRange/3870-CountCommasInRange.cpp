// Last updated: 24/09/2026, 00:50:55
class Solution {
public:
    int countCommas(int n) {
        if(n < 1000)return 0;
        return n - 999;
    }
};