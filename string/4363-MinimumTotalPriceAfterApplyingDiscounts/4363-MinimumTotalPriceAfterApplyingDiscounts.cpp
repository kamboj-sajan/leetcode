// Last updated: 19/08/2026, 15:14:47
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        double ans = 0;
        int n , m;
        bool a = true;
        n = prices.size();
        m = discounts.size();
        if(n < m)a = false;
        else a = true;
        if(a){
            for(int i=0; i<m; i++){
                double b = (1.0*prices[i] * (100 - discounts[i]))/100.0;
                ans += b;
            }
            for(int i=m; i<n; i++){
                ans += prices[i];
            }
        }else{
            for(int i=0; i<n; i++){
                double b = (1.0*prices[i] * (100 - discounts[i]))/100.0;
                ans += b;
            }
        }
        return ans;
    }
};