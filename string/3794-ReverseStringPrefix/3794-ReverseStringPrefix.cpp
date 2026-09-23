// Last updated: 24/09/2026, 00:52:04
class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();
        for(int i=0;i<k/2; ++i){
            swap(s[i],s[k-1-i]);
        }
        return s;
    }
};