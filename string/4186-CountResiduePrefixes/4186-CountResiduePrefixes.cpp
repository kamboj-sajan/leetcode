// Last updated: 19/08/2026, 15:17:56
class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<char,int> mpp;
        int n = s.size();
        int cnt = 0;
        int ans = 0;
        for(int i=0; i<n; ++i){
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]]++;
                cnt++;
                if((i+1)%3 == cnt)ans++;
            }else{
                if((i+1)%3 == cnt)ans++;
            }
        }
        return ans;
    }
};