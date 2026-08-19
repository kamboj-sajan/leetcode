// Last updated: 19/08/2026, 15:15:09
class Solution {
public:
    unordered_map<int,int> mpp;
    int ht(vector<vector<int>> &adj){
        queue<int> q;
        q.push(0);
        int h = 0;
        mpp[0] = 1;
        while(!q.empty()){
            int sz = q.size();
            h++;
            while(sz--){
            int top = q.front();
            q.pop();
            for(auto a : adj[top]){
                q.push(a);
                mpp[a] = mpp[top] + 1;
            }
        }
        }    
        return h;
    }
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> tr(n); 
        for(int i=0; i<n; i++){
            if(parent[i] != -1){
                tr[parent[i]].push_back(i);
            }
        }
        int h = ht(tr);
        long long wt = 0;
        for(int i=0; i<n; i++){
            wt += 1LL * nums[i] * (h - mpp[i] + 1);
        }
        return wt;
    }
};