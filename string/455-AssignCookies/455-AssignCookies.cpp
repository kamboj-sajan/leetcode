// Last updated: 19/08/2026, 16:01:18
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int n = min(g.size(),s.size());
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             if(s[i] >= g[i])cnt++;
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//        int n = g.size();
//        int m = s.size();
//        sort(g.begin(),g.end());
//        sort(s.begin(),s.end());
//        int l = 0, r = 0;
//        while(l<n && r<m){
//         if(s[r] >= g[l]){
//             l++;
//         }
//         r++;
//        }
//        return l;
//     }
// };

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int n = g.size();
       int m = s.size();
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int l = 0, r = 0;
       int cnt = 0;
       while(l<n && r<m){
        if(s[r] >= g[l]){
            l++;
            r++;
            cnt++;
        }else{
        r++;
        }
       }
       return cnt;
    }
};