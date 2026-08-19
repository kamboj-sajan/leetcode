// Last updated: 19/08/2026, 15:38:25
class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxi = 0;
        for(char c : s){
            if(c == '('){
                cnt++;
                maxi = max(maxi,cnt);
            }else if(c == ')')cnt--;
        }
        return maxi;
    }
};