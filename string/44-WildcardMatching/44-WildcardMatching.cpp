// Last updated: 19/08/2026, 16:12:05
class Solution {
public:
    bool isMatch(string s, string p) {
       int m = s.size();
       int n = p.size();
       vector<bool> prev(m+1,false),cur(m+1,false);
       prev[0] = true;
       for(int j=1; j<=m; j++)prev[j] = false;
       for(int i=1; i<=n; i++){
        //cur is the current row or column
        //and that cur's 0th row has to be assigned everytime
        bool flag = true;

        for(int ii=1; ii<=i; ii++){
                if(p[ii-1] != '*'){
                    flag = false;
                    break;
                }
            }
        // for every row 
        // you are assigning the 0th column's value
        cur[0] = flag;
        for(int j=1; j<=m; j++){
            if(p[i-1] == s[j-1] || p[i-1] == '?'){
                cur[j] = prev[j-1];
            }
            else if(p[i-1] == '*'){
                cur[j] = prev[j] || cur[j-1];
            }else{
                cur[j] = false;
            }
        }
        prev = cur;
       } 
       return prev[m];
    }
};