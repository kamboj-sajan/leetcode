// Last updated: 11/10/2026, 08:09:56
// class DisjointSet{
//     vector<int> rank,parent,size;
// public:
//     DisjointSet(int n){
//         rank.resize(n+1,0);
//         parent.resize(n+1);
//         size.resize(n+1);
//         for(int i=0; i<n; i++){
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }
//     int findUpar(int node){
//         if(node == parent[node])return node;
//         else return parent[node] = findUpar(parent[node]);
//     }
//     void unionByrank(int a,int b){
//         int upara = findUpar(a);
//         int uparb = findUpar(b);
//         if(upara == uparb)return;
//         if(rank[upara] < rank[uparb]){
//             parent[upara] = uparb;
//         }else if(rank[uparb] < rank[upara]){
//             parent[uparb] = upara;
//         }else{
//             parent[uparb] = upara;
//             rank[upara]++;
//         }
//     }
//     void unionBysize(int a,int b){
//         int upara = findUpar(a);
//         int uparb = findUpar(b);
//         if(upara == uparb)return;
//         if(size[upara] < size[uparb]){
//             parent[upara] = uparb;
//             size[uparb] += size[upara];
//         }else{
//             parent[uparb] = upara;
//             size[upara] += size[uparb];
//         }
//     }
// };
// class Solution {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         DisjointSet ds(n);
//         vector<int> ans;
//         for(int i=0; i<n; i++){
//             int a = edges[i][0];
//             int b = edges[i][1];
//             if(ds.findUpar(a) != ds.findUpar(b)){
//                 ds.unionByrank(a,b);
//             }else{
//                 if(ans.size() != 0)ans.clear();
//                 ans = {edges[i][0],edges[i][1]};
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int find(int x, vector<int>& p)
    {
        if(p[x]!=x) p[x] = find(p[x], p);

        return p[x]; 
    }
    bool unify(int x, int y, vector<int> & p)
    {
        int px = find(p[x], p);
        int py = find(p[y], p);

        if(px == py) return false;
        p[py] = px;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> x;
        vector<int> p(edges.size()+1);
        iota(p.begin(), p.end(), 0);
        for(auto edge: edges){
            if(!unify(edge[0], edge[1], p)) x = edge;
        }

        return x;

    }
};