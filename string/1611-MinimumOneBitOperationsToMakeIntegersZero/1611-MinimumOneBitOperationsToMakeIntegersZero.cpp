// Last updated: 25/09/2026, 01:11:23
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};