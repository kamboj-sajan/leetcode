// Last updated: 19/08/2026, 15:18:11
class Solution {
using ll = long long;
public:
     vector<int> bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vec1 = bfs(x,adj);
        vector<int> vec2 = bfs(y,adj);
        vector<int> vec3 = bfs(z,adj);
        int ans =0;
        for(int i = 0; i<n; ++i){
            ll c = vec1[i];
            ll d = vec2[i];
            ll e = vec3[i];
            vector<ll> vec4 = {c,d,e};
            sort(vec4.begin(),vec4.end());
            if(vec4[0]*vec4[0] + vec4[1]*vec4[1] == vec4[2]*vec4[2])ans++;
         }
        return ans;
    }
};