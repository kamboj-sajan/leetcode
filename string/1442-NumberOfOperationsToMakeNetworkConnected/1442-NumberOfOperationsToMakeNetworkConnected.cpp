// Last updated: 19/08/2026, 15:49:37
// class Solution {
// public:
//     vector<int> sz;
//     void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
//         vis[node] = 1;
//         for(auto it : adj[node]){
//             if(!vis[it]) dfs(it,adj,vis);
//         }
//         return;
//     }
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         int m = connections.size();
//         vector<vector<int>> adj(n);
//         for(auto it : connections){
//             int a = it[0];
//             int b = it[1];
//             adj[a].push_back(b);
//             adj[b].push_back(a);
//         }
//         vector<int> vis(n,0);
//         int cnt = 0;
//         for(int i = 0; i<n; i++){
//             if(!vis[i]){
//                 cnt++;
//                 dfs(i,adj,vis);
//             }
//         }
//         if(m >= n-1){
//             return cnt-1;
//         }else return -1;
//     }
// };

// class Solution {
// public:
//     void bfsHelper(int pt, vector<bool>& vis, vector<vector<int>>& adj) {
//         queue<int> q;
//         q.push(pt);
//         vis[pt] = true;

//         while(!q.empty()){
//             int u = q.front();
//             q.pop();

//             for(int v : adj[u]){
//                 if(!vis[v]){
//                     vis[v] = true;
//                     q.push(v);
//                 }
//             }
//         }
//     }

//     int makeConnected(int n, vector<vector<int>>& connections) {
//         // Step 1: if there aren’t enough cables, impossible
//         if (connections.size() < n - 1) return -1;

//         // Step 2: build adjacency list (undirected)
//         vector<vector<int>> adj(n);
//         for (auto& e : connections) {
//             int u = e[0], v = e[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         // Step 3: count connected components
//         vector<bool> vis(n, false);
//         int components = 0;

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 components++;
//                 bfsHelper(i, vis, adj);
//             }
//         }

//         // Step 4: minimum operations needed = components - 1
//         return components - 1;
//     }
// };

class DisjointSet {
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisjointSet(int n){
        this->n = n;

        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    // T.C -> O(alpha(n))
    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);    // Path Compression Optimization
    }

    // T.C -> O(alpha(n))
    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
        }
        else{
            parent[parA] = parB;
        }
    }

    // T.C -> O(alpha(n))
    void unionBySize(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(size[parA] >= size[parB]){
            size[parA] += size[parB];
            parent[parB] = parA;
        }
        else{
            size[parB] += size[parA];
            parent[parA] = parB;
        }
    }

    // void getInfo(){
    //     for(int i=0;i<n;i++){
    //         cout << i << ": " << parent[i] << " , " << rank[i] << endl;
    //     }

    //     for(int i=0;i<n;i++){
    //         cout << i << ": " << parent[i] << " , " << size[i] << endl;
    //     }
    // }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        DisjointSet djs(n);

        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];
            djs.unionBySize(u, v);
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(djs.parent[i] == i){
                count++;
            }
        }

        return count-1;
    }
};