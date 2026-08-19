// Last updated: 19/08/2026, 15:57:46
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int,int>>> adj(n+1);
//         vector<int> time(n+1,1e9);
//         for(auto &it : times){
//             int u = it[0];
//             int v = it[1];
//             int w = it[2];
//             adj[u].push_back({v,w});
//         }
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         pq.push({0,k});
//         time[k] = 0;
//         while(!pq.empty()){
//             auto it = pq.top();
//             int node = it.second;
//             int curt = it.first;
//             pq.pop();
//             for(auto it : adj[node]){
//                 int nxtnode = it.first;
//                 int nt = it.second;
//                 if(curt + nt < time[nxtnode]){
//                     time[nxtnode] = curt + nt;
//                     pq.push({curt+nt,nxtnode});
//                 }
//             }
//         }
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             if (time[i] == 1e9) return -1;
//             ans = max(ans, time[i]);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int,int>>> adj(n + 1);
        
//         for (auto &it : times) {
//             adj[it[0]].push_back({it[1], it[2]});
//         }

//         vector<int> dist(n + 1, 1e9);
//         dist[k] = 0;

//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         pq.push({0, k});

//         while (!pq.empty()) {
//             auto [curt, node] = pq.top();
//             pq.pop();

//             if (curt > dist[node]) continue;

//             for (auto &[next, wt] : adj[node]) {
//                 if (curt + wt < dist[next]) {
//                     dist[next] = curt + wt;
//                     pq.push({dist[next], next});
//                 }
//             }
//         }

//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             if (dist[i] == 1e9) return -1;
//             ans = max(ans, dist[i]);
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto edge: times){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d > dist[node]){
                continue;
            }
            for(auto nei: adj[node]){
                int neighbor = nei.first;
                int wt = nei.second;
                if(dist[node] + wt < dist[neighbor]){
                    dist[neighbor] = dist[node] + wt;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        int ans = 0; 
        for(int i = 1; i <= n; i++){ 
            if(dist[i] == 1e9) return -1; 
            ans = max(ans, dist[i]); 
        } 
        return ans;
    }
};