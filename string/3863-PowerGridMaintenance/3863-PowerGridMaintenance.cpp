// Last updated: 19/08/2026, 15:24:34
// class Solution {
// public:
//     vector<int> parent , size;
//     unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mpp;
    
//     int findParent(int node){
//         if(parent[node] == node)return node;
//         return parent[node] = findParent(parent[node]);
//     }

//     void Union(int u,int v){
//         int up = findParent(u);
//         int vp = findParent(v);
//         if(up == vp)return;
//         if(size[up] > size[vp]){
//             size[up] += size[vp];
//             parent[vp] = up;
//             while(!mpp[vp].empty()){
//                 mpp[up].push(mpp[vp].top());
//                 mpp[vp].pop();
//             }
//         }else{
//             size[vp] += size[up];
//             parent[up] = vp;
//             while(!mpp[up].empty()){
//                 mpp[vp].push(mpp[up].top());
//                 mpp[up].pop();
//             }
//         }
//     }

//     vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
//        vector<int> ans;
//        parent.resize(c);
//        size.resize(c,1);
//        vector<int> offline(c,0);
//        for(int i=0; i<c; ++i){
//         parent[i] = i;
//         mpp[i].push(i);
//        }

//        for(auto &it : connections){
//         int u = it[0] - 1;
//         int v = it[1] - 1;
//         Union(u,v);
//        }

//        for(auto &it : queries){
//         int type = it[0];
//         int node = it[1] - 1;
//         if(type == 1){
//             if(offline[node] == 0){
//                 ans.push_back(node + 1);
//                 continue;
//             }
//             int par = findParent(node);
//             while(!mpp[par].empty() && offline[mpp[par].top()]){
//                 mpp[par].pop();
//             }

//             if(mpp[par].empty())ans.push_back(-1);
//             else ans.push_back(mpp[par].top() + 1);
//         }else{
//             offline[node] = 1;
//         }
//        }
//        return ans;
//     }
// };


class Solution {
public:
    void dfs(int id, int node, vector<vector<int>>& adj, vector<int>& vis, map<int, set<int>>& smp, map<int, int>& mpp){
        vis[node] = 1;
        smp[id].insert(node);
        mpp[node] = id;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(id, it, adj, vis, smp, mpp);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c);
        for(auto it: connections){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }

        vector<int> vis(c), online(c, 1);
        int id = 0;
        map<int, set<int>> smp;
        map<int, int> mpp;

        for(int i = 0; i < c; i++){
            if(!vis[i]){
                dfs(id, i, adj, vis, smp, mpp);
                id++;
            }
        }

        vector<int> ans;
        for(auto& q : queries){
            int type = q[0], node = q[1]-1;
            int compId = mpp[node];

            if(type == 2){
                smp[compId].erase(node);
                online[node] = 0;
                continue;
            }

            if(online[node]){
                ans.push_back(node + 1);
            } else if(smp[compId].size() > 0){
                ans.push_back(*smp[compId].begin() + 1);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};