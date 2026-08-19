// Last updated: 19/08/2026, 15:50:30
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