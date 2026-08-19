// Last updated: 19/08/2026, 16:10:14
class Solution {
public:
    bool f(int i,int j,int ind,vector<vector<char>> &board,string &word){
        int n = board.size();
        int m = board[0].size();
        if(ind == word.size())return true;
        if(i < 0 || j<0 || i>=n|| j>=m || board[i][j] != word[ind])return false;

        char ch = board[i][j];
        board[i][j] = '#';//for visited
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int d=0; d<4; d++){
            int newi = i + dx[d];
            int newj = j + dy[d];
            if(f(newi,newj,ind+1,board,word))return true;
        }
        board[i][j] = ch;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                   if(f(i,j,0,board,word))return true;
                }
            }
        }
        return false;
    }
};