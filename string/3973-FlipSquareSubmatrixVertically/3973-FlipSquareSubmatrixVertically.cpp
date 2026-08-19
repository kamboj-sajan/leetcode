// Last updated: 19/08/2026, 15:22:45
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        if(n == 0)return grid;
        if(x<0 || y<0 || k<=0 || x+k>n|| y+k>m)return grid;
        for(int i=x; i<n && cnt <k/2 ; i++){
            int cnt2 = 0;
            for(int j=y; j<m&& cnt2<k; j++){ 
                swap(grid[i][j],grid[x+k-1-cnt][j]);
                cnt2++;
            }
            cnt++;
        }
        return grid;
    }
};