// Last updated: 19/08/2026, 16:00:06
/*
class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjls, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, adjls, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjls(v);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                }
            }
        }

        vector<int> vis(v, 0);
        int cnt = 0;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjls, vis); 
            }
        }

        return cnt;
    }
};
*/
/* 
with adjacency matrix 
void solve(int node, vector<vector<int>>& adj, vector<bool>& visited)
    {
        visited[node] = true;
        for (size_t it{0}; it < adj[node].size(); ++it)
        {
            if (!visited[it] && adj[node][it])
            {
                solve(it, adj, visited);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        vector<bool> visited(V, false);
        int numProvince{0};
        for(int node{0}; node < V; ++node)
        {
            if(!visited[node])
            {
                ++numProvince;
                solve(node, adj, visited);
            }
        }
        return numProvince;
    } 
    */

    // above code in simple lang;
    class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int V) {
        visited[node] = true;

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                dfs(i, adj, visited, V);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited, V);
            }
        }

        return count;
    }
};
/*

    // disjoint set
    class DisjointSet{
public:
vector<int> rank,parent,size;
       DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
       }
       int findUPar(int node){
        if(node == parent[node])return node;
        return parent[node] = findUPar(parent[node]);
       }

       void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
       }

        void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        }
};
    class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjointSet ds(V);
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(isConnected[i][j] == 1){
                ds.unionBySize(i,j);
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<V; i++){
        if(ds.parent[i] == i)cnt++;
    }
    return cnt;
    }
};
*/