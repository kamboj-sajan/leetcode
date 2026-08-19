// Last updated: 19/08/2026, 15:23:09
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int cnt = 0;
        int maxi = weight[0];
        int start = 0;
        for(int i=1; i<n; i++){
            maxi = max(maxi,weight[i]);
            if(weight[i] < maxi){
                cnt++;
                if(i+1<n){
                    start = i+1;
                    maxi = weight[start];
                    i = start;
                }
            }
        }
        return cnt;
    }
};