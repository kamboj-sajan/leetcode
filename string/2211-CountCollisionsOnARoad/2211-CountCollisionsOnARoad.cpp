// Last updated: 25/09/2026, 01:06:06
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int total_moving = 0;
        for (char c : directions)
            if (c == 'L' || c == 'R') total_moving++;
        int leading_L = 0, i = 0;
        while (i < n && directions[i] == 'L') {
            leading_L++;
            i++;
        }
        int trailing_R = 0, j = n - 1;
        while (j >= 0 && directions[j] == 'R') {
            trailing_R++;
            j--;
        }
        return total_moving - (leading_L + trailing_R);
    }
};
