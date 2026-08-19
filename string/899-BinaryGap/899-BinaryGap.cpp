// Last updated: 19/08/2026, 15:55:51
class Solution {
public:
    int binaryGap(int n) {
         int last = -1;     // position of previous 1
    int pos = 0;       // current bit position
    int ans = 0;

    while (n > 0) {
        if (n & 1) {           // if current bit is 1
            if (last != -1)
                ans = max(ans, pos - last);
            last = pos;
        }
        pos++;
        n >>= 1;               // move to next bit
    }
    return ans;
    }
};