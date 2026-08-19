// Last updated: 19/08/2026, 15:35:53
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                st.insert(grid[i][j]); // k = 0 case
                
                for(int k = 1; ; k++){
                    if(i-k < 0 || i+k >= m || j-k < 0 || j+k >= n) break;
                    
                    int sum = 0;
                    
                    int x = i-k, y = j;
                    for(int t = 0; t < k; t++) sum += grid[x+t][y+t];
                    
                    x = i; y = j+k;
                    for(int t = 0; t < k; t++) sum += grid[x+t][y-t];
                    
                    x = i+k; y = j;
                    for(int t = 0; t < k; t++) sum += grid[x-t][y-t];
                    
                    x = i; y = j-k;
                    for(int t = 0; t < k; t++) sum += grid[x-t][y+t];
                    
                    st.insert(sum);
                }
            }
        }

        vector<int> ans(st.begin(), st.end());
        sort(ans.rbegin(), ans.rend());
        if(ans.size() > 3) ans.resize(3);
        return ans;
    }
};