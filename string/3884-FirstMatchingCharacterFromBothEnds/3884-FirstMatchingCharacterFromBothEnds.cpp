// Last updated: 24/09/2026, 00:50:30
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