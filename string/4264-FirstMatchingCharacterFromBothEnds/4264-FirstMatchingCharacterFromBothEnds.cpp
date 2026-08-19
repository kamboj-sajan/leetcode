// Last updated: 19/08/2026, 15:16:32
class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        for(int i=0; i<n; ++i){
            if(s[i] == s[n-i-1])return i;
        }
        return -1;
    }
};