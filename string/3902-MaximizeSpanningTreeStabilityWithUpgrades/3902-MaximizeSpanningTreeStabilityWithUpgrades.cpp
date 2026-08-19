// Last updated: 19/08/2026, 15:23:45
class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n){
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;

        if(rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;
        if(rankv[a]==rankv[b]) rankv[a]++;

        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, long long x){

        DSU dsu(n);
        int used=0;
        int upgrades=0;

        vector<vector<int>> normal, upgrade;

        for(auto &e: edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must){
                if(s<x) return false;

                if(!dsu.unite(u,v)) return false;

                used++;
            }
            else{
                if(s>=x) normal.push_back(e);
                else if(2LL*s>=x) upgrade.push_back(e);
            }
        }

        for(auto &e: normal){
            if(dsu.unite(e[0],e[1])){
                used++;
            }
        }

        for(auto &e: upgrade){
            if(used==n-1) break;

            if(dsu.unite(e[0],e[1])){
                upgrades++;
                used++;
                if(upgrades>k) return false;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        long long l=0,r=2e9;
        int ans=-1;

        while(l<=r){
            long long mid=(l+r)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
};