// Last updated: 19/08/2026, 15:17:09
class Solution {
public:
    int countCommas(int n) {
        if(n < 1000)return 0;
        return n - 999;
    }
};