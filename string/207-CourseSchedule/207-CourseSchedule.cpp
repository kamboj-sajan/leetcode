// Last updated: 19/08/2026, 16:05:04
// class Solution {
// public:
//     bool canFinish(int V, vector<vector<int>>& prerequisites) {
//           vector<vector<int>> adj(V);  

//         //  adj list
//         for (auto it : prerequisites) {
//             int a = it[0];
//             int b = it[1];
//             adj[b].push_back(a);
//         }
//         vector<int> indegree(V, 0);;
//         for(int i=0; i<V; i++){
//             for(auto it : adj[i]){
//                 indegree[it]++;
//             }
//         }
//         queue<int> q;
//         for(int i=0; i<V; i++){
//             if(indegree[i] == 0)q.push(i);
//         }
//        int cnt = 0;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             cnt ++;
//             // node is in topo sort order so erase all edges 
//             // which means remove indegree for its adj elements
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it] == 0)q.push(it);
//             }
//         }
//         if(cnt == V) return true;
//         return false;
//     }
// };

// class Solution {
// private:
//     bool dfs(int node, const vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path) {
//         vis[node] = path[node] = true;

//         for (int next : adj[node]) {
//             if (!vis[next]) {
//                 if (dfs(next, adj, vis, path)) return true;
//             } else if (path[next]) {
//                 return true;
//             }
//         }
        
//         path[node] = false;
//         return false;
//     }

// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         for (const auto& pre : prerequisites) {
//             adj[pre[1]].push_back(pre[0]);
//         }

//         vector<bool> vis(numCourses, false);
//         vector<bool> path(numCourses, false);

//         for (int i = 0; i < numCourses; ++i) {
//             if (!vis[i]) {
//                 if (dfs(i, adj, vis, path)) return false;
//             }
//         }

//         return true;
//     }
// };


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;

        std::vector<std::vector<int>> adj(numCourses);
        for(auto& pair: prerequisites) {
            adj[pair[1]].push_back(pair[0]);
        }

        std::vector<bool> visited(numCourses, false);
        std::vector<bool> path(numCourses, false);

        for(int i=0; i <numCourses; i++) {
            if(visited[i]) continue;

            if(bfs(i, adj, visited, path)) return false;
        }
        
        return true;
    }

    bool bfs(int i, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& path) {
        visited[i] = path[i] = true;

        for(int n: adj[i]) {
            if(!visited[n]) {
                if(bfs(n, adj, visited, path)) 
                    return true;
            } else if(path[n]) {
                return true;
            }
        }
        path[i] = false;
        return false;
    }
};
