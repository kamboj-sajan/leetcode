// Last updated: 19/08/2026, 15:19:27
class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        using ll = long long;
        int n = nums.size();
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + nums[i];
    }
    const ll mini = -1e18;
    vector<ll> pdp(n + 1, 0);
    ll maxi = mini;
    for (int j = 1; j <= m; ++j) {
        vector<ll> cur(n + 1, mini);
        deque<int> dq;
        for (int i = 1; i <= n; ++i) {
            int a = i - l;
            if (a >= 0) {
                ll val = pdp[a] - pre[a];
                while (!dq.empty() &&
                       (pdp[dq.back()] - pre[dq.back()]) <= val) {
                    dq.pop_back();
                }
                dq.push_back(a);
            }
            while (!dq.empty() && dq.front() < i - r) {
                dq.pop_front();
            }
            cur[i] = cur[i - 1];
            if (!dq.empty()) {
                int best = dq.front();
                ll take = pre[i] + pdp[best] - pre[best];
                cur[i] = max(cur[i], take);
            }
        }
        maxi = max(maxi, cur[n]);
        pdp = cur;
    }
    return maxi;
    }
};