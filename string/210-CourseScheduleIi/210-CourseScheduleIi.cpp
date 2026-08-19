// Last updated: 19/08/2026, 16:04:58
// // class Solution {
// // public:
// //     vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
// //         int n = pr.size();
// //         int v = numCourses;
// //         vector<int> ans;
// //         vector<vector<int>> adj(v);
// //         vector<int> idg(v,0);
// //         for(int i=0; i<n; ++i){
// //             int a = pr[i][0];
// //             int b = pr[i][1];
// //             adj[b].push_back(a);
// //             idg[a]++;
// //         }
// //         queue<int> q;
// //         for(int i=0; i<v; i++){
// //             if(idg[i] == 0 )q.push(i);
// //         }
// //         while(!q.empty()){
// //             int node = q.front();
// //             q.pop();
// //             ans.push_back(node);
// //             for(auto &it : adj[node]){
// //                 idg[it]--;
// //                 if(idg[it] == 0)q.push(it);
// //             }
// //         }
// //         if(ans.size() != numCourses) return {};
// //         return ans;
// //     }
// // };


// // class Solution {
// // public:
// //     vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
// //           vector<vector<int>> adj(V);  

// //         //  adj list
// //         for (auto it : prerequisites) {
// //             int a = it[0];
// //             int b = it[1];
// //             adj[b].push_back(a);
// //         }
// //         vector<int> indegree(V, 0);;
// //         for(int i=0; i<V; i++){
// //             for(auto it : adj[i]){
// //                 indegree[it]++;
// //             }
// //         }
// //         queue<int> q;
// //         for(int i=0; i<V; i++){
// //             if(indegree[i] == 0)q.push(i);
// //         }
// //       vector<int> toposort;
// //         while(!q.empty()){
// //             int node = q.front();
// //             q.pop();
// //            toposort.push_back(node);
// //             // node is in topo sort order so erase all edges 
// //             // which means remove indegree for its adj elements
// //             for(auto it : adj[node]){
// //                 indegree[it]--;
// //                 if(indegree[it] == 0)q.push(it);
// //             }
// //         }
// //         if(toposort.size() == V) return toposort;
// //         return {};
// //     }
// // };

// class Solution {
// public:
//     bool dfs(vector<vector<int>> &graph,vector<int> &NodeVis,int node,vector<int> &ans)
//     {
//         if(NodeVis[node]==1)
//         {
//           return false;  
//         }
        
//         if(NodeVis[node] == 2)
//             return true;
        
//         NodeVis[node] = 1;
        
        
//         for(int neigh:graph[node])
//         {
//             if(!dfs(graph,NodeVis,neigh,ans))
//                 return false;            
//         }
        
//         NodeVis[node] = 2;
//         ans.push_back(node);
//         return true;
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//          vector<vector<int>> graph(numCourses);
//         vector<int> ans;
        
//         for(auto &p:prerequisites)
//         {
//             graph[p[1]].push_back(p[0]);
//         }
        
//         vector<int> NodeVis(numCourses,0);
        
//         for(int i=0;i<numCourses;i++)
//         {
//             if(NodeVis[i]==0)
//             {
//                 if(!dfs(graph,NodeVis,i,ans))
//                 {
//                     return {};
//                 }
//             }
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//     }
// };

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis,
             vector<int> &pathVis, vector<int> &ans) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, ans))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        ans.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};