// Last updated: 19/08/2026, 15:38:14
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> diff(n,vector<int> (m,1e9));
        diff[0][0] = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if(d > diff[r][c])continue;
            if(r == n-1 && c == m-1)return d;
            for(int k=0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >=0 && nc >= 0 && nr < n && nc < m){
                    int dfn = abs(heights[nr][nc] - heights[r][c]);
                    int ndf = max(d,dfn);
                    if(ndf < diff[nr][nc]){
                        diff[nr][nc] = ndf;
                        pq.push({ndf,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};