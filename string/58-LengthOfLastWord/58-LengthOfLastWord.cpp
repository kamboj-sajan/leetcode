// Last updated: 19/08/2026, 16:11:09
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
    int length = 0;
    int i = n - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count length of last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
    }
};