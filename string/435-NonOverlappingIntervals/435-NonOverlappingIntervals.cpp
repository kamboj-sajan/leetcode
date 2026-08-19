// Last updated: 19/08/2026, 16:01:38
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
       if(n == 0)return 0;
       sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
        return a[1] < b[1];
       });
       int cnt = 1;
       int let = intervals[0][1];
       for(int i=1; i<n; i++){
        if(intervals[i][0] >= let){
            cnt++;
            let = intervals[i][1];
        }
       }
       return n-cnt;
    }
};