// Last updated: 19/08/2026, 15:34:04
// class Solution {
// public:
//     int minOperations(vector<vector<int>>& grid, int x) {
//         using ll = long long;
//         int n = grid.size();
//         int m = grid[0].size();
//         // ll sum = 0;
//         // for(int i=0; i<n; ++i){
//         //     for(int j=0; j<m; ++j){
//         //         sum += grid[i][j];
//         //     }
//         // }
//         // ll md = sum/(n*m);
//         // if(sum % (n*m) != 0)md++;
//         // int res = 0;
//         // for(int i=0; i<n; ++i){
//         //     for(int j=0; j<m; ++j){
//         //         if(abs(grid[i][j]-md) % x != 0)return -1;
//         //         res += (abs(grid[i][j] - md))/x;
//         //     }
//         // }
//         // return res;
        // vector<int> vec(n*m);
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<m; ++j){
        //         vec[i*m + j] = grid[i][j];
        //     }
        // }
        // sort(vec.begin(),vec.end());
//         // int md;
//         // if(n*m % 2 == 0){
//         //     md = vec[n*m/2] + 1;
//         // }
//         // else{
//         //     md = (vec[n*m/2] + vec[n*m/2 - 1])/2;
//         // }
//         // int res = 0;
//         // for(int i=0; i<n*m; ++i){
//         //     res += abs(vec[i] - md)/x;
//         //     if(abs(vec[i]-md) %2 == 1 && x % 2 == 0)return -1;
//         // }
//         // return res;
//     }
// };

// class Solution {
// public:
//     int minOperations(vector<vector<int>>& grid, int x) {
//         using ll = long long;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<int> vec(n*m);
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 vec[i*m + j] = grid[i][j];
//             }
//         }
//         int res = INT_MAX;
//         sort(vec.begin(),vec.end());
//         for(int i=0; i<n*m; ++i){
//             int temp = 0;
//             for(int j=0; j<m*n; ++j){
//                 if(vec[i]%x != vec[j]%x)return -1;
//                 temp += abs(vec[i]-vec[j])/x;
//             }
//             res = min(res,temp);
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int minOperations(vector<vector<int>>& grid, int x) {
//         using ll = long long;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<int> vec(n*m);
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 vec[i*m + j] = grid[i][j];
//             }
//         }
//         int base = vec[0];
//         for(int i : vec){
//             if((i - base)%x != 0)return -1;
//         }
//         sort(vec.begin(),vec.end());
//         int md = vec[vec.size()/2];
//         int res = 0;
//         for(int i : vec){
//             res += abs(i - md)/x;
//         }
//         return res;
//     }
// };


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        int N = n * m;
        vector<int> data(10001, 0);
        int num0 = grid[0][0];
        int minValue(num0), maxValue(num0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((grid[i][j] - num0)%x != 0) {
                    return -1;
                }
                data[grid[i][j]]++;
                minValue = min(minValue, grid[i][j]);
                maxValue = max(maxValue, grid[i][j]);
            }
        }
        int count(0);
        for (int i = minValue + x; i <= maxValue; i += x) {
            count += (i - minValue)/x * data[i];
            data[i] = data[i] + data[i - x];
        }
        for (int i = minValue + x; i <= maxValue; i += x) {
            count = min(count, count + data[i - x] - (data[maxValue] - data[i - x]));
        }
        return count;
    }
};