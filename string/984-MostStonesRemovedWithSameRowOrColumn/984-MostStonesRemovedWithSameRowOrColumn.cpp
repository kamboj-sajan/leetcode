// Last updated: 19/08/2026, 15:55:01
// class DisjointSet {
// public:
//     vector<int> parent, size;

//     DisjointSet(int n) {
//         parent.resize(n+1);
//         size.resize(n+1, 1);

//         for (int i = 0; i <= n; i++)
//             parent[i] = i;
//     }
//     int findUPar(int node) {
//         if (parent[node] == node)
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }
//     void UnionBySize(int u, int v) {
//         int pu = findUPar(u);
//         int pv = findUPar(v);

//         if (pu == pv) return;

//         if (size[pu] < size[pv]) {
//             parent[pu] = pv;
//             size[pv] += size[pu];
//         } else {
//             parent[pv] = pu;
//             size[pu] += size[pv];
//         }
//     }
// };


// class Solution {
// public:
//     int removeStones(vector<vector<int>>& stones) {
//        int mr = 0;
//        int mc = 0;
//        for(auto it : stones){
//         mr = max(mr,it[0]);
//         mc = max(mc,it[1]);
//        }
//        DisjointSet ds(mr + mc + 1);
//        unordered_map<int,int> stoneNodes;
//        for(auto it : stones){
//         int noderow = it[0];
//         int nodecol = it[1] + mr + 1;
//         ds.UnionBySize(noderow,nodecol);
//         stoneNodes[noderow] = 1;
//         stoneNodes[nodecol] = 1;
//        }
//        int cnt = 0;
//        for(auto it : stoneNodes){
//         if(ds.findUPar(it.first) == it.first){
//             cnt++;
//         }
//        }
//        return stones.size() - cnt;
//     }
// };

// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& stones, vector<int>& vis) {
//         vis[node] = 1;

//         for (int i = 0; i < stones.size(); i++) {
//             if (!vis[i] &&
//                 (stones[node][0] == stones[i][0] ||
//                  stones[node][1] == stones[i][1])) {
//                 dfs(i, stones, vis);
//             }
//         }
//     }

//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         vector<int> vis(n, 0);

//         int components = 0;

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 components++;
//                 dfs(i, stones, vis);
//             }
//         }

//         return n - components;
//     }
// };

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int> vis(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            components++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int j = 0; j < n; j++) {
                    if (!vis[j] &&
                        (stones[node][0] == stones[j][0] ||
                         stones[node][1] == stones[j][1])) {
                        vis[j] = 1;
                        q.push(j);
                    }
                }
            }
        }

        return n - components;
    }
};