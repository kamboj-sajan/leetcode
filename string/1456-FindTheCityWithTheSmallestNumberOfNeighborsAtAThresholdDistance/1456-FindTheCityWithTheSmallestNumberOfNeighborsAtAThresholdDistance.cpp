// Last updated: 19/08/2026, 15:49:19
// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> dist(n,vector<int> (n,1e8));
//         for(auto it : edges){
//             int a = it[0];
//             int b = it[1];
//             int c = it[2];
//             dist[a][b] = c;
//             dist[b][a] = c;
//         }
//         for(int i=0; i<n; i++){
//             dist[i][i] = 0;
//         }
//         for(int via = 0; via < n; via++){
//             for(int i=0; i<n; i++){
//                 for(int j=0; j<n; j++){
//                     if(dist[i][via] != 1e8 && dist[via][i] != 1e8){
//                         dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
//                     }
//                 }
//             }
//         }
//         int cnt = INT_MAX;
//         int el = -1;
//         for(int i=0; i<n; i++){
//             int d = 0;
//             for(int j=0; j<n; j++){
//                 if(dist[i][j] <= distanceThreshold && i!=j){
//                     d++;
//                 }
//             }
//             if(d <= cnt){
//                 el = i;
//                 cnt = d;
//             }
//         }
//         return el;
//     }
// };

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int t) {
        vector<vector<int>> d(n, vector<int>(n, 1e9)); // Use a safe infinity to avoid overflow additions

        for (const auto& edge : e) {
            d[edge[0]][edge[1]] = edge[2];
            d[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0; i < n; i++) d[i][i] = 0;

        // Floyd-Warshall Core
        for (int i = 0; i < n; i++) {   
            for (int j = 0; j < n; j++) {   
                if (d[j][i] > t) continue; 
                for (int k = 0; k < n; k++) {   
                    if (d[i][k] > t) continue;
                    if (d[j][i] + d[i][k] < d[j][k]) {
                        d[j][k] = d[j][i] + d[i][k];
                    }
                }
            }
        }

        int minm = INT_MAX;
        int city = -1;

        // Evaluate counts
        for (int i = 0; i < n; i++) {   
            int l = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && d[i][j] <= t) l++;
            }
            if (l <= minm) {
                minm = l;
                city = i;
            }
        }
        return city;
    }
};