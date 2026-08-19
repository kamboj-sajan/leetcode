// Last updated: 19/08/2026, 15:56:56
class Solution {
public:
    bool dfs(int node,int clr,vector<int> &col,vector<vector<int>> &adj){
        col[node] = clr;
        for(auto it: adj[node]){
            if(col[it] == -1){
                if(dfs(it,!clr,col,adj) == false)return false;
            }else if(col[it] == clr){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        for(int i=0; i<n; ++i){
            if(col[i] == -1){
                if(dfs(i,0,col,graph) == false)return false;
            }
        }
        return true;
    }
};