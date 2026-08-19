// Last updated: 19/08/2026, 16:08:24
// class Solution {
// public:
//     vector<int> generaterow(int row){
//         long long ans = 1;
//         vector<int> ansrow;
//         ansrow.push_back(1);
//         for(int col=1; col<row; col++){
//             ans = ans * (row - col);
//             ans = ans / (col);
//             ansrow.push_back(ans);
//         }
//         return ansrow;
//     }
//     vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> ans;
//        for(int i = 1; i<=numRows; i++){
//         ans.push_back(generaterow(i));
//        } 
//        return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i=0;i<numRows;i++){
            ans[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans;
    }
};