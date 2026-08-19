// Last updated: 19/08/2026, 15:34:42
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while (!pq.empty()) {

            auto [d,node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [adjNode,w] : adj[node]) {

                if (d + w < dist[adjNode]) {
                    dist[adjNode] = d + w;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if (d + w == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};