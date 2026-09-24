// Last updated: 25/09/2026, 01:04:24
// // class Solution {
// // public:
// //     int bfs(int a, vector<vector<int>>& grid) {
// //         int n = grid.size();
// //         int m = grid[0].size();
// //         if (grid[0][0] >= a)return 0;
// //         vector<vector<int>> vis(n,vector<int> (m,0));
// //         queue<pair<int, int>> q;
// //         int pt = 1;
// //         q.push({0, 0});
// //         vis[0][0] = 1;
// //         int drc[] = {0, -1, 0, 1, 0};
// //         while (!q.empty()) {
// //             auto [r, c] = q.front();
// //             q.pop();
// //             for (int i = 0; i < 4; i++) {
// //                 int nr = r + drc[i];
// //                 int nc = c + drc[i + 1];
// //                 if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] < a && !vis[nr][nc]) {
// //                     pt++;
// //                     q.push({nr, nc});
// //                     vis[nr][nc] = 1;
// //                 }
// //             }
// //         }
// //         return pt;
// //     }

// // public:
// //     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
// //         int n = queries.size();
// //         vector<int> ans;
// //         for (int i = 0; i < n; i++) {
// //             int a = bfs(queries[i], grid);
// //             ans.push_back(a);
// //         }
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         int n = grid.size();
//         int m = grid[0].size();
//         priority_queue<
//         tuple<int,int,int>,
//         vector<tuple<int,int,int>>,
//         greater<tuple<int,int,int>>> pq;
//         vector<vector<int>> vis(n,vector<int> (m,0));
//         pq.push({grid[0][0],0,0});
//         vis[0][0] = 1;
//         int pt = 0;
//         vector<pair<int,int>> vec;
//         for(int i=0; i<queries.size(); i++){
//             vec.push_back({queries[i],i});
//         }
//         sort(vec.begin(),vec.end());
//         vector<int> ans(queries.size());
//         int drc[] = {0,-1,0,1,0};
//         for(auto [qr,in] : vec){
//             while(!pq.empty() && get<0> (pq.top()) < qr){
//                 auto [vl,r,c] = pq.top();
//                 pq.pop();
//                 pt++;
//                 for(int i=0; i<4; i++){
//                     int nr = r + drc[i];
//                     int nc = c + drc[i+1];
//                     if(nr >= 0 && nr < n && nc>= 0 && nc < m && !vis[nr][nc]){
//                         vis[nr][nc] = 1;
//                         pq.push({grid[nr][nc],nr,nc});
//                     }
//                 }
//             }
//             ans[in] = pt;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size(), k = queries.size();
        vector<pair<int, int>> hash(k);
        vector<int> ans(k, 0), ansSort(k, 0);

        for(int i=0; i<k; i++)
            hash[i] = {queries[i], i};
        sort(hash.begin(), hash.end());

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int r = 0;
        for(r=0; r<k; r++){
            if(grid[0][0] < hash[r].first){
                break;
            }
        }

        queue<pair<int, int>> q;
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > s;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        if(r < k){
            q.push({0, 0});
            vis[0][0] = 1;
            cnt = 1;
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    if(grid[nx][ny] < hash[r].first){
                        cnt++;
                        q.push({nx, ny});
                    }else{
                        s.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }

            if(q.empty()){
                while(true){
                    ansSort[r] = cnt;
                    r++;
                    if (r == k)
                        break;

                    while(!s.empty() && s.top().first < hash[r].first){
                        auto cur = s.top();
                        s.pop();

                        q.push({cur.second.first, cur.second.second});
                        cnt++;
                    }

                    if(!q.empty())
                        break;
                }

                if(r == k)
                    break;
            }
        }

        for(int i=0; i<k; i++)
            ans[hash[i].second] = ansSort[i];

        return ans;
    }
};