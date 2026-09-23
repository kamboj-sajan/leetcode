// Last updated: 24/09/2026, 00:48:56
class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        int ans = 0;
        for(char c : s){
            if(c == '0'){
                cnt0++;
                if(abs(cnt0-cnt1) == 1)ans++;
                else if(cnt0 == cnt1)ans++;
            }else{
                cnt1++;
                if(abs(cnt0-cnt1) == 1)ans++;
                else if(cnt0 == cnt1)ans++;
            }
        }
        return ans;
    }
};