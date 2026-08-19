// Last updated: 19/08/2026, 16:11:38
// optimal solution
// class Solution {
// public:
//     void solve(int col,vector<string> &board, vector<vector<string>> &ans,vector<int> &leftrow,vector<int> &upperdiagonal,vector<int> &lowerdiagonal,int &n){
//         if(col == n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row=0; row<n; row++){
//             if(leftrow[row] == 0 && upperdiagonal[n-1 + col-row] == 0 && lowerdiagonal[row + col] == 0){
//                 board[row][col] = 'Q';
//                 leftrow[row] = 1;
//                 lowerdiagonal[row + col] = 1; 
//                 upperdiagonal[n-1 + col-row] = 1;
//                 solve(col+1,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
//                 board[row][col] = '.';
//                 leftrow[row] = 0;
//                 lowerdiagonal[row + col] = 0; 
//                 upperdiagonal[n-1 + col-row] = 0;
//             }
//         }
//     }
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n);
//         vector<vector<string>> ans;
//         string s(n,'.');
//         for(int i=0; i<n; i++){
//             board[i] = s;
//         }
//         vector<int> leftrow(n,0),upperdiagonal(2*n - 1, 0),lowerdiagonal(2*n - 1,0);
//         solve(0,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
//         return ans;
//     }
// };

class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        // check upper diagonal
        int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q')return false;
            row--;
            col--;
        }
        col = dupcol;
        row = duprow;
        while(col >= 0){
            if(board[row][col] == 'Q')return false;
            col--;
        }
        col = dupcol;
        row = duprow;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q')return false;
            row++;
            col--;
        }
        return true;
    }
public:
    void solve(int col,vector<string> &board, vector<vector<string>> &ans,int &n){
       if(col == n){
        ans.push_back(board);
        return;
       }
       for(int row =0; row<n; row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            solve(col+1,board,ans,n);
            board[row][col] = '.';
        }
       }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};