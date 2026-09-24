// Last updated: 25/09/2026, 00:56:41
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