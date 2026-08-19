// Last updated: 19/08/2026, 15:55:38
// class StockSpanner {
// public:
// vector<int> v;
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         v.push_back(price);
//         int cnt = 0;
//         for(int i=v.size()-1; i>=0; i--){
//             if(v[i] <= price){
//                 cnt++;
//             }else{
//                 break;
//             }
//         }
//         return cnt;
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 class StockSpanner {
public:
stack<pair<int,int>> st;
int ind = -1;
    StockSpanner() {
        ind = -1;
        while (!st.empty()) st.pop();
    }
    
    int next(int price) {
      ind = ind + 1;
      while(!st.empty() && st.top().first <= price)st.pop();
      int ans = ind - (st.empty() ? -1 : st.top().second);
      st.push({price,ind});
      return ans;
    }
};
