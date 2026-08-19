// Last updated: 19/08/2026, 15:50:43
class Solution {
public:
    bool f(vector<int> &vec, int m, long long k) {
        long long cnt = 0;
        for (int i : vec) {
            cnt += i / m;
            if (cnt >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        for (int x : candies) total += x;
        if (total < k) return 0;
        int l = 1;
        int r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (f(candies, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};