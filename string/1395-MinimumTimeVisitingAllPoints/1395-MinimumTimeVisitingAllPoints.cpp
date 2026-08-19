// Last updated: 19/08/2026, 15:50:07
// class Solution {
// public:
//     int minTimeToVisitAllPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         int ans = 0;
//         for(int i=1; i<n; ++i){
//             ans += max(abs(points[i][0] - points[i-1][0]),abs(points[i][1]-points[i-1][1]));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0 ;

        int x1 = points[0][0] , y1 = points[0][1];

        for(int i = 0 ; i < points.size() ; i++){
            int x2 = points[i][0] , y2 = points[i][1];

            sum += max(abs(y2 - y1) , abs(x2 - x1));

            x1 = x2;
            y1 = y2;
        }

        return sum;
    }
};