// Last updated: 19/08/2026, 15:48:09
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

    while (s != "1") {

        // Even number
        if (s.back() == '0') {
            s.pop_back();   // divide by 2
        }
        // Odd number
        else {
            int i = s.size() - 1;

            // handle carry
            while (i >= 0 && s[i] == '1') {
                s[i] = '0';
                i--;
            }

            if (i >= 0)
                s[i] = '1';
            else
                s = '1' + s;   // overflow case
        }

        steps++;
    }

    return steps;
    }
};