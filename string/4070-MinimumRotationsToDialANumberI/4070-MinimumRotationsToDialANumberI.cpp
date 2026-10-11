// Last updated: 11/10/2026, 07:58:52
class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int ans = 0;
        ans += min(10-(s[0]-'0'),s[0]-'0');
        for(int i=1; i<n; i++){
            int a = s[i-1] - '0';
            int b = s[i] - '0';
            bool c = true;
            if(a < b){
                c = true;
            }else c = false;
            if(c == true){
                int d = b - a;
                int e = (10+a) - b;
                ans += min(d,e);
            }else{
                int f = a - b;
                int g = (10+b) - a;
                ans += min(f,g);
            }
        }
        return ans;
    }
};