// Last updated: 19/08/2026, 15:20:09
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.size();
        int cnta = 0;
        int cntb = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == 'a')cnta++;
            else cntb++;
        }
        int c = min(cnta,cntb);
        return (n-2*c);
    }
};