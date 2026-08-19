// Last updated: 19/08/2026, 15:19:29
class Solution {
public:
    vector<vector<int>> pre;
    int n , m,l;
    bool f(int a){
        l =a;
        if(l > n || l > m){
            return false;
        }
        int tr = n-l +1;
        int tc = m-l+1;
        vector<vector<int>> vec(tr+1,vector<int> (tc+1,0));
        for(int i=0; i<tr; i++){
            for(int j=0; j<tc; j++){
                int sm = pre[i+l][j+l] - pre[i][j+l] - pre[i+l][j] + pre[i][j];
                if(sm == l*l)vec[i+1][j+1] = 1;          
            }
        }
        for(int i=1; i<=tr; i++){
            for(int j=1; j<=tc; j++){
                vec[i][j] += vec[i-1][j] + vec[i][j-1] - vec[i-1][j-1];
            }
        }
        for(int i=0; i<tr; i++){
            for(int j=0; j<tc; j++){
                int b = vec[i+1][j+1] - vec[i][j+1] - vec[i+1][j] + vec[i][j];
                if(!b)continue;
                if(ch(0,0,i-l,tc-1,vec))return true;
                if(ch(i+l,0,tr-1,tc-1,vec))return true;
                if(ch(0,0,tr-1,j-l,vec))return true;
                if(ch(0,j+l,tr-1,tc-1,vec))return true;
            }
        }
        return false;
    }
    int ch(int r,int c,int nr,int nc,vector<vector<int>> &vec){
        if(r > nr || c > nc)return 0;
        r = max(r,0);
        c = max(c,0);
        nr = min(nr,(int)vec.size()-2);
        nc = min(nc,(int)vec[0].size()-2);
        if(r > nr || c > nc)return 0;
        return vec[nr+1][nc+1] - vec[r][nc+1] - vec[nr+1][c] + vec[r][c];
    }
public:
    int maxArea(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        pre.assign(n+1,vector<int> (m+1,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i + 1][j + 1] =
                    mat[i][j] + pre[i][j+ 1] +
                    pre[i + 1][j] - pre[i][j];
            }
        }
        int ans = 0;
        int l = 1;
        int h = min(n,m);
        while(l <= h){
            int mid = l + (h-l)/2;
            if(f(mid)){
                ans = mid;
                l = mid+1;
            }else{
                h = mid -1;
            }
        }
        return ans*ans;
    }
};