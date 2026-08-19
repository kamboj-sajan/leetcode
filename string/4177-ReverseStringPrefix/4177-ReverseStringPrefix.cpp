// Last updated: 19/08/2026, 15:18:15
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