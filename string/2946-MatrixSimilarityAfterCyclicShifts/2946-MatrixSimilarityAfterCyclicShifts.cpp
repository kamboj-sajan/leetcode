// Last updated: 25/09/2026, 01:02:31
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
         int m = mat.size();
        int n = mat[0].size();
        
        int shift = k % n; // effective shift
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // left shift
                    if (mat[i][j] != mat[i][(j + shift) % n])
                        return false;
                } else {
                    // right shift
                    if (mat[i][j] != mat[i][(j - shift + n) % n])
                        return false;
                }
            }
        }
        return true;
    }
};