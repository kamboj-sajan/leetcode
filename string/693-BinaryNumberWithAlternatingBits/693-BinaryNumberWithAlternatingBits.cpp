// Last updated: 19/08/2026, 15:58:23
class Solution {
public:
    bool hasAlternatingBits(int n) {
         unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};