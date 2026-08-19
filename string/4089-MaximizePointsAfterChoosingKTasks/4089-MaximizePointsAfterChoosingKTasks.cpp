// Last updated: 19/08/2026, 15:20:13
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        long long ans = 0;
        for(int i=0; i<n; ++i){
            ans += technique2[i];
        }
        vector<long long> dif(n);
        for(int i=0; i<n; ++i){
            dif[i] = (long long)technique1[i] - technique2[i];
        }
        sort(dif.begin(),dif.end(),greater<long long>());
        for(int i=0; i<k; ++i){
            ans += dif[i];
        }
        for(int i=k; i<n; ++i){
            if(dif[i] > 0)ans += dif[i];
            else break;
        }
        return ans;
    }
};