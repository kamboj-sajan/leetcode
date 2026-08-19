// Last updated: 19/08/2026, 16:05:43
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
    while (n) {
        n &= (n - 1); 
        count++;
    }
    return count;
    }
};