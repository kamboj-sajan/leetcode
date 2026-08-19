// Last updated: 19/08/2026, 15:28:17
class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i=0; i<s.size()-1; ++i){
            sum += abs(s[i] - s[i+1]);
        }
        return sum;
    }
};