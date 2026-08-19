// Last updated: 19/08/2026, 15:35:48
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        // Step 1: Transpose
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        // Step 2: Reverse each row
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int k = 0; k < 4; k++){
            if(mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};