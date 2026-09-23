// Last updated: 24/09/2026, 00:50:11
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> fr;
        int en = cbrt(n);
        using ll = long long;
        for(int i=1; i<=en; ++i){
            ll a = 1LL*i*i*i;
            for(int j=i; j<=en; ++j){
                ll sm = a + 1LL*j*j*j;
                if(sm > n)break;
                fr[sm]++;
            }
        }
        vector<int> ans;
        for(auto &p : fr){
            if(p.second >= 2){
                ans.push_back(p.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};