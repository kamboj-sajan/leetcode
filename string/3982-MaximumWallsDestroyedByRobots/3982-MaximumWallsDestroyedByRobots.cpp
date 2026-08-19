// Last updated: 19/08/2026, 15:22:23
// class Solution {
// public:
//     int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
//         int n = robots.size();
//         sort(robots.begin(),robots.end());
//         sort(walls.begin(),walls.end());
//         unordered_set<int> st;
//         for(int i=0; i<n; ++i){
//             int r = robots[i];
//             int d = distance[i];
//             int lb = -1e9;
//             if(i > 0)lb = robots[i-1];
//             int rb = 1e9;
//             if(i < n-1)rb = robots[i+1];
//             int lft = max(r -d, lb+1);
//             int rft = r;
//             int lc = 0;
//             vector<int> lw;
//             for(int w : walls){
//                 if(w >= lft && w <= rft){
//                     lc++;
//                     lw.push_back(w);
//                 }
//             }
//             int rstart = 0;
//             int rend = min(r+d,rb - 1);
//             int rc = 0;
//             vector<int> rw;
//             for(int w : walls){
//                 if(w >= rstart && w <= rend){
//                     rc++;
//                     rw.push_back(w);
//                 }
//             }
//             if(rc >= lc){
//                 for(int w : rw)st.insert(w);
//             }else{
//                 for(int w : lw)st.insert(w);
//             }
//         }
//         return st.size();
//     }
// };

// class Solution {
// public:
//     int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
//         int n = robots.size();
//         // Pair robot with distance
//         vector<pair<int,int>> r;
//         for(int i = 0; i < n; i++) {
//             r.push_back({robots[i], distance[i]});
//         }
//         sort(r.begin(), r.end());
//         sort(walls.begin(), walls.end());
//         // Precompute left/right wall counts
//         vector<int> leftCnt(n), rightCnt(n);
//         for(int i = 0; i < n; i++) {
//             int pos = r[i].first;
//             int d = r[i].second;
//             int lb = (i > 0 ? r[i-1].first : -1e9);
//             int rb = (i < n-1 ? r[i+1].first : 1e9);
//             // LEFT
//             int L = max(pos - d, lb + 1);
//             int R = pos;
//             leftCnt[i] = upper_bound(walls.begin(), walls.end(), R) - 
//                          lower_bound(walls.begin(), walls.end(), L);
//             // RIGHT
//             L = pos;
//             R = min(pos + d, rb - 1);
//             rightCnt[i] = upper_bound(walls.begin(), walls.end(), R) - 
//                           lower_bound(walls.begin(), walls.end(), L);
//         }
//         // DP
//         vector<vector<int>> dp(n, vector<int>(2, 0));
//         dp[0][0] = leftCnt[0];
//         dp[0][1] = rightCnt[0];
//         for(int i = 1; i < n; i++) {
//             // If current goes LEFT
//             dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + leftCnt[i];
//             // If current goes RIGHT
//             // Avoid double counting overlap between i-1 and i
//             int overlap = 0;
//             int L = r[i-1].first;
//             int R = r[i].first;
//             overlap = upper_bound(walls.begin(), walls.end(), R) -
//                       lower_bound(walls.begin(), walls.end(), L);
//             dp[i][1] = max(
//                 dp[i-1][0] + rightCnt[i],                 // prev LEFT → no overlap
//                 dp[i-1][1] + rightCnt[i] - overlap        // prev RIGHT → subtract overlap
//             );
//         }
//         return max(dp[n-1][0], dp[n-1][1]);
//     }
// };

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        int pos1, pos2, pos3, leftPos, rightPos;
        vector<int> left(n, 0), right(n, 0), num(n, 0);
        unordered_map<int, int> robotsToDistance;
        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }
        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());
        for (int i = 0; i < n; i++) {
            pos1 = upper_bound(walls.begin(), walls.end(), robots[i]) -
                   walls.begin();
            if (i >= 1) {
                leftPos =
                    lower_bound(walls.begin(), walls.end(),
                                max(robots[i] - robotsToDistance[robots[i]],
                                    robots[i - 1] + 1)) -
                    walls.begin();
            } else {
                leftPos = lower_bound(walls.begin(), walls.end(),
                                      robots[i] - robotsToDistance[robots[i]]) -
                          walls.begin();
            }
            left[i] = pos1 - leftPos;
            if (i < n - 1) {
                rightPos =
                    upper_bound(walls.begin(), walls.end(),
                                min(robots[i] + robotsToDistance[robots[i]],
                                    robots[i + 1] - 1)) -
                    walls.begin();
            } else {
                rightPos =
                    upper_bound(walls.begin(), walls.end(),
                                robots[i] + robotsToDistance[robots[i]]) -
                    walls.begin();
            }
            pos2 = lower_bound(walls.begin(), walls.end(), robots[i]) -
                   walls.begin();
            right[i] = rightPos - pos2;
            if (i == 0) {
                continue;
            }
            pos3 = lower_bound(walls.begin(), walls.end(), robots[i - 1]) -
                   walls.begin();
            num[i] = pos1 - pos3;
        }
        int subLeft, subRight, currentLeft, currentRight;
        subLeft = left[0];
        subRight = right[0];
        for (int i = 1; i < n; i++) {
            currentLeft =
                max(subLeft + left[i], subRight - right[i - 1] +
                                           min(left[i] + right[i - 1], num[i]));
            currentRight = max(subLeft + right[i], subRight + right[i]);
            subLeft = currentLeft;
            subRight = currentRight;
        }
        return max(subLeft, subRight);
    }
};