// Last updated: 19/08/2026, 15:16:11
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0; i<matrix.size(); ++i){
            int temp =0;
            for(int j=0; j<matrix[0].size(); ++j){
                if(matrix[i][j] == 1)temp++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};