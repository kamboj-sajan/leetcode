// Last updated: 25/09/2026, 01:01:24
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