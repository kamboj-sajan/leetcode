// Last updated: 19/08/2026, 15:47:27
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxi1 = INT_MIN, maxi2 = INT_MIN;
//         for(int x : nums) {
//             if(x > maxi1) {
//                 maxi2 = maxi1;  // shift old max to second max
//                 maxi1 = x;
//             } else if(x > maxi2) {
//                 maxi2 = x;
//             }
//         }
//         return (maxi1 - 1) * (maxi2 - 1);
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        int res=0;
        for(auto x: nums){
            pq.push(x);
        }
        while(!pq.empty()){
            int f=pq.top();
            
            pq.pop();
            int s=pq.top();
            
            pq.pop();
           

            res=(f-1)*(s-1);
            break;
            
        }
        return res;
        
    }
};