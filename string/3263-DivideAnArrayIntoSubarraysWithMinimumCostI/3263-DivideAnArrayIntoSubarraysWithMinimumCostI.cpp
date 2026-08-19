// Last updated: 19/08/2026, 15:28:49
// class Solution {
// public:
//     int minimumCost(vector<int>& nums) {
//         priority_queue<int,vector<int>,greater<int>> pq;
//         for(int i=1; i<nums.size(); ++i){
//             pq.push(nums[i]);
//         }
//         int ans = 0;
//         ans += nums[0];
//         ans += pq.top();
//         pq.pop();
//         ans+= pq.top();
//         return ans;
//     }
// };

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (int i = 1;i < nums.size();++i) {
            int x = nums[i];
            if (x < m1) {
                m2 = m1;
                m1 = x;
            }
            else if (x < m2) {
                m2 = x;
            }
        }
        return nums[0] + m1 + m2;
    }
};