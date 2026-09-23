// Last updated: 24/09/2026, 00:51:52
class Solution {
public:
    using ll = long long;
    long long countPairs(vector<string>& words) {
        unordered_map<string,ll> mpp;
        for(auto &a : words){
            string b;
            int dif = a[0] - 'a';
            for(char &c : a){
                char d = (c - 'a' - dif + 26)%26 + 'a';
                b.push_back(d);
            }
            mpp[b]++;
        }
        ll ans = 0;
        for(auto &f : mpp){
            ll m = f.second;
            ans += m * (m-1)/2;
        }
        return ans;
    }
};