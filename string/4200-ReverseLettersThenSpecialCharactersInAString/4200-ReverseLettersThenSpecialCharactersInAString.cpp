// Last updated: 19/08/2026, 15:17:37
class Solution {
public:
    string reverseByType(string s) {
        string a = "";
        string b = "";
        int n = s.size();
        for(int i=0; i<n; ++i){
            if(s[i] >='a' && s[i] <= 'z'){
                a += s[i];
            }else b+= s[i];
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int j = 0;
        int k = 0;
        string str = "";
        for(int i=0; i<n; ++i){
            if(s[i] >='a' && s[i] <= 'z'){
                str += a[j];
                j++;
            }else {
                str += b[k]; 
                k++;
            }
        }
        return str;
    }
};