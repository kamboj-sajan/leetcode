// Last updated: 24/09/2026, 00:48:19
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
               if(max(intervals[i][0],intervals[j][0]) <= min(intervals[i][1],intervals[j][1]))cnt++;
            }
        }
        return cnt;
    }
};