// Last updated: 19/08/2026, 15:22:25

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<pair<int,int>> vals;
        vals.reserve(n);
        for (int i = 0; i < n; ++i) vals.emplace_back(nums[i], i);
        sort(vals.begin(), vals.end());

        int sz = 1;
        while (sz < n) sz <<= 1;
        vector<int> seg(2 * sz, -1);

        auto seg_update = [&](int pos, int val) {
            pos += sz;
            seg[pos] = val;
            pos >>= 1;
            while (pos) {
                seg[pos] = max(seg[pos<<1], seg[pos<<1|1]);
                pos >>= 1;
            }
        };

        auto seg_query = [&](int l, int r) {
            if (l > r) return -1;
            l += sz; r += sz;
            int res = -1;
            while (l <= r) {
                if (l & 1) res = max(res, seg[l++]);
                if (!(r & 1)) res = max(res, seg[r--]);
                l >>= 1; r >>= 1;
            }
            return res;
        };

        vector<int> R(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && vals[j].first == vals[i].first) ++j;
            for (int k = i; k < j; ++k) {
                int idx = vals[k].second;
                int q = seg_query(idx + 1, n - 1);
                R[idx] = (q == -1 ? idx : q);
            }
            for (int k = i; k < j; ++k) seg_update(vals[k].second, vals[k].second);
            i = j;
        }

        vector<int> ans(n);
        int pos = 0;
        while (pos < n) {
            int curR = R[pos];
            int curMax = nums[pos];
            int j = pos;
            while (j <= curR) {
                curR = max(curR, R[j]);
                curMax = max(curMax, nums[j]);
                ++j;
            }
            for (int t = pos; t < j; ++t) ans[t] = curMax;
            pos = j;
        }
        return ans;
    }
};
