// Last updated: 19/08/2026, 15:30:22
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        if(prices[0] + prices[1] > money)return money;
        else return (money - (prices[0] + prices[1]));
    }
};