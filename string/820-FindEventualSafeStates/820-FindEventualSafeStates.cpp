// Last updated: 19/08/2026, 15:56:29
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> idg(n,0);
        for(int i=0; i<n; ++i){
            for(int j = 0; j<graph[i].size(); j++){
                int a = graph[i][j];
                adj[a].push_back(i);
                idg[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; ++i){
            if(idg[i] == 0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int b = q.front();
            q.pop();
            ans.push_back(b);
            for(auto it : adj[b]){
                idg[it]--;
                if(idg[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};