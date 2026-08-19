// Last updated: 19/08/2026, 15:19:44
class DSU {
public:
    vector<int> parent, size, pt;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        pt.resize(n,0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
        int px = parent[x];
        parent[x] = find(parent[x]);
        pt[x] ^= pt[px];
        return parent[x];
    }
    bool unite(int u, int v,int w) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv){
            return ((pt[u]^pt[v]^w) == 0); 
        }
        if(size[pu] < size[pv]){
            swap(pu,pv);
            swap(u,v);
        }
        parent[pv] = pu;
        size[pu] += pv;
        pt[pv] = pt[u]^pt[v]^w;
        return true;
    }
};
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int size = 0;
        unordered_set<int> st;
        int cnt = 0;
        for(int i=0; i<edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(dsu.unite(u,v,w))cnt++;
        }
        return cnt;
    }
};