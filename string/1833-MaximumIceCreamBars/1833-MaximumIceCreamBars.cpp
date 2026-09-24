// Last updated: 25/09/2026, 01:09:28
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int c = coins;
        int cnt = 0;
        sort(costs.begin(),costs.end());
        for(int i=0; i<n; ++i){
            if(costs[i] <= c){
                c -= costs[i];
                cnt++;
            }
        }
        return cnt;
    }
};