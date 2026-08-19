// Last updated: 19/08/2026, 15:36:16
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