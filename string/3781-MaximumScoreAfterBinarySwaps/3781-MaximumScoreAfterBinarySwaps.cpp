// Last updated: 25/09/2026, 00:52:58
using ll = long long;

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        ll cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') cnt++;
            pq.push(nums[i]);
            if ((ll)pq.size() > cnt) pq.pop();
        }
        ll ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
