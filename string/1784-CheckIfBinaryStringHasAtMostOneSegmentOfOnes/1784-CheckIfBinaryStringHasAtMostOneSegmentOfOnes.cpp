// Last updated: 25/09/2026, 01:09:42
class Solution {
public:
    bool checkOnesSegment(string s) {
       int n = s.size();
       int a = 0;
       for(int i=0; i<n; ++i){
        if(s[i] == '0'){
            a = i;
            break;
        }
       }
       if(a == 0)return true;
       for(int i=a; i<n; ++i){
        if(s[i] == '1')return false;
       }
       return true;
    }
};