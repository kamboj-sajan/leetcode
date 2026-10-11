// Last updated: 11/10/2026, 07:58:50
class Solution {
public:
    int f(int a,int b){
        int d = abs(a-b);
        int ans = min(d,10-d);
        return ans;
    }
public:
    int minRotations(int n, string s) {
        vector<int> vec(n,0);
        vec[0] = f(0,s[0]-'0');
        for(int i=1; i<n; i++){
            int a = s[i-1] - '0';
            int b = s[i] - '0';
            vec[i] = vec[i-1] + f(a,b);
        }
        int ans = vec[n-1];
        for(int i=0; i<n; i++){
            int d;
            if(i == 0)d =0;
            else d = vec[i-1];
            int l;
            if(i == 0)l =0;
            else l = s[i-1]-'0';
            int e = f(l,s[n-1]-'0');
            int g = vec[n-1] - vec[i];
            ans = min(ans,d+e+g);
        }
        return ans;
    }
};