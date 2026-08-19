// Last updated: 19/08/2026, 15:57:56
// class Solution {
// private:
//     void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newcolor,int delrow[],int delcol[], int inicolor){
//         ans[row][col] = newcolor;
//         int n = image.size();
//         int m = image[0].size();
//         for(int i=0; i<4; i++){
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor){
//                 dfs(nrow,ncol,ans,image,newcolor,delrow,delcol,inicolor);
//             }
//         }
//     }
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int inicolor = image[sr][sc];
//         vector<vector<int>> ans = image;
//         int delrow[] = {-1,0,1,0};
//         int delcol[] = {0,1,0,-1};
//         dfs(sr,sc,ans,image,color,delrow,delcol,inicolor);
//         return ans;
//     }
// };

// class Solution {
// public:
//     void dfs(vector<vector<int>>&image,int sr,int sc,int color,int original)
//     {
//         int m=image.size(),n=image[0].size();
//         if(sr<0 || sr>=m || sc<0 || sc>=n) return;
//         if(image[sr][sc] != original) return;

//         image[sr][sc]=color;
//         dfs(image,sr-1,sc,color,original);
//         dfs(image,sr+1,sc,color,original);
//         dfs(image,sr,sc+1,color,original);
//         dfs(image,sr,sc-1,color,original);
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int original=image[sr][sc];
//         if(original == color) return image;

//         dfs(image,sr,sc,color,original);
//         return image;
//     }
// };



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];

        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;

        int drow[4] = {0,0,-1,1};
        int dcol[4] = {-1,1,0,0};

        while(!q.empty()){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0&&nrow<m && ncol>=0&& ncol < n && image[nrow][ncol] == start && image[nrow][ncol] != color){
                    q.push({nrow,ncol});
                    image[nrow][ncol] = color;
                }
            }
        } 
        return image;
        
    }
};