// Last updated: 19/08/2026, 15:19:06
class Solution {
public:
    bool es(string &a){
        bool b = true;
        for(int i=1;i<a.size(); ++i){
            if(a[i-1] != a[i]){
                b = false;
                break;
            }
        }
        if(b == true)return true;
        else return false;
    }
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        if(es(s))return 0;
        long long cnt = 0;
        vector<long long>vec(26,0);
        for(int i=0; i<n; ++i){
            cnt += cost[i];
            vec[s[i] - 'a'] += cost[i];
        }
        long long maxi = 0;
        for(int i=0; i<26; ++i){
            maxi= max(maxi,vec[i]);
        }
        return cnt - maxi;
    }
};