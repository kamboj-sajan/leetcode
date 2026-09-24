// Last updated: 25/09/2026, 01:14:53
class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0, count = 0;
        for(char c : s) {
            if(c == 'L') balance++;
            else balance--;
            if(balance == 0) count++;
        }
        return count;
    }
};