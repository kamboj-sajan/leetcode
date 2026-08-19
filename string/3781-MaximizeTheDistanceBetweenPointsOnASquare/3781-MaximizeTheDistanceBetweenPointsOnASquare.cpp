// Last updated: 19/08/2026, 15:25:25
// class Solution {
// public:
//     using ll = long long;

//     // map boundary point to perimeter position
//     ll getPos(int side, int x, int y) {
//         if (y == 0) return x;                       // bottom
//         if (x == side) return (ll)side + y;        // right
//         if (y == side) return (ll)3 * side - x;    // top
//         return (ll)4 * side - y;                   // left
//     }

//     bool can(vector<ll>& pos, int k, ll d, int side) {
//         int n = pos.size();
//         ll perimeter = 4LL * side;

//         // duplicate array for circular handling
//         vector<ll> ext = pos;
//         for (auto x : pos) ext.push_back(x + perimeter);

//         // try every point as starting point
//         for (int start = 0; start < n; start++) {
//             int cnt = 1;
//             ll last = ext[start];

//             for (int i = start + 1; i < start + n && cnt < k; i++) {
//                 if (ext[i] - last >= d) {
//                     cnt++;
//                     last = ext[i];
//                 }
//             }

//             // ensure circular distance between last and first
//             if (cnt == k) {
//                 ll circularGap = perimeter - (last - ext[start]);
//                 if (circularGap >= d) return true;
//             }
//         }
//         return false;
//     }

//     int maxDistance(int side, vector<vector<int>>& points, int k) {
//         vector<ll> pos;

//         for (auto &p : points) {
//             pos.push_back(getPos(side, p[0], p[1]));
//         }

//         sort(pos.begin(), pos.end());

//         ll lo = 0, hi = 2LL * side; // max possible Manhattan distance
//         ll ans = 0;

//         while (lo <= hi) {
//             ll mid = (lo + hi) / 2;

//             if (can(pos, k, mid, side)) {
//                 ans = mid;
//                 lo = mid + 1;
//             } else {
//                 hi = mid - 1;
//             }
//         }

//         return (int)ans;
//     }
// };


class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> res;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) res.push_back(y);
            else if (y == side) 
                res.push_back((long long)side + x);
            else if (x == side) 
                res.push_back((long long)side * 3 - y);
            else res.push_back((long long)side * 4 - x);
        }
        sort(res.begin(), res.end());

        auto check = [&](int n) {
            int m = res.size();
            vector<int> idx(k);
            long long curr = res[0];
            idx[0] = 0;
            for (int i = 1; i < k; i++) {
                auto it = lower_bound(res.begin(), res.end(), curr + n);
                if (it == res.end()) 
                    return false;
                idx[i] = distance(res.begin(), it);
                curr = *it;
            }
            if (res[idx[k - 1]] - res[0] <= (long long)side * 4 - n) 
                return true;

            for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {
                for (int j = 1; j < k; j++) {
                    while (idx[j] < m && res[idx[j]] < res[idx[j - 1]] + n) {
                        idx[j]++;
                    }
                    if (idx[j] == m) 
                        return false;
                }
                if (res[idx[k - 1]] - res[idx[0]] <= (long long)side * 4 - n) 
                    return true;
            }
            return false;
        };

        int left = 1;
        int right = (1LL * side * 4) / k + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) 
                left = mid;
            else right = mid;
        }
        return left;
    }
};
