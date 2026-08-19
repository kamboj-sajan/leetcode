// Last updated: 19/08/2026, 15:58:00
class DisjointSet{
public:
    vector<int> size,parent;
    DisjointSet(int n){
      size.resize(n+1,1);
      parent.resize(n+1);
      for(int i=0; i<=n; ++i){
        parent[i] = i;
      }  
    }

    int findUPar(int node){
        if(node == parent[node])return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u,int v){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        map<string,int> mpp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }else{
                    ds.UnionBySize(i,mpp[mail]);
                }
            }
        }
        vector<vector<string>> mergedmail(n);
        for(auto it : mpp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedmail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedmail[i].empty())continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto mail : mergedmail[i])temp.push_back(mail);
            ans.push_back(temp);
        }
        return ans;
    }
};