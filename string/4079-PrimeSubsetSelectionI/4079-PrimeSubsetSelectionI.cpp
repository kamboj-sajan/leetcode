// Last updated: 13/10/2026, 10:47:17
class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> b(n+1,true);
        vector<int> pr;
        vector<int> ans;
        if(n <2)return ans;
        b[0] = b[1] = false;
        for(int i=2; i*i <= n; i++){
            if(b[i]){
                for(int j=i*i; j<=n; j+=i){
                    b[j] = false;
                }
            }
        }
        for(int i=2; i<=n; i++){
            if(b[i]){
                pr.push_back(i);
            }
        }
        int sum = 0;
        for(int i=0; i<pr.size(); i++){
            if(sum + pr[i] <= s){
                sum += pr[i];
                ans.push_back(pr[i]);
            }
            else break;
        }
        return ans;
    }
};